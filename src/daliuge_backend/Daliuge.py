# Daliuge
from dlg import droputils, utils
from dlg.ddap_protocol import AppDROPStates
from dlg.drop import BarrierAppDROP, BranchAppDrop, ContainerDROP, AppDROP
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
# \brief SplitStatsApp\n
# \details App that reads and splits a fits file into number of outputs.
# \par EAGLE_START
# \param gitrepo $(GIT_REPO)
# \param version $(PROJECT_VERSION)
# \param category PythonApp
# \param[in] param/appclass/CompDaF.src.daliuge_backend.Daliuge.SplitStatsApp/String
#     \~English Application class\n
# \param[in] param/fileName/20000.fits/String
#     \~English Path to FITS file
# \param[out] port/list
#     \~English Port outputting the list containing respective splits
# \par EAGLE_END
class SplitStatsApp(BarrierAppDROP):
    
    compontent_meta = dlg_component('SplitStatsApp', 'Split Stats App',
                                    [dlg_batch_input('binary/*', [])],
                                    [dlg_batch_output('binary/*', [])],
                                    [dlg_streaming_input('binary/*')])

    # fileName is relative to tmp/.dlg/code/ directory

    fileName = dlg_string_param('fileName','20000.fits') # NOTE: The variable name has to match the value of the param name!
    fileDir = "../testdata/"

    def initialize(self, **kwargs):
        super(SplitStatsApp, self).initialize(**kwargs)
        self.file = os.path.normpath(self.fileDir + "sample.fits")
        self.start = 0

    def run(self):
        t = time.perf_counter()
        try:
            with fits.open(self.file, memmap=True) as hdu:
                if "data" not in dir(hdu[0]):
                    raise Exception("Unexpected format in fits file.")
                self.s = hdu[0].data.shape[0]
            self.width = math.ceil(self.s / len(self.outputs)) 
        except:
            raise Exception("Unable to load file.")

        for out in self.outputs:
            if (self.start + self.width) > self.s:
                d = pickle.dumps([self.start, self.s, self.file, t])
            else:
                d = pickle.dumps([self.start, self.start + self.width, self.file, t])
            out.len = len(d)
            out.write(d)
            self.start += self.width


##
# \brief ComputeStatsApp\n
# \details Array Statistics App that takes in a np array and calculates statistics on it.
# \par EAGLE_START
# \param gitrepo $(GIT_REPO)
# \param version $(PROJECT_VERSION)
# \param category PythonApp
# \param[in] param/appclass/CompDaF.src.daliuge_backend.Daliuge.ComputeStatsApp/String
#             \~English Application class\n
# \param[in] port/list
#             \~English Port receiving respective split
# \param[out] port/stats
#             \~English Port outputs list of calculated statistics
# \par EAGLE_END
class ComputeStatsApp(BarrierAppDROP):
    
    compontent_meta = dlg_component('ComputeStatsApp', 'Array Stats App.',
                                    [dlg_batch_input('binary/*', [])],
                                    [dlg_batch_output('binary/*', [])],
                                    [dlg_streaming_input('binary/*')])

    def initialize(self, **kwargs):
        super(ComputeStatsApp, self).initialize(**kwargs)
        self.sum = 0
        self.sumSq = 0
        self.pixels = 0
        self.min = 9999999
        self.max = -9999999

    def run(self):
        self.d = pickle.loads(droputils.allDropContents(self.inputs[0]))
        start = self.d[0]
        end = self.d[1]
        width = math.ceil((end-start)/4)
        file = self.d[2]

        try:
            with fits.open(file, memmap=True) as hdu:
                if "data" not in dir(hdu[0]):
                    raise Exception("Unexpected format in fits file.")
                temp = start + width

                for i in range(4):
                    if temp > end:
                        temp = end
                    data = hdu[0].data[start:temp]

                    self.sum += np.nansum(data, dtype=np.float64)
                    self.sumSq += np.nansum(np.multiply(data, data, dtype= np.float64), dtype= np.float64)
                    self.pixels += data.size - np.count_nonzero(np.isnan(data))
                    mi = np.nanmin(data)
                    ma = np.nanmax(data)
                    if mi < self.min:
                        self.min = mi
                    if ma > self.max:
                        self.max = ma
                    start = temp
                    temp += width
        except:
            raise Exception("Unable to load file.")

        stats = [self.sum, self.sumSq, self.pixels, self.min, self.max, self.d[3], file]
        stats = pickle.dumps(stats)

        outs = self.outputs

        outs[0].len = len(stats)
        outs[0].write(stats)


##
# \brief GatherStatsApp\n
# \details GatherStatsApp that receives list of results and compares/combines.
# \par EAGLE_START
# \param gitrepo $(GIT_REPO)
# \param version $(PROJECT_VERSION)
# \param category PythonApp
# \param[in] param/appclass/CompDaF.src.daliuge_backend.Daliuge.GatherStatsApp/String
#     \~English Application class\n
# \param[in] port/stats
#     \~English Port receiving list of statistics to combine
# \param[out] port/list
#     \~English Port outputting list of min, max, file
# \par EAGLE_END
class GatherStatsApp(BarrierAppDROP):
    
    compontent_meta = dlg_component('GatherStatsApp', 'Gather Statsistics App',
                                    [dlg_batch_input('binary/*', [])],
                                    [dlg_batch_output('binary/*', [])],
                                    [dlg_streaming_input('binary/*')])

    def initialize(self, **kwargs):
        super(GatherStatsApp, self).initialize(**kwargs)
        self.sum = 0
        self.sumSq = 0
        self.min = 9999999
        self.max = -9999999
        self.pixels = 0

    def run(self):
        # Set self.data to list of data from inputs
        self.getInputArrays()
        
        for i in self.data:
            self.sum += i[0]
            self.sumSq += i[1]
            self.pixels += i[2]
            if i[3] < self.min:
                self.min = i[3]
            if i[4] > self.max:
                self.max = i[4]
        mean = self.sum/self.pixels
        stddev = np.sqrt(self.sumSq/self.pixels - mean**2)

        t = time.perf_counter()
        timer = t - self.data[0][5]

        stats = "Sum: {sum} \nMean: {mean} \nMin: {min} \nMax: {max} \nStandard deviation: {stddev} \nSumSq: {sumSq} \nPixels: {pixels} \nTime taken: {t}"
        stats = stats.format(sum=self.sum, mean=mean, min=self.min, max=self.max, stddev=stddev, sumSq=self.sumSq, pixels=self.pixels, t=timer)

        # Write the final output to a file
        pickle.dump(stats, open("Statistics", "wb"))


        outs = self.outputs
        if len(outs) != 1:
            raise Exception("Only one output should have been added.")
        d = pickle.dumps([self.min, self.max, self.data[0][6]])
        outs[0].len = len(d)
        outs[0].write(d)
        
    def getInputArrays(self):
        """""
        Create the input array from all inputs received. Shape is
        (<#inputs>, <#elements>), where #elements is the length of the
        vector received from one input. 
        Format of embedded list: [sum, sumSq, pixels, hist, min, max, bins, startTime]
        """""
        ins = self.inputs
        if len(ins) < 1:
            raise Exception(
                'At least one input should have been added to %r' % self) 
        
        self.data = [pickle.loads(droputils.allDropContents(inp)) for inp in ins]


##
# \brief SplitHistApp\n
# \details App that splits data
# \par EAGLE_START
# \param gitrepo $(GIT_REPO)
# \param version $(PROJECT_VERSION)
# \param category PythonApp
# \param[in] param/appclass/CompDaF.src.daliuge_backend.Daliuge.SplitHistApp/String
#     \~English Application class\n
# \param[in] port/list
#     \~English Port receiving list of min, max, file
# \param[out] port/list
#     \~English Port outputting list to each respective split
# \par EAGLE_END
class SplitHistApp(BarrierAppDROP):
    
    compontent_meta = dlg_component('SplitHistApp', 'Split Histogram App',
                                    [dlg_batch_input('binary/*', [])],
                                    [dlg_batch_output('binary/*', [])],
                                    [dlg_streaming_input('binary/*')])

    def initialize(self, **kwargs):
        super(SplitHistApp, self).initialize(**kwargs)
        self.start = 0

    def run(self):
        data = pickle.loads(droputils.allDropContents(self.inputs[0]))
        self.min = data[0]
        self.max = data[1]
        file = data[2]

        t = time.perf_counter()
        try:
            with fits.open(file, memmap=True) as hdu:
                if "data" not in dir(hdu[0]):
                    raise Exception("Unexpected format in fits file.")
                self.s = hdu[0].data.shape[0]
                self.bins = int(max(2, math.sqrt(self.s * hdu[0].data.shape[1])))
            self.width = math.ceil(self.s / len(self.outputs))    
        except:
            raise Exception("Unable to load file.")

        for out in self.outputs:
            if (self.start + self.width) > self.s:
                d = pickle.dumps([self.start, self.s, self.min, self.max, self.bins, file, t])
            else:
                d = pickle.dumps([self.start, self.start + self.width, self.min, self.max, self.bins, file, t])
            out.len = len(d)
            out.write(d)
            self.start += self.width



##
# \brief ComputeHistApp\n
# \details Array Statistics App that takes in a np array and calculates statistics on it.
# \par EAGLE_START
# \param gitrepo $(GIT_REPO)
# \param version $(PROJECT_VERSION)
# \param category PythonApp
# \param[in] param/appclass/CompDaF.src.daliuge_backend.Daliuge.ComputeHistApp/String
#             \~English Application class\n
# \param[in] port/list
#             \~English Port receiving list of respective split
# \param[out] port/hist
#             \~English Port outputs list of histogram, num bins
# \par EAGLE_END
class ComputeHistApp(BarrierAppDROP):
    
    component_meta = dlg_component('ComputeHistApp', 'Compute Histogram App',
                                    [dlg_batch_input('binary/*', [])],
                                    [dlg_batch_output('binary/*', [])],
                                    [dlg_streaming_input('binary/*')])

    def initialize(self, **kwargs):
        super(ComputeHistApp, self).initialize(**kwargs)
        self.hist = None

    def run(self):
        inp = pickle.loads(droputils.allDropContents(self.inputs[0]))
        start = inp[0]
        end = inp[1]
        min = inp[2]
        max = inp[3]
        bins = inp[4]
        width = math.ceil((end-start)/4)
        file = inp[5]

        try:
            with fits.open(file, memmap=True) as hdu:
                if "data" not in dir(hdu[0]):
                    raise Exception("Unexpected format in fits file.")
                temp = start + width

                for i in range(4):
                    if temp > end:
                        temp = end
                    data = hdu[0].data[start:temp]
                    
                    if self.hist is None:
                        self.hist, b = np.histogram(data, bins, (min, max))
                    else:
                        h, b = np.histogram(data, bins, (min, max))
                        self.hist += h
                    
                    start = temp
                    temp += width
        except:
            raise Exception("Unable to load file.")

        outs = self.outputs

        d = pickle.dumps([self.hist, bins, inp[6]])
        outs[0].len = len(d)
        outs[0].write(d)



##
# \brief GatherHistApp\n
# \details GatherHistApp that receives list of results and compares/combines.
# \par EAGLE_START
# \param gitrepo $(GIT_REPO)
# \param version $(PROJECT_VERSION)
# \param category PythonApp
# \param[in] param/appclass/CompDaF.src.daliuge_backend.Daliuge.GatherHistApp/String
#     \~English Application class\n
# \param[in] port/hist
#     \~English Port receiving histograms to combine
# \param[out] port/string
#     \~English Port outputting histogram and number of bins
# \par EAGLE_END
class GatherHistApp(BarrierAppDROP):
    
    compontent_meta = dlg_component('GatherHistApp', 'Gather Histogram App',
                                    [dlg_batch_input('binary/*', [])],
                                    [dlg_batch_output('binary/*', [])],
                                    [dlg_streaming_input('binary/*')])

    def initialize(self, **kwargs):
        super(GatherHistApp, self).initialize(**kwargs)
        self.hist = None

    def run(self):
        # Set self.data to list of data from inputs
        self.getInputArrays()
        
        for i in self.data:
            try:
                self.hist += i[0]
            except:
                self.hist = i[0]
            
        t = time.perf_counter()
        timer = t - self.data[0][2]

        stats = "Time taken: {t} \nNumber of bins: {bins} \nHistogram: {hist}"
        stats = stats.format(t=timer, bins=self.data[0][1], hist=self.hist)

        self.outputs[0].len = len(str(stats).encode())
        self.outputs[0].write(str(stats).encode())
    
    def getInputArrays(self):
        """""
        Create the input array from all inputs received. Shape is
        (<#inputs>, <#elements>), where #elements is the length of the
        vector received from one input. 
        Format of embedded list: [sum, sumSq, pixels, hist, min, max, bins, startTime]
        """""
        ins = self.inputs
        if len(ins) < 1:
            raise Exception(
                'At least one input should have been added to %r' % self) 
        
        self.data = [pickle.loads(droputils.allDropContents(inp)) for inp in ins]