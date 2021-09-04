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
    fits_close_file(fptr, &status);
}
void FitsReader::readImagePixels()
{
    int status = 0;
    fits_open_file(&fptr, _filename.c_str(), READONLY, &status);
    //Reading image pixels into array
    long naxes[3] = {1, 1, 1}, fpixel[3] = {1, 1, 1};
    int bitpix, naxis;
    status = 0;
    float *pixels;
    fits_get_img_param(fptr, 3, &bitpix, &naxis, naxes, &status);

    //allocating memory for one row
    pixels = (float *)malloc(naxes[0] * sizeof(float));

    if (pixels == NULL)
    {
        printf("Memory allocation error\n");
    }
    long totPixels = 0;

    Raftlib<float> raft(naxes);
    
    raft.TestStatsReadImage(fptr);
    std::cout<<"Finsihed Raft stats through reading in raft"<<std::endl;
    totPixels=raft.getNoOfPixels();
    // for (fpixel[2] = naxes[2]; fpixel[2] >= 1; fpixel[2]--)
    // {
    //     std::vector<std::vector<float>> channelData;
    //     //std::cout << naxes[2] << " " << fpixel[2] << std::endl;
    //     for (fpixel[1] = naxes[1]; fpixel[1] >= 1; fpixel[1]--)
    //     {
    //         status = 0;
    //         if (fits_read_pix(fptr, TFLOAT, fpixel, naxes[0], NULL, pixels, NULL, &status)) /* read row of pixels */
    //         {
    //             std::cout << "error" << std::endl;
    //             break; /* jump out of loop on error */
    //         }
    //         std::vector<float> v;
    //         //This below code prints out each pixel with the row number
    //         //Is one way of accessing each pixel/row at a time

    //         // printf(" %4d ", fpixel[1]); /* print row number */
    //         for (int ii = 0; ii < naxes[0]; ii++)
    //         {
    //             if (std::isfinite(pixels[ii]))
    //             {
    //                 totPixels += 1;
    //                 v.push_back(pixels[ii]);
    //             }
    //         }
    //         // std::cout << pixels[ii] << " "; /* print each value  */
    //         //printf("\n");                       /* terminate line */
    //         //imageData.push_back(v);
    //         channelData.push_back(v);
    //     }
    //     raft.statistics(channelData);
    // }


    //std::cout<<totPixels<<std::endl;

    //std::cout << "\nCopied image data to array" << std::endl;

    //Raftlib<float> raft(naxes);
    //raft.statistics(imageData);
    raft.mean(totPixels);
    raft.calcStdv(totPixels);
    raft.calculateBins();

    raft.TestHistoReadImage(fptr);
    std::cout<<"Finsihed Raft Histo through reading in raft"<<std::endl;
    // for (fpixel[2] = naxes[2]; fpixel[2] >= 1; fpixel[2]--)
    // {
    //     std::vector<std::vector<float>> channelData;
    //     //std::cout << naxes[2] << " " << fpixel[2] << std::endl;
    //     for (fpixel[1] = naxes[1]; fpixel[1] >= 1; fpixel[1]--)
    //     {
    //         status = 0;
    //         if (fits_read_pix(fptr, TFLOAT, fpixel, naxes[0], NULL, pixels, NULL, &status)) /* read row of pixels */
    //         {
    //             std::cout << "error" << std::endl;
    //             break; /* jump out of loop on error */
    //         }
    //         std::vector<float> v;
    //         //This below code prints out each pixel with the row number
    //         //Is one way of accessing each pixel/row at a time

    //         // printf(" %4d ", fpixel[1]); /* print row number */
    //         for (int ii = 0; ii < naxes[0]; ii++)
    //         {
    //             if (std::isfinite(pixels[ii]))
    //             {
    //                 //totPixels += 1;
    //                 v.push_back(pixels[ii]);
    //             }
    //         }
    //         // std::cout << pixels[ii] << " "; /* print each value  */
    //         //printf("\n");                       /* terminate line */
    //         //imageData.push_back(v);
    //         channelData.push_back(v);
    //     }
    //     raft.histogram(channelData);
    // }

    //raft.histogram(imageData);
    //raft.stdDev(imageData);
    int noOfBins;
    double binWidth;
    std::vector<int> bins;
    raft.getBins(noOfBins, binWidth, bins);
    float min, max;
    raft.getMinAndMax(min, max);
    //std::cout << " " << naxes[0] << " " << naxes[1] << " Total: " << raft.getSum() << " Mean: " << raft.getMean() << " Stdv: " << raft.getStdv() << " No of Bins: " << noOfBins << " BinWidth: " << binWidth << " Min: " << min << " Max: " << max << " FirstBinCenter: " << raft.getBinCenter() << std::endl;
    // for(int i=0;i<bins.size();i++){
    //     std::cout<<bins[i]<<std::endl;
    // }

    //setting histogram data
    auto message_histogram = regionHistoData.add_histograms();
    message_histogram->set_channel(-1);
    message_histogram->set_num_bins(noOfBins);
    message_histogram->set_bin_width(binWidth);
    message_histogram->set_first_bin_center(raft.getBinCenter());
    message_histogram->set_mean(raft.getMean());
    message_histogram->set_std_dev(raft.getStdv());
    *message_histogram->mutable_bins() = {bins.begin(), bins.end()};

    //setting statistics data
    auto numPixelsValue = regionStatsData.add_statistics();
    numPixelsValue->set_value(totPixels);
    numPixelsValue->set_stats_type(CARTA::StatsType::NumPixels);
    auto sumValue = regionStatsData.add_statistics();
    sumValue->set_value(raft.getSum());
    sumValue->set_stats_type(CARTA::StatsType::Sum);
    auto meanValue = regionStatsData.add_statistics();
    meanValue->set_value(raft.getMean());
    meanValue->set_stats_type(CARTA::StatsType::Mean);
    auto stdvValue = regionStatsData.add_statistics();
    stdvValue->set_value(raft.getStdv());
    stdvValue->set_stats_type(CARTA::StatsType::Sigma);
    auto minValue = regionStatsData.add_statistics();
    minValue->set_value(min);
    minValue->set_stats_type(CARTA::StatsType::Min);
    auto maxValue = regionStatsData.add_statistics();
    maxValue->set_value(max);
    maxValue->set_stats_type(CARTA::StatsType::Max);

    fits_close_file(fptr, &status);
}
CARTA::RegionHistogramData &FitsReader::getRegionHistoData()
{
    return regionHistoData;
}
CARTA::RegionStatsData &FitsReader::getRegionStatsData()
{
    return regionStatsData;
}
std::ifstream::pos_type FitsReader::filesize(const char *filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}