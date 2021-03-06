# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: contour.proto
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from protobufs.python import enums_pb2 as enums__pb2
from protobufs.python import defs_pb2 as defs__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='contour.proto',
  package='CARTA',
  syntax='proto3',
  serialized_options=None,
  create_key=_descriptor._internal_create_key,
  serialized_pb=b'\n\rcontour.proto\x12\x05\x43\x41RTA\x1a\x0b\x65nums.proto\x1a\ndefs.proto\"\x96\x02\n\x14SetContourParameters\x12\x0f\n\x07\x66ile_id\x18\x01 \x01(\x07\x12\x19\n\x11reference_file_id\x18\x02 \x01(\x07\x12(\n\x0cimage_bounds\x18\x03 \x01(\x0b\x32\x12.CARTA.ImageBounds\x12\x0e\n\x06levels\x18\x04 \x03(\x01\x12,\n\x0esmoothing_mode\x18\x05 \x01(\x0e\x32\x14.CARTA.SmoothingMode\x12\x18\n\x10smoothing_factor\x18\x06 \x01(\x05\x12\x19\n\x11\x64\x65\x63imation_factor\x18\x07 \x01(\x05\x12\x19\n\x11\x63ompression_level\x18\x08 \x01(\x05\x12\x1a\n\x12\x63ontour_chunk_size\x18\t \x01(\x05\x62\x06proto3'
  ,
  dependencies=[enums__pb2.DESCRIPTOR,defs__pb2.DESCRIPTOR,])




_SETCONTOURPARAMETERS = _descriptor.Descriptor(
  name='SetContourParameters',
  full_name='CARTA.SetContourParameters',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='file_id', full_name='CARTA.SetContourParameters.file_id', index=0,
      number=1, type=7, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='reference_file_id', full_name='CARTA.SetContourParameters.reference_file_id', index=1,
      number=2, type=7, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='image_bounds', full_name='CARTA.SetContourParameters.image_bounds', index=2,
      number=3, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='levels', full_name='CARTA.SetContourParameters.levels', index=3,
      number=4, type=1, cpp_type=5, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='smoothing_mode', full_name='CARTA.SetContourParameters.smoothing_mode', index=4,
      number=5, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='smoothing_factor', full_name='CARTA.SetContourParameters.smoothing_factor', index=5,
      number=6, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='decimation_factor', full_name='CARTA.SetContourParameters.decimation_factor', index=6,
      number=7, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='compression_level', full_name='CARTA.SetContourParameters.compression_level', index=7,
      number=8, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='contour_chunk_size', full_name='CARTA.SetContourParameters.contour_chunk_size', index=8,
      number=9, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
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
  serialized_start=50,
  serialized_end=328,
)

_SETCONTOURPARAMETERS.fields_by_name['image_bounds'].message_type = defs__pb2._IMAGEBOUNDS
_SETCONTOURPARAMETERS.fields_by_name['smoothing_mode'].enum_type = enums__pb2._SMOOTHINGMODE
DESCRIPTOR.message_types_by_name['SetContourParameters'] = _SETCONTOURPARAMETERS
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

SetContourParameters = _reflection.GeneratedProtocolMessageType('SetContourParameters', (_message.Message,), {
  'DESCRIPTOR' : _SETCONTOURPARAMETERS,
  '__module__' : 'contour_pb2'
  # @@protoc_insertion_point(class_scope:CARTA.SetContourParameters)
  })
_sym_db.RegisterMessage(SetContourParameters)


# @@protoc_insertion_point(module_scope)
