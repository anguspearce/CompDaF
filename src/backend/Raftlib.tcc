#ifndef RAFTLIB_TCC
#define RAFTLIB_TCC

using namespace std::chrono;

template <typename T>
Raftlib<T>::Raftlib(long *naxes)
{
    this->width = naxes[0];
    this->height = naxes[1];
    this->depth = naxes[2];
    //this->noOfPixels = totPixels;
    this->sumTotal = 0;
    this->max = -999999;
    this->min = 999999;
}
template <typename T>
void Raftlib<T>::statistics(std::vector<std::vector<T>> &vec)
{

    using type_v = std::vector<T>;
    using type_a = std::vector<std::pair<type_v, raft::signal>>;
    using splitvec = SplitVector<type_v>;
    using raftstats = RaftStatistics<type_a, T>;
    using sum = Sum<T>;
    // this->max = -999999;
    // this->min = 999999;

    splitvec sp(NUM_THREADS);
    raftstats av(max, min);
    sum s(NUM_THREADS);
    raft::map m;

    auto readeachone(raft::read_each<type_v>(vec.begin(), vec.end()));

    m += readeachone >> sp;
    m += sp <= av >= s;

    auto start = high_resolution_clock::now();

    m.exe();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    //std::cout << "Raft Statistics Time: " << duration.count() << std::endl;
    this->sumTotal += s.total;
    this->sumsquares += s.sumSquaresTotal;
}
template <typename T>
void Raftlib<T>::mean(long totPixels)
{
    this->imgMean = this->sumTotal / this->noOfPixels;
}
template <typename T>
void Raftlib<T>::calcStdv(long totPixels)
{
    this->stdvDev = sqrt((this->sumsquares / this->noOfPixels) - (this->imgMean * this->imgMean));
}
template <typename T>
void Raftlib<T>::histogram(std::vector<std::vector<T>> &vec)
{
    using type_v = std::vector<T>;
    using type_a = std::vector<std::pair<type_v, raft::signal>>;
    using splitvec = SplitVector<type_v>;
    using rafthisto = RaftHistogram<type_a, T>;
    using mergebins = MergeBins<T>;
    //calculateBins();
    // std::vector<int> lbins(this->noOfBins, 0);
    // this->bins = lbins;
    splitvec sp(NUM_THREADS);
    rafthisto sv(getMean(), this->min, this->binWidth, this->noOfBins);
    mergebins mb(bins, NUM_THREADS);
    raft::map m;

    auto readeachone(raft::read_each<type_v>(vec.begin(), vec.end()));
    m += readeachone >> sp;
    m += sp <= sv >= mb;
    auto start = high_resolution_clock::now();

    m.exe();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    //std::cout << "Raft Histogram Time: " << duration.count() << std::endl;
    //this->stdvDev = sqrt(s.total / (this->noOfPixels-1));
}

template <typename T>
void Raftlib<T>::TestStatsReadImage(fitsfile *fptr)
{
    using type_v = std::vector<T>;
    using type_a = std::vector<std::pair<type_v, raft::signal>>;

    using readimage = RaftReadImage<type_v>;
    using splitvec = SplitVector<type_v>;
    using raftstats = RaftStatistics<type_a, T>;
    using sum = Sum<T>;
    readimage ri(fptr);
    splitvec sp(NUM_THREADS);
    raftstats av(max, min);
    sum s(NUM_THREADS);
    raft::map m;
    m += ri >> sp;
    m += sp <= av >= s;

    auto start = high_resolution_clock::now();

    m.exe();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Raft Read Image Time: " << ri.readTime*1e-6<<"s" << std::endl;

    std::cout << "Raft Statistics Time: " << (duration.count()*1e-6)-(ri.readTime*1e-6)<<"s" << std::endl;
    this->sumTotal += s.total;
    this->sumsquares += s.sumSquaresTotal;
    this->noOfPixels=ri.totPixels;
}
template <typename T>
void Raftlib<T>::TestHistoReadImage(fitsfile *fptr)
{
    using type_v = std::vector<T>;
    using type_a = std::vector<std::pair<type_v, raft::signal>>;
    using readimage = RaftReadImage<type_v>;
    using splitvec = SplitVector<type_v>;
    using rafthisto = RaftHistogram<type_a, T>;
    using mergebins = MergeBins<T>;
    //calculateBins();
    // std::vector<int> lbins(this->noOfBins, 0);
    // this->bins = lbins;
    readimage ri(fptr);
    splitvec sp(NUM_THREADS);
    rafthisto sv(getMean(), this->min, this->binWidth, this->noOfBins);
    mergebins mb(bins, NUM_THREADS);
    raft::map m;

    //auto readeachone(raft::read_each<type_v>(vec.begin(), vec.end()));
    //m += readeachone >> sp;
    m += ri >> sp;
    m += sp <= sv >= mb;
    auto start = high_resolution_clock::now();

    m.exe();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Raft Read Image Time: " << ri.readTime*1e-6<<"s" << std::endl;
    std::cout << "Raft Histogram Time: " << (duration.count()*1e-6)-(ri.readTime*1e-6)<<"s" << std::endl;

}

template <typename T>
void Raftlib<T>::calculateBins()
{
    this->noOfBins = int(std::max(2.0, sqrt((this->width * this->height))));
    this->binWidth = (this->max - this->min) / this->noOfBins;
    this->firstBinCenter = this->min + (this->binWidth * 0.5);
    std::vector<int> lbins(this->noOfBins, 0);
    this->bins = lbins;
}
template <typename T>
void Raftlib<T>::getBins(int &nBins, double &bWidth, std::vector<int> &bins)
{
    nBins = this->noOfBins;
    bWidth = this->binWidth;
    bins = this->bins;
}
template <typename T>
T Raftlib<T>::getSum()
{
    return this->sumTotal;
}
template <typename T>
T Raftlib<T>::getMean()
{
    return this->imgMean;
}
template <typename T>
T Raftlib<T>::getStdv()
{
    return this->stdvDev;
}
template <typename T>
void Raftlib<T>::getMinAndMax(T &imgMin, T &imgMax)
{
    imgMin = this->min;
    imgMax = this->max;
}
template <typename T>
T Raftlib<T>::getBinCenter()
{
    return this->firstBinCenter;
}
template <typename T>
long Raftlib<T>::getNoOfPixels()
{
    return this->noOfPixels;
}

#endif
