#ifndef RAFTREADIMAGE_TCC
#define RAFTRWADIMAGE_TCC
using namespace std::chrono;

/*
    RaftReadImage constructor
    Assigns the fits pointer that will be used to
    get the parameters and open file in the run.
    Allocates memory for a row.
*/
template <typename T>
RaftReadImage<T>::RaftReadImage(fitsfile *fptr) : raft::kernel()
{
    input.addPort<std::vector<long long>>("range");
    status = 0;
    this->fptr = fptr;

    //Getting the image parameters - naxis, naxes and bitpixs
    fits_get_img_paramll(this->fptr, 3, &bitpix, &naxis, naxes, &status);

    //Allocating a memory for a row
    //pixels = (float *)malloc(naxes[0] * sizeof(float));
    pixels = new float[naxes[0]];

    if (pixels == NULL)
    {
        printf("Memory allocation error\n");
    }

    //set no of non-nan pixels to 0
    totPixels = 0;
    std::cout << naxes[0] << " " << naxes[1] << " " << naxes[2] << std::endl;

    //Declaring one output port called total.
    output.addPort<T>("total");
}

template <typename T>
RaftReadImage<T>::RaftReadImage(const RaftReadImage &other) : raft::kernel()
{
    input.addPort<std::vector<long long>>("range");
    status = 0;
    this->fptr = other.fptr;

    //Getting the image parameters - naxis, naxes and bitpixs
    fits_get_img_paramll(this->fptr, 3, &bitpix, &naxis, naxes, &status);

    //Allocating a memory for a row
    //pixels = (float *)malloc(naxes[0] * sizeof(float));
    pixels = new float[naxes[0]];

    if (pixels == NULL)
    {
        printf("Memory allocation error\n");
    }

    //set no of non-nan pixels to 0
    totPixels = other.totPixels;
    std::cout << naxes[0] << " " << naxes[1] << " " << naxes[2] << std::endl;

    //Declaring one output port called total.
    output.addPort<T>("total");
}

/*
    Method to access ports and do work
    This method will specifically read a fits file
    a row at a time and passes the row down the stream as
    it is ready
*/
template <typename T>
raft::kstatus RaftReadImage<T>::run()
{
    auto &t(input["range"].template peek<std::vector<long long>>());
    std::cout<<t[0]<<" "<<t[1]<<std::endl;
    input["range"].unpeek();

    //Loop through depth
    for (fpixel[2] = naxes[2]; fpixel[2] >= 1; fpixel[2]--)
    {
        //Loop through rows
        for (fpixel[1] = t[1]; fpixel[1] >= t[0]; fpixel[1]--)
        {
            //Timing the reading using cfitsio for testing
            auto start = high_resolution_clock::now();

            status = 0;

            //Cfitsio reading an entire row into allocated pixels pointer array
            if (fits_read_pixll(fptr, TFLOAT, fpixel, naxes[0], nullptr, pixels, nullptr, &status))
            {
                std::cout << "error" << std::endl;
                break;
            }

            //temp vector that will be passed down the stream
            std::vector<float> v;

            //looping through pixels and eliminating any nan pixels, incrementing counter
            //and puishing to temp vector
            for (int ii = 0; ii < naxes[0]; ii++)
            {
                if (std::isfinite(pixels[ii]))
                {
                    totPixels += 1;
                    v.push_back(pixels[ii]);
                }
            }

            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            
            //adding read time to global read time
            readTime += duration.count();
            
            //allocate_s returns an object of the allocated memory
            //which will be released to the downstream port. pushing the memory allocated
            //to the consumer is handled by the returned object
            //exiting the calling stack frame.
            auto c(output["total"].template allocate_s<T>());
            (*c) = v;
        }
    }
    delete(pixels);
    //Since this is a prodducer kerner and only has an output (no inputs)
    //must user stop to let the scheduler know when to exit the application
    return (raft::stop);
}

#endif