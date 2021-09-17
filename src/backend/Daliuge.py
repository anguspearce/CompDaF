# Daliuge
from dlg import droputils, utils
from dlg.drop import BarrierAppDROP, BranchAppDrop, ContainerDROP
from dlg.meta import dlg_float_param, dlg_string_param
from dlg.meta import dlg_bool_param, dlg_int_param
from dlg.meta import dlg_component, dlg_batch_input
from dlg.meta import dlg_batch_output, dlg_streaming_input

import pickle
import numpy as np
# Fits file reader
from astropy.io import fits
import os
import logging
import time
import math


logger = logging.getLogger(__name__)


## 
# \file Daliuge.py
##
# \brief FITSread\n
# \details App that reads fits file data to memory
# \par EAGLE_START
# \param gitrepo $(GIT_REPO)
# \param version $(PROJECT_VERSION)
# \param category PythonApp
# \param[in] param/appclass/Daliuge.FITSread/String
#     \~English Application class\n
# \param[in] param/fileName/dummy.fits/String
#     \~English Path to FITS file
# \param[out] port/ndarray
#     \~English Port outputting the ndarray view 
# \par EAGLE_END
class FITSread(BarrierAppDROP):
 
    compontent_meta = dlg_component('FITSread', 'FITS reader',
                                    [dlg_batch_input('binary/*', [])],
                                    [dlg_batch_output('binary/*', [])],
                                    [dlg_streaming_input('binary/*')])

    fileName = dlg_string_param('fileName','dummy.fits') # NOTE: The variable name has to match the value of the param name!

    def initialize(self, **kwargs):
        super(FITSread, self).initialize(**kwargs)

    def run(self):
        logger.info(f"Input FITS file: {self.fileName}")
        # Fetch FITS data
        self.loadFile(self.fileName)
        for out in self.outputs:
            d = pickle.dumps(self.data)
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


##
# \brief SplitApp\n
# \details App that splits fits file into number of outputs.
# \par EAGLE_START
# \param gitrepo $(GIT_REPO)
# \param version $(PROJECT_VERSION)
# \param category PythonApp
# \param[in] param/appclass/Daliuge.SplitApp/String
#     \~English Application class\n
# \param[in] port/ndarray
#     \~English Port receiving entire ndarray
# \param[out] port/ndarray
#     \~English Port outputting the ndarray view
# \par EAGLE_END
class SplitApp(BarrierAppDROP):
    
    compontent_meta = dlg_component('SplitApp', 'Split Vector App.',
                                    [dlg_batch_input('binary/*', [])],
                                    [dlg_batch_output('binary/*', [])],
                                    [dlg_streaming_input('binary/*')])

    def run(self):
        # Fetch data from input port
        self.getInputArrays()
        # self.outputs is a list of output ports
        outs = self.outputs
        # Split the array into the number of output ports 
        arrs = np.array_split(self.data, len(outs))
        
        
        t = time.perf_counter() # Timer 1

        # Max of entire data set (ignoring NaN)
        max = np.nanmax(self.data) 
        # Min of entire data set (ignoring NaN)
        min = np.nanmin(self.data)
        # Get number of bins 
        bins = self.getNumBins()

        #t1 = time.perf_counter() # Timer 2 
        
        #t = t1-t
        
        

        # Zip each array view to a corresponding output (parallel iteration)
        z = zip(outs, arrs)
        # Pass pickled data to each respective output
        for [out, arr] in z:
            d = pickle.dumps([arr, min, max, bins, t])
            out.len = len(d)
            out.write(d)
            
    
    def getNumBins(self):
        # Returns the max between 2 and square root of (width * height) of the image
        return int(max(2, math.sqrt(self.data.shape[0] * self.data.shape[1])))

    def getInputArrays(self):
        """
        Create the input array from all inputs received. Shape is
        (<#inputs>, <#elements>), where #elements is the length of the
        vector received from one input.
        """
        ins = self.inputs
        if len(ins) != 1:
            raise Exception(
                'Only one input should have been added to %r' % self)
        
        self.data = np.array(pickle.loads(droputils.allDropContents(ins[0], bufsize=8192)) , dtype= np.float64)



##
# \brief ComputeStatsApp\n
# \details Array Statistics App that takes in a np array and calculates statistics on it.
# \par EAGLE_START
# \param gitrepo $(GIT_REPO)
# \param version $(PROJECT_VERSION)
# \param category PythonApp
# \param[in] param/appclass/Daliuge.ComputeStatsApp/String
#             \~English Application class\n
# \param[in] port/ndarray
#             \~English Port receiving ndarray view
# \param[out] port/list
#             \~English Port outputs list of calculated statistics
# \par EAGLE_END
class ComputeStatsApp(BarrierAppDROP):
    
    compontent_meta = dlg_component('ComputeStatsApp', 'Array Stats App.',
                                    [dlg_batch_input('binary/*', [])],
                                    [dlg_batch_output('binary/*', [])],
                                    [dlg_streaming_input('binary/*')])

    def initialize(self, **kwargs):
        super(ComputeStatsApp, self).initialize(**kwargs)

    def run(self):
        # Fetch data from input port in form [arr, min, max, bins, t] (t is the time taken to calculate min, max, number of bins over entire data set)
        self.getInputArrays()
        # data is the numpy array view 
        data = np.array(self.d[0], dtype= np.float64)

        t0 = time.perf_counter() # Timer 1

        # Sum of data
        sum = np.nansum(data, dtype=np.float64)
        # Sum of the squared data
        sumSq = np.nansum(np.multiply(data, data, dtype= np.float64), dtype= np.float64)
        # Number of pixels
        pixels = data.size - np.count_nonzero(np.isnan(data))
        # Histogram that uses the received number of bins, min, and max, calculated in the previous Drop
        hist, bins = np.histogram(data, self.d[3], (self.d[1], self.d[2]))

        t1 = time.perf_counter() # Timer 2
        t1 = t1-t0

        # Combining calcalation results to send to output Drop, as well as min, max, bins, t from prev Drop
        stats = [sum, sumSq, pixels, hist, t1, self.d[1], self.d[2], self.d[3], self.d[4]]
        stats = pickle.dumps(stats)
        
        # Only one output should have been added
        outs = self.outputs
        if len(outs) != 1:
            raise Exception(
                'Only one output should have been added to %r' % self)
        # Write the pickled stats list to the only output
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
        if len(ins) != 1:
            raise Exception(
                'Only one input should have been added to %r' % self)
        
        self.d =  pickle.loads(droputils.allDropContents(ins[0], bufsize=8192))


##
# \brief GatherApp\n
# \details GatherApp that receives list of results and compares/combines.
# \par EAGLE_START
# \param gitrepo $(GIT_REPO)
# \param version $(PROJECT_VERSION)
# \param category PythonApp
# \param[in] param/appclass/Daliuge.GatherApp/String
#     \~English Application class\n
# \param[in] port/list
#     \~English Port receiving list of statistics to combine
# \param[out] port/string
#     \~English Port outputting final results
# \par EAGLE_END
class GatherApp(BarrierAppDROP):
    
    compontent_meta = dlg_component('Gather App', 'Gather App.',
                                    [dlg_batch_input('binary/*', [])],
                                    [dlg_batch_output('binary/*', [])],
                                    [dlg_streaming_input('binary/*')])
    def run(self):
        # Set self.data to list of data from inputs
        self.getInputArrays()
        
        
        # Default values for time, sum, sum squared, pixels, histogram
        t = 0
        sum = 0
        sumSq = 0
        pixels = 0
        hist = None
        

        #t0 = time.perf_counter() # Timer 1

        for i in self.data:
            sum += i[0]
            sumSq += i[1]
            pixels += i[2]
            if hist is None:
                hist = i[3]
            else:
                hist += i[3]
            t += i[4]
        mean = sum/pixels
        stddev = np.sqrt(sumSq/pixels - mean**2) #CHECK WHETHER THIS MESSES UP RESULTS (sumSq/pixels may not give float)
        
        t1 = time.perf_counter() # Timer 2
        
        t = t1 - self.data[0][8]
        #t += (t1-t0) # Add time taken to compare results of each Drop

        # Combining calculation results to send to output Drop
        stats = "Sum: {sum} \nMean: {mean} \nMin: {min} \nMax: {max} \nNumber of bins: {bins} \nStandard deviation: {stddev} \nSumSq: {sumSq} \nPixels: {pixels} \nTime taken: {t}"
        stats = stats.format(sum=sum, mean=mean, min=self.data[0][5], max=self.data[0][6], bins=self.data[0][7], stddev=stddev, sumSq=sumSq, pixels=pixels, t=t)
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