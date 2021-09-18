#include "FitsReader.h"

/*
    Constructor of FitsReader that will store the file name. 
*/
FitsReader::FitsReader(const std::string &filename)
{
    _filename = filename;
}
/*
    FillFileInfo is called when a user selects to open a file
    This method will open a fits file and will only take information from
    the primary HDU of a fits file
*/
void FitsReader::FillFileInfo(std::vector<std::string> &hdu_list, std::string &fName, int64_t &fSize, int &naxis, long *naxes, std::vector<CARTA::HeaderEntry> &headerEntries, std::string &error)
{
    //Opening fits file
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
            //If no filename key then set filename to user input
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

            //Get image Dimensions
            fits_get_img_dim(fptr, &naxis, &status);

            //If 2D image
            if (naxis == 2)
            {
                fits_get_img_param(fptr, 2, &bitpix, &naxis, naxes, &status);
            }
            //else 3d image
            else if (naxis == 3)
            {

                fits_get_img_param(fptr, 3, &bitpix, &naxis, naxes, &status);
            }

            int nKeys;
            char kComment[FLEN_CARD];
            char kValue[FLEN_CARD];
            char kName[FLEN_CARD];
            status = 0;

            //Getting the number of header entires
            fits_get_hdrspace(fptr, &nkeys, NULL, &status);

            //Looping through each entry and adding it to the protocol message
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
    //Close file after use
    fits_close_file(fptr, &status);
}
/*
    readImagePixels is called after fillFileInfo
    This method will make calls to the Raftlib class
    to calculate the respective statistics and histogram
    data.
*/
void FitsReader::readImagePixels()
{
    int status = 0;

    //Open fits file
    fits_open_file(&fptr, _filename.c_str(), READONLY, &status);

    //initialising the number of axis and axes values
    long naxes[3] = {1, 1, 1};
    int bitpix, naxis;
    status = 0;

    //Getting the parameters
    fits_get_img_param(fptr, 3, &bitpix, &naxis, naxes, &status);

    //Variable to hold total number of non nan pixels
    long totPixels = 0;

    //Initialising a Raftlib class - constructing with image dimensions
    Raftlib<float> raft(naxes);

    //Calling region statistics implementation using raftlib
    raft.CalculateStatistics(fptr);
    std::cout << "Finsihed Raft stats through reading in raft" << std::endl;

    //Getting the number of non nan pixels
    totPixels = raft.getNoOfPixels();

    //Calculating mean, standard deviation and no of bins once region statistics is completed
    raft.mean(totPixels);
    raft.calcStdv(totPixels);
    raft.calculateBins();

    //Calling region histogram implementation using raftlib
    raft.CalculateHistogram(fptr);
    std::cout << "Finsihed Raft Histo through reading in raft" << std::endl;

    //Initialising and retireve data that goes in the protocol buffers once histogram is completed
    int noOfBins;
    double binWidth;
    std::vector<int> bins;
    raft.getBins(noOfBins, binWidth, bins);
    float min, max;
    raft.getMinAndMax(min, max);

    //setting histogram data into protocol buffers
    auto message_histogram = regionHistoData.add_histograms();
    message_histogram->set_channel(-1);
    message_histogram->set_num_bins(noOfBins);
    message_histogram->set_bin_width(binWidth);
    message_histogram->set_first_bin_center(raft.getBinCenter());
    message_histogram->set_mean(raft.getMean());
    message_histogram->set_std_dev(raft.getStdv());
    *message_histogram->mutable_bins() = {bins.begin(), bins.end()};

    //setting statistics data into protocol buffers
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

/*
    This method is used to return the protocol buffer
    for region histogram data
*/
CARTA::RegionHistogramData &FitsReader::getRegionHistoData()
{
    return regionHistoData;
}

/*
    This method is used to return the protocol buffer
    for region Statistics data
*/
CARTA::RegionStatsData &FitsReader::getRegionStatsData()
{
    return regionStatsData;
}

/*
    This method is used to calculate the filesize which
    which is used in the open file ack protobuf
*/
std::ifstream::pos_type FitsReader::filesize(const char *filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}