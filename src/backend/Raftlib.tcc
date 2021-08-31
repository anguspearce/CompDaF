#ifndef RAFTLIB_TCC
#define RAFTLIB_TCC



using namespace std::chrono;

template <typename T>
Raftlib<T>::Raftlib(long *naxes,long totPixels)
{
    this->width = naxes[0];
    this->height = naxes[1];
    this->depth = naxes[2];
    this->noOfPixels = totPixels;
    this->sumTotal = 0;
}
template <typename T>
void Raftlib<T>::sum(std::vector<std::vector<T>> &vec)
{

    using type_v = std::vector<T>;
    using type_a = std::vector<std::pair<type_v, raft::signal>>;
    using splitvec = SplitVector<type_v>;
    using addvec = AddVector<type_a, T>;
    using sum = Sum<T>;
    this->max = -999999;
    this->min = 999999;

    splitvec sp(NUM_THREADS);
    addvec av(max, min);
    sum s(NUM_THREADS);
    raft::map m;

    auto readeachone(raft::read_each<type_v>(vec.begin(), vec.end()));

    m += readeachone >> sp;
    m += sp <= av >= s;

    auto start = high_resolution_clock::now();

    m.exe();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    //std::cout << "Raft Sum Time: " << duration.count() << std::endl;
    this->sumTotal = s.total;
}
template <typename T>
void Raftlib<T>::mean()
{
    this->imgMean = this->sumTotal / this->noOfPixels;
}
template <typename T>
void Raftlib<T>::stdDev(std::vector<std::vector<T>> &vec)
{
    using type_v = std::vector<T>;
    using type_a = std::vector<std::pair<type_v, raft::signal>>;
    using splitvec = SplitVector<type_v>;
    using stdvvec = StdvVector<type_a, T>;
    using sum = Sum<T>;
    calculateBins();
    std::vector<int> lbins(this->noOfBins, 0);
    this->bins = lbins;
    splitvec sp(NUM_THREADS);
    stdvvec sv(getMean(), bins, this->min, this->binWidth);
    sum s(NUM_THREADS);
    raft::map m;

    auto readeachone(raft::read_each<type_v>(vec.begin(), vec.end()));
    m += readeachone >> sp;
    m += sp <= sv >= s;
    auto start = high_resolution_clock::now();

    m.exe();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    //std::cout << "Raft Stdv Time: " << duration.count() << std::endl;
    this->stdvDev = sqrt(s.total / (this->noOfPixels-1));
}
template <typename T>
void Raftlib<T>::calculateBins()
{
    this->noOfBins = int(std::max(2.0, sqrt((this->width * this->height))));
    this->binWidth = (this->max - this->min) / this->noOfBins;
    this->firstBinCenter = this->min + (this->binWidth * 0.5);
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

#endif
