# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: region_histogram.proto
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from src.protobuf import defs_pb2 as defs__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='region_histogram.proto',
  package='CARTA',
  syntax='proto3',
  serialized_options=None,
  create_key=_descriptor._internal_create_key,
  serialized_pb=b'\n\x16region_histogram.proto\x12\x05\x43\x41RTA\x1a\ndefs.proto\"\x81\x01\n\x13RegionHistogramData\x12\x0f\n\x07\x66ile_id\x18\x01 \x01(\x0f\x12\x11\n\tregion_id\x18\x02 \x01(\x0f\x12\x0e\n\x06stokes\x18\x03 \x01(\x0f\x12$\n\nhistograms\x18\x04 \x03(\x0b\x32\x10.CARTA.Histogram\x12\x10\n\x08progress\x18\x05 \x01(\x02\x62\x06proto3'
  ,
  dependencies=[defs__pb2.DESCRIPTOR,])




_REGIONHISTOGRAMDATA = _descriptor.Descriptor(
  name='RegionHistogramData',
  full_name='CARTA.RegionHistogramData',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='file_id', full_name='CARTA.RegionHistogramData.file_id', index=0,
      number=1, type=15, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='region_id', full_name='CARTA.RegionHistogramData.region_id', index=1,
      number=2, type=15, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='stokes', full_name='CARTA.RegionHistogramData.stokes', index=2,
      number=3, type=15, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='histograms', full_name='CARTA.RegionHistogramData.histograms', index=3,
      number=4, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='progress', full_name='CARTA.RegionHistogramData.progress', index=4,
      number=5, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=46,
  serialized_end=175,
)

_REGIONHISTOGRAMDATA.fields_by_name['histograms'].message_type = defs__pb2._HISTOGRAM
DESCRIPTOR.message_types_by_name['RegionHistogramData'] = _REGIONHISTOGRAMDATA
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

RegionHistogramData = _reflection.GeneratedProtocolMessageType('RegionHistogramData', (_message.Message,), {
  'DESCRIPTOR' : _REGIONHISTOGRAMDATA,
  '__module__' : 'region_histogram_pb2'
  # @@protoc_insertion_point(class_scope:CARTA.RegionHistogramData)
  })
_sym_db.RegisterMessage(RegionHistogramData)


# @@protoc_insertion_point(module_scope)
