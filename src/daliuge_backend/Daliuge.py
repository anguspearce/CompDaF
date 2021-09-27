#!/usr/bin/env python3.8
# Daliuge
from sys import float_info
from dlg import droputils, utils
from dlg.ddap_protocol import AppDROPStates
from dlg.drop import BarrierAppDROP, BranchAppDrop, ContainerDROP, AppDROP
from dlg.meta import dlg_float_param, dlg_string_param
from dlg.meta import dlg_bool_param, dlg_int_param
from dlg.meta import dlg_component, dlg_batch_input
from dlg.meta import dlg_batch_output, dlg_streaming_input

import pickle
import numba as nb
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
# \details App that splits a FITS file into a range based on number of outputs
# \par EAGLE_START
# \param gitrepo $(GIT_REPO)
# \param version $(PROJECT_VERSION)
# \param category PythonApp
# \param[in] param/appclass/CompDaF.src.daliuge_backend.Daliuge.SplitStatsApp/String
#     \~English Application class\n
# \param[in] param/fileName/sample.fits/String
#     \~English Path to FITS file
# \param[in] param/ramSplit/4/Integer
#     \~English Split of data to work on at a time
# \param[out] port/range
#     \~English Port outputting the list containing respective splits
# \par EAGLE_END
class SplitStatsApp(BarrierAppDROP):
    
    compontent_meta = dlg_component('SplitStatsApp', 'Split Stats App',
                                    [dlg_batch_input('binary/*', [])],
                                    [dlg_batch_output('binary/*', [])],
                                    [dlg_streaming_input('binary/*')])

    # ramSplit is the number of splits each AppDROP will divide its range of data by
    ramSplit = dlg_int_param('ramSplit', 4) # NOTE: The variable name has to match the value of the param name!
    fileName = dlg_string_param('fileName','sample.fits') # NOTE: The variable name has to match the value of the param name!
    fileDir = "../testdata/" 

    def initialize(self, **kwargs):
        super(SplitStatsApp, self).initialize(**kwargs)
        self.file = os.path.normpath(self.fileDir + self.fileName)
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
                d = pickle.dumps([self.start, self.s, self.ramSplit, self.file, t])
            else:
                d = pickle.dumps([self.start, self.start + self.width, self.ramSplit, self.file, t])
            out.len = len(d)
            out.write(d)
            self.start += self.width


##
# \brief ComputeStatsApp\n
# \details App that computes various statistics over a section of data
# \par EAGLE_START
# \param gitrepo $(GIT_REPO)
# \param version $(PROJECT_VERSION)
# \param category PythonApp
# \param[in] param/appclass/CompDaF.src.daliuge_backend.Daliuge.ComputeStatsApp/String
#             \~English Application class\n
# \param[in] port/range
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
        self.min = float_info.max
        self.max = float_info.min

    def run(self):
        self.d = pickle.loads(droputils.allDropContents(self.inputs[0]))
        start = self.d[0]
        end = self.d[1]
        step = self.d[2]
        file = self.d[3]
        width = math.ceil((end-start)/step)

        try:
            with fits.open(file, memmap=True) as hdu:
                if "data" not in dir(hdu[0]):
                    raise Exception("Unexpected format in fits file.")
                temp = start + width

                for i in range(step):
                    # Ensure we don't overflow the range 
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

        stats = [self.sum, self.sumSq, self.pixels, self.min, self.max, self.d[4], file, step]
        stats = pickle.dumps(stats)

        outs = self.outputs

        outs[0].len = len(stats)
        outs[0].write(stats)


##
# \brief GatherStatsApp\n
# \details App that compares/combines statistics computed
# \par EAGLE_START
# \param gitrepo $(GIT_REPO)
# \param version $(PROJECT_VERSION)
# \param category PythonApp
# \param[in] param/appclass/CompDaF.src.daliuge_backend.Daliuge.GatherStatsApp/String
#     \~English Application class\n
# \param[in] port/stats
#     \~English Port receiving list of statistics to combine
# \param[out] port/minmax
#     \~English Port outputting list of min, max, file
# \param[out] port/statistics
#     \~English Port outputting calculated statistics
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
        self.min = float_info.max
        self.max = float_info.min
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

        stats = "File: {file} \nSum: {sum} \nMean: {mean} \nMin: {min} \nMax: {max} \nStandard deviation: {stddev} \nSumSq: {sumSq} \nPixels: {pixels} \nTime taken: {t}"
        stats = stats.format(file=self.data[0][6], sum=self.sum, mean=mean, min=self.min, max=self.max, stddev=stddev, sumSq=self.sumSq, pixels=self.pixels, t=timer)
        stats = stats.encode()

        dump = {"sum" : self.sum, "sumSq" : self.sumSq, "mean" : mean, "min" : self.min, "max" : self.max, "stddev" : stddev, "pixels" : self.pixels}
        # Write the final output to a file
        pickle.dump(dump, open("Statistics", "wb"))

        outs = self.outputs
        if len(outs) != 2:
            raise Exception("Only two outputs should have been added.")
        
        d = pickle.dumps([self.min, self.max, self.data[0][6], self.data[0][7]])
        outs[0].len = len(d)
        outs[0].write(d)

        outs[1].len = len(stats)
        outs[1].write(stats)
        
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
# \details App that splits a FITS file into sections based on number of outputs
# \par EAGLE_START
# \param gitrepo $(GIT_REPO)
# \param version $(PROJECT_VERSION)
# \param category PythonApp
# \param[in] param/appclass/CompDaF.src.daliuge_backend.Daliuge.SplitHistApp/String
#     \~English Application class\n
# \param[in] port/minmax
#     \~English Port receiving list of min, max, file
# \param[out] port/range
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
            self.binWidth = (self.max - self.min)/self.bins
        except:
            raise Exception("Unable to load file.")

        for out in self.outputs:
            if (self.start + self.width) > self.s:
                d = pickle.dumps([self.start, self.s, self.min, self.bins, self.binWidth, file, t, data[3]])
            else:
                d = pickle.dumps([self.start, self.start + self.width, self.min, self.bins, self.binWidth, file, t, data[3]])
            out.len = len(d)
            out.write(d)
            self.start += self.width



##
# \brief ComputeHistApp\n
# \details App that computes the histogram for a specific range of a FITS file 
# \par EAGLE_START
# \param gitrepo $(GIT_REPO)
# \param version $(PROJECT_VERSION)
# \param category PythonApp
# \param[in] param/appclass/CompDaF.src.daliuge_backend.Daliuge.ComputeHistApp/String
#             \~English Application class\n
# \param[in] port/range
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
        bins = inp[3]
        binWidth = inp[4]
        file = inp[5]
        step = inp[7]
        width = math.ceil((end-start)/step)

        self.hist = np.zeros(bins, dtype=np.int32)

        try:
            with fits.open(file, memmap=True) as hdu:
                if "data" not in dir(hdu[0]):
                    raise Exception("Unexpected format in fits file.")
                temp = start + width

                for i in range(step):
                    if temp > end:
                        temp = end
                    data = hdu[0].data[start:temp]
                    
                    if data.dtype.byteorder == '>':
                        self.getHisto(data.newbyteorder().byteswap(inplace=True), min, binWidth, self.hist)
                    else:
                        self.getHisto(data, min, binWidth, self.hist)
                    
                    start = temp
                    temp += width 
        except:
            raise Exception("Unable to load file.")

        outs = self.outputs

        d = pickle.dumps([self.hist, bins, binWidth, inp[6]])
        outs[0].len = len(d)
        outs[0].write(d)
    
    @staticmethod
    @nb.njit(parallel=False, fastmath=True, nogil=True, cache=True)
    def getHisto(data, min, binWidth, hist):
        for i in range(data.shape[0]):
            for j in range(data.shape[1]):
                scaledVal = (data[i,j] - min) / binWidth
                index = math.floor(scaledVal)
                hist[index] += 1
        return hist



##
# \brief GatherHistApp\n
# \details App that receives histograms from each compute node
# \par EAGLE_START
# \param gitrepo $(GIT_REPO)
# \param version $(PROJECT_VERSION)
# \param category PythonApp
# \param[in] param/appclass/CompDaF.src.daliuge_backend.Daliuge.GatherHistApp/String
#     \~English Application class\n
# \param[in] port/hist
#     \~English Port receiving histograms to combine
# \param[out] port/histogram
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
        # Set self.data to list of data from inputs [histogram, numBins, startTime]
        self.getInputArrays()
        
        # Combine all the histograms that were gathered into one
        for i in self.data:
            try:
                self.hist = np.add(self.hist, i[0])
            except:
                self.hist = i[0]
        
        # Stopping the histogram timer
        t = time.perf_counter()
        timer = t - self.data[0][3] # Any input ports 3rd index will have the same time


        # Combining and pickling the data to a file
        dump = {"hist" : self.hist, "numBins" : self.data[0][1], "binWidth" : self.data[0][2]}
        pickle.dump(dump, open("Histogram", "wb"))

        # Formatting results into a string (human-readable)
        stats = "Histogram: {hist} \nNumber of bins: {bins} \nTime taken: {t}"
        stats = stats.format(hist=self.hist, bins=self.data[0][1], binWidth = self.data[0][2], t=timer)
        # Sending the string output to the output port
        self.outputs[0].len = len(stats.encode())
        self.outputs[0].write(stats.encode())
    
    def getInputArrays(self):
        """""
        Create the input array from all inputs received. Shape is
        (<#inputs>, <#elements>), where #elements is the length of the
        vector received from one input. 
        Format of embedded list: [histogram, numBins, startTime]
        """""
        ins = self.inputs
        if len(ins) < 1:
            raise Exception(
                'At least one input should have been added to %r' % self) 
        
        self.data = [pickle.loads(droputils.allDropContents(inp)) for inp in ins]