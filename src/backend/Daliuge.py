## 
 # \file LoadVis.h 

import dlg
import pickle
import numpy as np
from dlg import droputils
# Fits file reader
from astropy.io import fits
import os
import logging
import time
import math

##
# @brief SplitVector\n
# @details App that reads fits file data to memory and splits it into number of outputs.
# @par EAGLE_START
# @param gitrepo $(GIT_REPO)
# @param version $(PROJECT_VERSION)
# @param category PythonApp
# @param[in] param/appclass/Daliuge.SplitVector/String
#     \~English Application class\n
# @param[out] port/ndarray
#     \~English Port outputting the ndarray view 
# @par EAGLE_END
class SplitVector(dlg.drop.BarrierAppDROP):
    
    compontent_meta = dlg.meta.dlg_component('SplitVector', 'Split Vector App.',
                                    [dlg.meta.dlg_batch_input('binary/*', [])],
                                    [dlg.meta.dlg_batch_output('binary/*', [])],
                                    [dlg.meta.dlg_streaming_input('binary/*')])

    def run(self):
        # Load file using fits (astropy)
        self.loadFile("../sample.fits")
        
        outs = self.outputs
        # Split the array into the number of output ports 
        arrs = np.array_split(self.data, len(outs))

        
        t0 = time.perf_counter()
        # Max of entire data set (ignoring NaN)
        max = np.nanmax(self.data) 
        # Min of entire data set (ignoring NaN)
        min = np.nanmin(self.data)
        # Get number of bins 
        bins = self.getNumBins()
        # Set pickled file location
        pkl_file = open("values.pkl", 'wb')
        # Create pickled file containing min, max, number of bins
        values = pickle.dump([min, max ,bins], pkl_file)
        
        t1 = time.perf_counter()

        # Zip is a quick way to combine data storages for parallel iteration
        z = zip(outs, arrs)
        for [out, arr] in z:
            d = pickle.dumps(arr)
            out.len = len(d)
            out.write(d)

    def loadFile(self, file):
        try:
            with fits.open(file, memmap=False) as hdu:
                if "data" not in dir(hdu[0]):
                    raise Exception("Unexpected format in fits file.")
                
                self.data = np.array(hdu[0].data, dtype=np.float64)
        except:
            raise Exception("Unable to load file.")
    
    def getNumBins(self):
        # Returns the max between 2 and square root of (width * height) of the image
        return int(max(2, math.sqrt(self.data.shape[0] * self.data.shape[1])))

##
# @brief StatisticsApp\n
# @details Array Statistics App that takes in a np array and calculates statistics on it.
# @par EAGLE_START
# @param gitrepo $(GIT_REPO)
# @param version $(PROJECT_VERSION)
# @param category PythonApp
# @param[in] param/appclass/Daliuge.StatisticsApp/String
#     \~English Application class\n
# @param[in] port/ndarray
#     \~English Port receiving ndarray view
# @param[out] port/list
#     \~English Port outputs list of calculated statistics
# @par EAGLE_END
class StatisticsApp(dlg.drop.BarrierAppDROP):
    
    compontent_meta = dlg.meta.dlg_component('StatisticsApp', 'Array Stats App.',
                                    [dlg.meta.dlg_batch_input('binary/*', [])],
                                    [dlg.meta.dlg_batch_output('binary/*', [])],
                                    [dlg.meta.dlg_streaming_input('binary/*')])

    def initialize(self, **kwargs):
        super(StatisticsApp, self).initialize(**kwargs)

    def run(self):
        # Fetch data from input port
        self.getInputArrays()
        # Load min, max, number of bins from pickled file
        self.values = pickle.load("values.pkl")

        # Timestamp 1
        t0 = time.perf_counter()
        # Sum of data
        total = np.nansum(self.data, dtype=np.float64)
        # Sum of the squared data
        sumsquares = np.nansum(np.multiply(self.data, self.data, dtype=np.float64), dtype=np.float64)
        # Number of pixels
        pixels = self.data.size - np.count_nonzero(np.isnan(self.data))
        # Histogram that uses the received number of bins, min, and max, calculated in the previous Drop
        h = np.histogram(self.data, self.values[2], (self.values[0], self.values[1]))
        # Timestamp
        t5 = time.perf_counter()
        
        # Combining calcalation results to send to output Drop
        stats = [total, self.values[0], self.values[1], sumsquares, pixels, h, t5-t0]
        stats = pickle.dumps(stats)
        
        # At least one output should have been added
        outs = self.outputs
        if len(outs) < 1:
            raise Exception(
                'At least one output should have been added to %r' % self)
        for o in outs:
            o.len = len(stats)
            o.write(stats)


    def getInputArrays(self):
        """
        Create the input array from all inputs received. Shape is
        (<#inputs>, <#elements>), where #elements is the length of the
        vector received from one input.
        """
        ins = self.inputs
        if len(ins) < 2:
            raise Exception(
                'At least two inputs should have been added to %r' % self)
        
        self.data = np.array(pickle.loads(droputils.allDropContents(ins[0])) , dtype=np.float64)


##
# @brief CompareAndCombineApp\n
# @details CompareAndCombineApp that receives list of results and compares/combines.
# @par EAGLE_START
# @param gitrepo $(GIT_REPO)
# @param version $(PROJECT_VERSION)
# @param category PythonApp
# @param[in] param/appclass/Daliuge.CompareAndCombineApp/String
#     \~English Application class\n
# @param[in] port/list
#     \~English Port receiving list of statistics to combine
# @param[out] port/string
#     \~English Port outputting final results
# @par EAGLE_END
class CompareAndCombineApp(dlg.drop.BarrierAppDROP):
    
    compontent_meta = dlg.meta.dlg_component('CompareAndCombineApp', 'Combine Results App.',
                                    [dlg.meta.dlg_batch_input('binary/*', [])],
                                    [dlg.meta.dlg_batch_output('binary/*', [])],
                                    [dlg.meta.dlg_streaming_input('binary/*')])
    def run(self):
        self.getInputArrays()

        
        t = 0
        total = 0
        max = -999999999
        min = 999999999
        sumsquares = 0
        pixels = 0
        h = None

        t0 = time.perf_counter()
        for i in self.data:
            total += i[0]
            if i[1] < min:
                min = i[1]
            if i[2] > max:
                max = i[2]
            sumsquares += i[3]
            pixels += i[4]
            if h == None:
                h = i[5]
            else:
                h += i[5]
            t += i[6]
        mean = total/pixels
        stddev = np.sqrt(sumsquares/pixels - mean**2)
        t1 = time.perf_counter()
        t += (t1-t0)
        stats = "Total: {total} Mean: {mean} Max: {max} Min: {min} Standard deviation: {stddev} Pixels: {pixels} Time taken: {t}".format(total=total, mean=mean, max=max, min=min, stddev=stddev, pixels=pixels, t=t)

        # At least one output should have been added
        outs = self.outputs
        if len(outs) < 1:
            raise Exception(
                'At least one output should have been added to %r' % self)
        for o in outs:
            o.len = len(stats.encode())
            o.write(stats.encode())


    def getInputArrays(self):
        """
        Create the input array from all inputs received. Shape is
        (<#inputs>, <#elements>), where #elements is the length of the
        vector received from one input.
        """
        ins = self.inputs
        if len(ins) < 1:
            raise Exception(
                'At least one input should have been added to %r' % self)

        self.data = [pickle.loads(droputils.allDropContents(inp)) for inp in ins]