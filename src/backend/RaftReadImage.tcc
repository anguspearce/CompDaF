#ifndef RAFTREADIMAGE_TCC
#define RAFTRWADIMAGE_TCC
using namespace std::chrono;

template <typename T>
RaftReadImage<T>::RaftReadImage(fitsfile *fptr) : raft::kernel()
{

    status = 0;
    this->fptr = fptr;
    fits_get_img_param(this->fptr, 3, &bitpix, &naxis, naxes, &status);

    //allocating memory for one row
    pixels = (float *)malloc(naxes[0] * sizeof(float));

    if (pixels == NULL)
    {
        printf("Memory allocation error\n");
    }
    totPixels = 0;
    std::cout << naxes[0] << " " << naxes[1] << " " << naxes[2] << std::endl;
    //input.addPort<T>("addvec");
    output.addPort<T>("total");
}

// template <typename T, typename F>
// RaftReadImage<T, F>::RaftReadImage(const RaftReadImage &other) : raft::kernel()
// {

//     //input.addPort<T>("addvec");
//     output.addPort<std::vector<T>>("total");
// }

template <typename T>
raft::kstatus RaftReadImage<T>::run()
{
    for (fpixel[2] = naxes[2]; fpixel[2] >= 1; fpixel[2]--)
    {
        //std::vector<std::vector<float>> channelData;
        //std::cout << naxes[2] << " " << fpixel[2] << std::endl;
        for (fpixel[1] = naxes[1]; fpixel[1] >= 1; fpixel[1]--)
        {
            auto start = high_resolution_clock::now();

            status = 0;
            if (fits_read_pix(fptr, TFLOAT, fpixel, naxes[0], NULL, pixels, NULL, &status)) /* read row of pixels */
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
                    totPixels += 1;
                    v.push_back(pixels[ii]);
                }
            }
            // std::cout << pixels[ii] << " "; /* print each value  */
            //printf("\n");                       /* terminate line */
            //imageData.push_back(v);
            //channelData.push_back(v);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            readTime+=duration.count();
            //std::cout << "Raft Read Image Time: " << duration.count()*1e-6<<"s" << std::endl;
            auto c(output["total"].template allocate_s<T>());
            (*c) = v;
        }
        //std::cout << totPixels << std::endl;
        //auto c(output["total"].template allocate_s<std::vector<T>>());
        //(*c) = channelData;
    }

    //output["total"].send();
    //input["addvec"].recycle(1);

    return (raft::stop);
}

#endif