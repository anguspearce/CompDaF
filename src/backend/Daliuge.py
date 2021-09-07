import dlg
import pickle
import numpy as np
from dlg import droputils
# Fits file reader
from astropy.io import fits
import os
import logging
import time

## 
 # \file Daliuge.py 
##
# @brief SplitVector\n
# @details App that reads fits file data to memory and splits it into number of outputs.
# @par EAGLE_START
# @param gitrepo $(GIT_REPO)
# @param version $(PROJECT_VERSION)
# @param category PythonApp
# @param[in] param/appclass/Daliuge.SplitVector/String
#     \~English Application class\n
# @param[out] port/array
#     \~English Port outputting list to be summed

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
        arrs = np.array_split(self.data, len(outs))

        z = zip(outs, arrs)
        for [out, arr] in z:
            d = pickle.dumps(arr)
            out.len = len(d)
            out.write(d)

    def loadFile(self, file):
        try:
            with fits.open(file, memmap=False) as hdu:
                print("in")
                if "data" not in dir(hdu[0]):
                    raise Exception("Unexpected format in fits file.")
                
                self.data = np.array(hdu[0].data, dtype=np.float64)
        except:
            raise Exception("Unable to load file.")

##
# @brief ArrayStatsApp\n
# @details Array Statistics App that takes in a np array and calculates statistics on it.
# @par EAGLE_START
# @param gitrepo $(GIT_REPO)
# @param version $(PROJECT_VERSION)
# @param category PythonApp
# @param[in] param/appclass/Daliuge.ArrayStatsApp/String
#     \~English Application class\n
# @param[in] port/array
#     \~English Port receiving array or integer 
# @param[out] port/list
#     \~English Port outputs list of calculated statistics

# @par EAGLE_END
class ArrayStatsApp(dlg.drop.BarrierAppDROP):
    
    compontent_meta = dlg.meta.dlg_component('ArrayStatsApp', 'Array Stats App.',
                                    [dlg.meta.dlg_batch_input('binary/*', [])],
                                    [dlg.meta.dlg_batch_output('binary/*', [])],
                                    [dlg.meta.dlg_streaming_input('binary/*')])

    def initialize(self, **kwargs):
        super(ArrayStatsApp, self).initialize(**kwargs)

    def run(self):
        
        self.getInputArrays()
 
        # Timestamp 1
        t0 = time.perf_counter()

        total = np.nansum(self.data, dtype=np.float64)
        #t1 = time.perf_counter() 
        max = np.nanmax(self.data)
        #t2 = time.perf_counter() 
        min = np.nanmin(self.data)
        #t3 = time.perf_counter() 
        sumsquares = np.nansum(np.multiply(self.data, self.data, dtype=np.float64), dtype=np.float64)
        #t4 = time.perf_counter() 
        pixels = self.data.size - np.count_nonzero(np.isnan(self.data))
        t5 = time.perf_counter()
        
        
        stats = [total, max, min, sumsquares, pixels, t5-t0]
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
        if len(ins) < 1:
            raise Exception(
                'At least one input should have been added to %r' % self)

        self.data = np.array([pickle.loads(droputils.allDropContents(inp)) for inp in ins], dtype=np.float64)

##
# @brief CombineResultsApp\n
# @details CombineResultsApp that receives list of results and compares/combines.
# @par EAGLE_START
# @param gitrepo $(GIT_REPO)
# @param version $(PROJECT_VERSION)
# @param category PythonApp
# @param[in] param/appclass/Daliuge.CombineResultsApp/String
#     \~English Application class\n
# @param[in] port/list
#     \~English Port receiving list of statistics to combine
# @param[out] port/string
#     \~English Port outputting final results

# @par EAGLE_END
class CombineResultsApp(dlg.drop.BarrierAppDROP):
    
    compontent_meta = dlg.meta.dlg_component('CombineResultsApp', 'Combine Results App.',
                                    [dlg.meta.dlg_batch_input('binary/*', [])],
                                    [dlg.meta.dlg_batch_output('binary/*', [])],
                                    [dlg.meta.dlg_streaming_input('binary/*')])
    def run(self):
        self.getInputArrays()
        timeTaken = 0
        total = 0
        max = -999999999
        min = 999999999
        sumsquares = 0
        pixels = 0

        t0 = time.perf_counter()
        for i in self.data:
            total += i[0]
            if i[1] > max:
                max = i[1]
            if i[2] < min:
                min = i[2]
            sumsquares += i[3]
            pixels += i[4]
            timeTaken += i[5]
        mean = total/pixels
        stddev = np.sqrt(sumsquares/pixels - mean**2)
        t1 = time.perf_counter()
        timeTaken += (t1-t0)
        stats = "Total: {total} Mean: {mean} Max: {max} Min: {min} Standard deviation: {stddev} Pixels: {pixels} Time taken: {timeTaken}".format(total=total, mean=mean, max=max, min=min, stddev=stddev, pixels=pixels, timeTaken=timeTaken)

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