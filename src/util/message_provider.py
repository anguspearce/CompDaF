# ***************************************************************************************
#    Title: message_provider.py
#    Author: Dylan Fouche
#    Date: 09/08/2021
#    Code version: 1.0
#    Availability: https://github.com/DylanFouche/CADaFloP.git
#
# **************************************************************************************

import uuid
import numpy as np

from protobufs.python import defs_pb2
from protobufs.python import enums_pb2
from protobufs.python import register_viewer_pb2
from protobufs.python import file_info_pb2
from protobufs.python import open_file_pb2
from protobufs.python import region_requirements_pb2
from protobufs.python import region_histogram_pb2
from protobufs.python import region_stats_pb2


STATS_TYPES = [enums_pb2.StatsType.Sum,
               enums_pb2.StatsType.Mean,
               enums_pb2.StatsType.Sigma,
               enums_pb2.StatsType.Min,
               enums_pb2.StatsType.Max]


def construct_register_viewer():
    """Construct a REGISTER_VIEWER message.

    :return: a tuple (message, message type)

    """
    message_type = enums_pb2.EventType.REGISTER_VIEWER
    message = register_viewer_pb2.RegisterViewer()
    message.session_id = np.uint32(
        uuid.uuid4().int % np.iinfo(np.uint32()).max)
    return (message, message_type)


def construct_register_viewer_ack(client_session_id):
    """Construct a REGISTER_VIEWER_ACK message.

    :param client_session_id: the id to use in the ack message
    :return: a tuple (message, message type)

    """
    message_type = enums_pb2.EventType.REGISTER_VIEWER_ACK
    message = register_viewer_pb2.RegisterViewerAck()
    message.session_id = client_session_id
    message.success = True
    return (message, message_type)

def construct_file_info_request(directory,file):
    """Construct a FILE_INFO_REQUEST message.

    :return: a tuple (message, message type)

    """
    message_type = enums_pb2.EventType.FILE_INFO_REQUEST
    message = file_info_pb2.FileInfoRequest()
    message.file = file
    message.directory = directory
    return (message, message_type)

def construct_file_info_response(fileInfo):
    """Construct a FILE_INFO_REQUEST message.

    :return: a tuple (message, message type)

    """
    message_type = enums_pb2.EventType.FILE_INFO_RESPONSE
    message = file_info_pb2.FileInfoResponse()
    message.file_info.name = fileInfo[0]
    message.file_info.size = fileInfo[1]
    message.file_info.type = enums_pb2.FITS
    message.success = True

    return (message, message_type)

def construct_open_file(directory, file):
    """Construct an OPEN_FILE message.

    :param file: the name of the file to open
    :param directory: the path to the file to open
    :return: a tuple (message, message type)

    """
    message_type = enums_pb2.EventType.OPEN_FILE
    message = open_file_pb2.OpenFile()
    message.file = file
    message.directory = directory
    message.file_id = 1
    return (message, message_type)


def construct_open_file_ack():
    """Construct an OPEN_FILE_ACK message.

    :return: a tuple (message, message type)

    """
    message_type = enums_pb2.EventType.OPEN_FILE_ACK
    message = open_file_pb2.OpenFileAck()
    message.success = True
    return (message, message_type)


def construct_set_histogram_requirements():
    """Construct a SET_HISTOGRAM_REQUIREMENTS message.

    :param num_bins:  the number of bins for the histogram
    :return: a tuple (message, message type)

    """
    message_type = enums_pb2.EventType.SET_HISTOGRAM_REQUIREMENTS
    message = region_requirements_pb2.SetHistogramRequirements()
    message.file_id = 1
    message.region_id = -1
    histogram_config = region_requirements_pb2.SetHistogramRequirements.HistogramConfig()
    histogram_config.channel = -1
    histogram_config.num_bins = -1
    message.histograms.append(histogram_config)
    return (message, message_type)


def construct_region_histogram_data(num_bins, bins, binWidth, mean, std_dev):
    """Construct a REGION_HISTOGRAM_DATA message.

    :param num_bins: the number of bins for the histogram
    :param bins: the bin values for the histogram
    :param mean: the mean of the histogram
    :param std_dev: the standard deviation of the histogram
    :return: a tuple (message, message type)

    """
    message_type = enums_pb2.EventType.REGION_HISTOGRAM_DATA
    message = region_histogram_pb2.RegionHistogramData()
    message.file_id = 1
    message.region_id = -1
    message.progress = 1
    histogram = defs_pb2.Histogram()
    histogram.num_bins = num_bins if num_bins is not None else -1
    histogram.bins.extend(bins)
    histogram.mean = mean
    histogram.std_dev = std_dev
    histogram.first_bin_center = -1
    histogram.bin_width = binWidth
    message.histograms.append(histogram)
    return (message, message_type)


def construct_set_stats_requirements():
    """Construct a SET_STATS_REQUIREMETNS message.

    :return: a tuple (message, message type)

    """
    message_type = enums_pb2.EventType.SET_STATS_REQUIREMENTS
    message = region_requirements_pb2.SetStatsRequirements()
    message.file_id = 1
    message.region_id = -1
    for stat in STATS_TYPES:
        message.stats.append(stat)
    return (message, message_type)


def construct_region_stats_data(stats):
    """Construct a REGION_STATS_DATA message.

    :param stats: the statistics tuple
    :return: a tuple (message, message type)

    """
    message_type = enums_pb2.EventType.REGION_STATS_DATA
    message = region_stats_pb2.RegionStatsData()
    message.file_id = 1
    message.region_id = -1
    for i in range(len(stats)):
        stat_value = defs_pb2.StatisticsValue()
        stat_value.stats_type = STATS_TYPES[i]
        stat_value.value = stats[i]
        message.statistics.append(stat_value)
    return (message, message_type)
