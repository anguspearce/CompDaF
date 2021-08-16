#include "FitsReader.h"

FitsReader::FitsReader(const std::string &filename)
{
    _filename = filename;
}

void FitsReader::FillFileInfo(std::vector<std::string> &hdu_list,std::string& fName,int64_t& fSize,int& naxis,int& width,int& height,std::vector<CARTA::HeaderEntry>& headerEntries, std::string &error)
{
    //Opening fits file
    fitsfile *fptr;
    int status = 0, nkeys, hdunum;

    //Open fits file
    fits_open_file(&fptr, _filename.c_str(), READONLY, &status);
    //Get number of headers
    fits_get_num_hdus(fptr, &hdunum, &status);

    for (int hdu = 0; hdu < hdunum; hdu++)
    {

        std::string key;
        char comment[70];

        if (hdu == 0)
        {
            // Check SIMPLE for primary header only; exit if false
            status = 0;
            key = "SIMPLE";
            bool simple(false);
            fits_read_key(fptr, TLOGICAL, key.c_str(), &simple, comment, &status);

            if (status || !simple)
            {
                error = "FITS error: SIMPLE missing or false.";
                break;
            }
            std::string hdu_name = std::to_string(hdu);

            hdu_list.push_back(hdu_name);
            
            //Getting the file name
            status = 0;
            key = "FILENAME";
            char name[70];
            fits_read_key(fptr, TSTRING, key.c_str(), name, comment, &status);
            fName=name;

            //File Size
            fSize=filesize(_filename.c_str());

            //Get Image dimensions
            fits_get_img_dim(fptr, &naxis,&status);

            //Get image Width and Height
            key = "NAXIS1";
            fits_read_key(fptr, TINT, key.c_str(), &width, comment, &status);

            key = "NAXIS2";
            fits_read_key(fptr, TINT, key.c_str(), &height, comment, &status);

            //Get header entries
            int nKeys;
            char kComment[FLEN_CARD];
            char kValue[FLEN_CARD];
            char kName[FLEN_CARD];

            fits_get_hdrspace(fptr, &nkeys, NULL, &status);
            for (int i = 1; i <= nkeys; i++)  { 
                CARTA::HeaderEntry hEntry;
                fits_read_keyn(fptr, i,kName,kValue, kComment, &status);
                hEntry.set_name(kName);
                hEntry.set_value(kValue);
                hEntry.set_comment(kComment);
                headerEntries.push_back(hEntry);

            }

        }
        
    }
    fits_close_file(fptr, &status);

}
std::ifstream::pos_type FitsReader::filesize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg(); 
}