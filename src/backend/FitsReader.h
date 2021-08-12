#ifndef FITSREADER_H
#define FITSREADER_H

#include "fitsio.h"
#include <string>
#include <vector>
#include <iostream>

class FitsReader {
public:
    FitsReader(const std::string& filename);
    void GetHduList(std::vector<std::string>& hdu_list, std::string& error);
private:

    std::string _filename;

    
};
#endif

