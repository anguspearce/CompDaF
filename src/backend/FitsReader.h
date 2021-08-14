#ifndef FITSREADER_H
#define FITSREADER_H

#include "fitsio.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class FitsReader {
public:
    FitsReader(const std::string& filename);
    void FillFileInfo(std::vector<std::string>& hdu_list,std::string& fName,int64_t& fSize, std::string& error);
    std::ifstream::pos_type filesize(const char* filename);

private:

    std::string _filename;

    
};
#endif

