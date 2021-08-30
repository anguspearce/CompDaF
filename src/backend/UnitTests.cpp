// tests.cpp
// #include "whattotest.cpp"
#include <gtest/gtest.h>
  #include "FitsReader.h"
#include <iostream>
#include <carta-protobuf/defs.pb.h>
#include "EventHeader.h"

std::string fName="../sample.fits";
FitsReader fitsFile = FitsReader(fName);
bool errMargin(float a,float b){
  if(((b<=(a+(a*0.0001)))&&(b>=a-(a*0.0001)))||(a==b)){
    return true;
  }
  return false;
}
TEST(DimensionsTest, h_m51_b_s05_drz_sci) { 
    std::vector<std::string> hdu_list;
    
    int64_t fSize;
    int naxis, width, height, depth;
    long naxes[3] = {1, 1, 1};

    std::string messageOut;
    std::vector<CARTA::HeaderEntry> headerEntries;
    

    //Getting file_info
    fitsFile.FillFileInfo(hdu_list, fName, fSize, naxis, naxes, headerEntries, messageOut);
    EXPECT_PRED2(errMargin,419823360, fSize);
    EXPECT_EQ(8600, naxes[0]);
    EXPECT_EQ(12200, naxes[1]);
    EXPECT_EQ(1, naxes[2]);
}


TEST(HistogramTest, h_m51_b_s05_drz_sci) { 
  fitsFile.readImagePixels();
    CARTA::RegionHistogramData &regionHistogramData = fitsFile.getRegionHistoData();
    EXPECT_EQ(10243, regionHistogramData.histograms()[0].num_bins());
    EXPECT_PRED2(errMargin,0.013268050737679005, regionHistogramData.histograms()[0].bin_width());
    EXPECT_PRED2(errMargin,-0.6275313496589661, regionHistogramData.histograms()[0].first_bin_center());
    EXPECT_PRED2(errMargin,0.07252902101836572, regionHistogramData.histograms()[0].mean());
    EXPECT_PRED2(errMargin,0.20578365970699125, regionHistogramData.histograms()[0].std_dev());
    //EXPECT_PRED2(errMargin,1.352704772949e+2, regionHistogramData.histograms()[0].value());

}

TEST(StatisticsTest, h_m51_b_s05_drz_sci) { 
    CARTA::RegionStatsData &regionStatsData = fitsFile.getRegionStatsData();
    EXPECT_PRED2(errMargin,1.049200000000e+8, regionStatsData.statistics()[0].value());
    EXPECT_PRED2(errMargin,7.609744885247e+6, regionStatsData.statistics()[1].value());
    EXPECT_PRED2(errMargin,7.252902101837e-2, regionStatsData.statistics()[2].value());
    EXPECT_PRED2(errMargin,2.057836597843e-1, regionStatsData.statistics()[3].value());
    EXPECT_PRED2(errMargin,-6.341653466225e-1, regionStatsData.statistics()[4].value());
    EXPECT_PRED2(errMargin,1.352704772949e+2, regionStatsData.statistics()[5].value());

}
 
// TEST(SquareRootTest, NegativeNos) {
//     EXPECT_EQ(-1.0, squareRoot(-15.0));
//     EXPECT_EQ(-1.0, squareRoot(-0.2));
// }
 
FitsReader fitsFileBigM = FitsReader("../bigM81.fits");
TEST(DimensionsTest, bigM81) { 
    std::vector<std::string> hdu_list;
    
    int64_t fSize;
    int naxis, width, height, depth;
    long naxes[3] = {1, 1, 1};

    std::string messageOut;
    std::vector<CARTA::HeaderEntry> headerEntries;
    

    //Getting file_info
    fitsFileBigM.FillFileInfo(hdu_list, fName, fSize, naxis, naxes, headerEntries, messageOut);
    EXPECT_PRED2(errMargin,844816320, fSize);
    EXPECT_EQ(1100, naxes[0]);
    EXPECT_EQ(750, naxes[1]);
    EXPECT_EQ(256, naxes[2]);
}
TEST(HistogramTest, BigM81) { 
  fitsFileBigM.readImagePixels();
    CARTA::RegionHistogramData &regionHistogramData = fitsFileBigM.getRegionHistoData();
    EXPECT_EQ(908, regionHistogramData.histograms()[0].num_bins());
    EXPECT_PRED2(errMargin,0.0003651687002275139, regionHistogramData.histograms()[0].bin_width());
    EXPECT_PRED2(errMargin,-0.13961118459701538, regionHistogramData.histograms()[0].first_bin_center());
    EXPECT_PRED2(errMargin,0.00007653293441828733, regionHistogramData.histograms()[0].mean());
    EXPECT_PRED2(errMargin,0.001379763263000731, regionHistogramData.histograms()[0].std_dev());
    //EXPECT_PRED2(errMargin,1.352704772949e+2, regionHistogramData.histograms()[0].value());

}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}