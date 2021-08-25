#include "FitsReader.h"

FitsReader::FitsReader(const std::string &filename)
{
    _filename = filename;
}

void FitsReader::FillFileInfo(std::vector<std::string> &hdu_list, std::string &fName, int64_t &fSize, int &naxis, long *naxes, std::vector<CARTA::HeaderEntry> &headerEntries, std::string &error)
{
    //Opening fits file
    //fitsfile *fptr;
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
            if (status)
            {

                error = "FITS error: FILENAME missing or false.";
                fName = _filename.c_str();
            }
            else
            {
                fName = name;
            }
            //File Size
            fSize = filesize(_filename.c_str());

            //Get Image dimensions
            status = 0;
            int bitpix;
            //long naxes[3] = {1, 1, 1};
            fits_get_img_dim(fptr, &naxis, &status);

            if (naxis == 2)
            {
                fits_get_img_param(fptr, 2, &bitpix, &naxis, naxes, &status);
            }
            else if (naxis == 3)
            {

                fits_get_img_param(fptr, 3, &bitpix, &naxis, naxes, &status);
            }
            //std::cout<<naxes[0]<<" "<<naxes[1]<<" "<< naxes[2]<<" "<<sizeof(naxes)/sizeof(naxes[0])<<std::endl;
            // //Get image Width and Height
            // key = "NAXIS1";
            // fits_read_key(fptr, TINT, key.c_str(), &width, comment, &status);

            // key = "NAXIS2";
            // fits_read_key(fptr, TINT, key.c_str(), &height, comment, &status);]

            //getting no of axes and dimensions and data type

            //Get header entries
            int nKeys;
            char kComment[FLEN_CARD];
            char kValue[FLEN_CARD];
            char kName[FLEN_CARD];
            status = 0;
            fits_get_hdrspace(fptr, &nkeys, NULL, &status);
            for (int i = 1; i <= nkeys; i++)
            {
                CARTA::HeaderEntry hEntry;
                fits_read_keyn(fptr, i, kName, kValue, kComment, &status);
                hEntry.set_name(kName);
                hEntry.set_value(kValue);
                hEntry.set_comment(kComment);
                headerEntries.push_back(hEntry);
            }
        }
    }
}
void FitsReader::readImagePixels()
{
    //Reading image pixels into array
    long naxes[3] = {1, 1, 1}, fpixel[3] = {1, 1, 1};
    int bitpix, naxis, status = 0;
    float *pixels;
    fits_get_img_param(fptr, 3, &bitpix, &naxis, naxes, &status);

    //allocating memory for one row
    pixels = (float *)malloc(naxes[0] * sizeof(float));

    if (pixels == NULL)
    {
        printf("Memory allocation error\n");
    }

    // long imgSize = naxes[0] * naxes[1] * naxes[2];
    // pixels = new float[imgSize];
    // fits_read_pix(fptr, TFLOAT, fpixel, imgSize, NULL, pixels, NULL, &status);
    // std::cout << imgSize << std::endl;

    // for (long z = 128;  z < naxes[2]; z++)
    // {
    //     for (long y = 0;  y < naxes[1]; y++)
    //     {
    //         for (long x = 0;  x < naxes[0]; x++)
    //         {
    //             auto index=x+naxes[0] * y+(naxes[0]*naxes[1])*z;
    //             std::cout<<pixels[index];
    //         }
    //         std::cout<<std::endl;
    //     }
    //     break;
    // }
    //std::cout<<naxes[2]<<std::endl;
    for (fpixel[2] = naxes[2]; fpixel[2] >= 1; fpixel[2]--)
    {
        //std::cout << naxes[2] << " " << fpixel[2] << std::endl;
        for (fpixel[1] = naxes[1]; fpixel[1] >= 1; fpixel[1]--)
        {
            status = 0;
            if (fits_read_pix(fptr, TFLOAT, fpixel, naxes[0], 0, pixels, 0, &status)) /* read row of pixels */
            {
                std::cout << "error" << std::endl;
                break; /* jump out of loop on error */
            }
            std::vector<float> v;
            //This below code prints out each pixel with the row number
            //Is one way of accessing each pixel/row at a time

            // printf(" %4d ", fpixel[1]); /* print row number */
            for (int ii = 0; ii < naxes[0]; ii++)
            {
                if (std::isfinite(pixels[ii]))
                {
                    v.push_back(pixels[ii]);
                }
            }

            // std::cout << pixels[ii] << " "; /* print each value  */
            //printf("\n");                       /* terminate line */
            imageData.push_back(v);
        }
        //break;
    }
    // double tot = 0.0;
    // for (int i = 0; i < imageData.size(); i++)
    // {
    //     for (int j = 0; j < imageData[i].size(); j++)
    //     {
    //         if (std::isfinite(imageData[i][j]))
    //         {
    //             std::cout << imageData[i][j];
    //             tot += imageData[i][j];
    //         }
    //     }
    //     std::cout << std::endl;
    // }
    std::cout << "Copied image data to array" << std::endl;

    Raftlib<float> raft(naxes);
    raft.sum(imageData);
    raft.mean();
    raft.stdDev(imageData);
    int noOfBins;
    double binWidth;
    std::vector<int> bins;
    raft.getBins(noOfBins, binWidth, bins);
    // for(int i=0;i<bins.size();i++){
    //     std::cout<<bins[i]<<std::endl;
    // }
    std::cout << " " << naxes[0] << " " << naxes[1] << " Total: " << raft.getSum() << " Mean: " << raft.getMean() << " Stdv: " << raft.getStdv() << " No of Bins: " << noOfBins << " BinWidth: " << binWidth << std::endl;
    fits_close_file(fptr, &status);
}
std::ifstream::pos_type FitsReader::filesize(const char *filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}