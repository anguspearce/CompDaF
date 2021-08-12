#include "FitsReader.h"

FitsReader::FitsReader(const std::string& filename) {
    _filename = filename;
}

void FitsReader::GetHduList(std::vector<std::string>& hdu_list, std::string& error) {
    //Opening fits file
    fitsfile *fptr;         
    int status = 0,nkeys,hdunum;

    //Open fits file
    fits_open_file(&fptr, _filename.c_str(), READONLY, &status);
    //Get number of headers
    fits_get_num_hdus( fptr, &hdunum, &status);

    for(int hdu = 0; hdu<hdunum; hdu++ ){
        std::string key;
        char comment[70];

        if (hdu == 0) {
            // Check SIMPLE for primary header only; exit if false
            status = 0;
            key = "SIMPLE";
            bool simple(false);
            fits_read_key(fptr, TLOGICAL, key.c_str(), &simple, comment, &status);

            if (status || !simple) {
                error = "FITS error: SIMPLE missing or false.";
                break;
            }
        std::string hdu_name = std::to_string(hdu);

        hdu_list.push_back(hdu_name);
        int* hdutype(nullptr);
        status = 0;
        fits_movrel_hdu(fptr, 1, hdutype, &status);
    }
    fits_close_file(fptr, &status);
}}