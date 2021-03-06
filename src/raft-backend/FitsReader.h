#ifndef FITSREADER_H
#define FITSREADER_H

#include "fitsio.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <carta-protobuf/defs.pb.h>
#include <carta-protobuf/open_file.pb.h>
#include <carta-protobuf/tiles.pb.h>
#include <carta-protobuf/enums.pb.h>
#include <carta-protobuf/region_histogram.pb.h>
#include <carta-protobuf/region_stats.pb.h>

#include "Raftlib.h"
#include <map>
class FitsReader
{
public:
    FitsReader(const std::string &filename,int numThreads);
    void FillFileInfo(std::vector<std::string> &hdu_list, std::string &fName, int64_t &fSize, int &naxis, long *naxes, std::vector<CARTA::HeaderEntry> &headerEntries, std::string &error);
    void readImagePixels();
    std::ifstream::pos_type filesize(const char *filename);
    CARTA::RegionHistogramData& getRegionHistoData();
    CARTA::RegionStatsData& getRegionStatsData();

private:
    std::string _filename;
    fitsfile *fptr;
    std::vector<std::vector<float>> imageData;
    CARTA::RegionHistogramData regionHistoData;
    CARTA::RegionStatsData regionStatsData;
    int numThreads;
};
#endif
