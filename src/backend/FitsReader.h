#ifndef FITSREADER_H
#define FITSREADER_H

#include "fitsio.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <carta-protobuf/defs.pb.h>
#include "Raftlib.h"

class FitsReader {
public:
    FitsReader(const std::string& filename);
    void FillFileInfo(std::vector<std::string>& hdu_list,std::string& fName,int64_t& fSize,int& naxis,long *naxes,std::vector<CARTA::HeaderEntry>& headerEntries, std::string& error);
    void readImagePixels();
    std::ifstream::pos_type filesize(const char* filename);

private:

    std::string _filename;
    fitsfile *fptr;
    std::vector<std::vector<float>> imageData;

    
};
#endif

