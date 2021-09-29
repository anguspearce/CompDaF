#ifndef RAFTLIB_TCC
#define RAFTLIB_TCC

using namespace std::chrono;

/*
    Constructor for Raftlib
    Assigns the width, height and depth
    from naxes.
    Default min and max operations
*/
template <typename T>
Raftlib<T>::Raftlib(long *naxes,int numThreads)
{
    this->width = naxes[0];
    this->height = naxes[1];
    this->depth = naxes[2];
    this->sumTotal = 0;
    this->sumsquares = 0;
    this->max = INT_MIN;
    this->min = INT_MAX;
    this->NUM_THREADS=numThreads;
}

/*
    CalculateStatistics is the method that makes
    use of raftlib library to calculate the statistics.
    The kernels will calculate min, max, sum, sum square
    and total number of non nan pixels.
*/
template <typename T>
void Raftlib<T>::CalculateStatistics(fitsfile *fptr)
{
    std::cout<<"Num of threads: "<<NUM_THREADS<<std::endl;
    //Setting the types that will be passed into the kernels
    using type_v = std::vector<T>;
    using type_a = std::vector<std::pair<type_v, raft::signal>>;

    // Kernel to read a fits file
    using readimage = RaftReadImage<type_v>;

    //Kernel to send a number of vector through to the next kernel
    using splitvec = SplitVector<type_v>;

    //Kernel that will be duplicated to calculate sum, sumsquare, min and max
    using raftstats = RaftStatistics<type_a, T>;

    //Final kernel which will be used to total all sums and sumsquares
    using sum = Sum<T>;

    //Initialising using the constructors
    //NUM_THREADS is the number of input and output ports
    //Duplicates the middle kernel as required
    readimage ri(fptr);
    splitvec sp(NUM_THREADS);
    raftstats av;
    sum s(NUM_THREADS);

    //Map object will be used to link compute kernels
    raft::map m;

    //kernel ri has a single output and sp has a single
    //input port
    m += ri >> sp;

    //sp could have multiple output ports depending on 
    //NUM_THREADS, av will be duplicated NUM_THREADS times
    //s will have NUM_THREADS input ports
    m += sp <= av >= s;

    auto start = high_resolution_clock::now();

    //Execution of graph only once connecting port rules
    //are satisfied
    m.exe();
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Raft Total Statistics Time: " << duration.count()*1e-6<<"s" << std::endl;
    std::cout << "Raft Read Image Time: " << ri.readTime*1e-6<<"s" << std::endl;
    std::cout << "Raft Statistics Time: " << (duration.count()*1e-6)-(ri.readTime*1e-6)<<"s" << std::endl;
    
    //Getting the sum, sum square and no of non nan pixels
    //from the kernels
    this->sumTotal += s.total;
    this->sumsquares += s.sumSquaresTotal;
    this->noOfPixels=ri.totPixels;
    this->min=s.min;
    this->max=s.max;
}

/*
    CalculateHistogram is the method that makes
    use of raftlib library to calculate the histogram.
    The kernels will calculate bins and merge them.
*/
template <typename T>
void Raftlib<T>::CalculateHistogram(fitsfile *fptr)
{

    //Setting the types that will be passed into the kernels
    using type_v = std::vector<T>;
    using type_a = std::vector<std::pair<type_v, raft::signal>>;
    
    // Kernel to read a fits file
    using readimage = RaftReadImage<type_v>;

    //Kernel to send a number of vector through to the next kernel
    using splitvec = SplitVector<type_v>;
    
    //Kernel that will be duplicated to calculate seperate bins    
    using rafthisto = RaftHistogram<type_a, T>;
    
    //Final kernel which will be used to join all bins    
    using mergebins = MergeBins<T>;

    //Initialising using the constructors
    //NUM_THREADS is the number of input and output ports
    //Duplicates the middle kernel as required
    readimage ri(fptr);
    splitvec sp(NUM_THREADS);
    rafthisto sv(getMean(), this->min, this->binWidth, this->noOfBins);
    mergebins mb(bins, NUM_THREADS);

    //Map object will be used to link compute kernels
    raft::map m;

    //kernel ri has a single output and sp has a single
    //input port
    m += ri >> sp;

    //sp could have multiple output ports depending on 
    //NUM_THREADS, sv will be duplicated NUM_THREADS times
    //mb will have NUM_THREADS input ports
    m += sp <= sv >= mb;

    auto start = high_resolution_clock::now();

    //Execution of graph only once connecting port rules
    //are satisfied
    m.exe();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Raft Total Histogram Time: " << duration.count()*1e-6<<"s" << std::endl;    
    std::cout << "Raft Read Image Time: " << ri.readTime*1e-6<<"s" << std::endl;
    std::cout << "Raft Histogram Time: " << (duration.count()*1e-6)-(ri.readTime*1e-6)<<"s" << std::endl;

}

/*
    Calculate mean using sum and non-nan 
    pixels from kernel
*/
template <typename T>
void Raftlib<T>::mean(long totPixels)
{
    this->imgMean = this->sumTotal / this->noOfPixels;
}

/*
    Calculate standard deviation using sum and 
    non-nan pixels from kernel and mean.
*/
template <typename T>
void Raftlib<T>::calcStdv(long totPixels)
{
    this->stdvDev = sqrt((this->sumsquares / this->noOfPixels) - (this->imgMean * this->imgMean));
}

/*
    Calculate no of bins using width and height,
    bin width using min and max from kernels and noOfBins,
    and the first bin center
*/
template <typename T>
void Raftlib<T>::calculateBins()
{
    this->noOfBins = int(std::max(2.0, sqrt((this->width * this->height))));
    this->binWidth = (this->max - this->min) / this->noOfBins;
    this->firstBinCenter = this->min + (this->binWidth * 0.5);

    //creating a vector of size noOfBins and initialising with 0s
    //Will be passed into final kernel to total everything.
    std::vector<int> lbins(this->noOfBins, 0);
    this->bins = lbins;
}

/*
    Returns the number of bins, bin width and bins 
*/
template <typename T>
void Raftlib<T>::getBins(int &nBins, double &bWidth, std::vector<int> &bins)
{
    nBins = this->noOfBins;
    bWidth = this->binWidth;
    bins = this->bins;
}

/*
    Returns the total sum 
*/
template <typename T>
T Raftlib<T>::getSum()
{
    return this->sumTotal;
}

/*
    Returns the mean
*/
template <typename T>
T Raftlib<T>::getMean()
{
    return this->imgMean;
}

/*
    Returns the standard deviation
*/
template <typename T>
T Raftlib<T>::getStdv()
{
    return this->stdvDev;
}

/*
    Returns the min and max values
*/
template <typename T>
void Raftlib<T>::getMinAndMax(T &imgMin, T &imgMax)
{
    imgMin = this->min;
    imgMax = this->max;
}

/*
    Returns the fist bin center
*/
template <typename T>
T Raftlib<T>::getBinCenter()
{
    return this->firstBinCenter;
}

/*
    Returns the number of pixels
*/
template <typename T>
long Raftlib<T>::getNoOfPixels()
{
    return this->noOfPixels;
}

#endif
