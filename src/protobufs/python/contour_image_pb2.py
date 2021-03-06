# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: contour_image.proto
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from protobufs.python import defs_pb2 as defs__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='contour_image.proto',
  package='CARTA',
  syntax='proto3',
  serialized_options=None,
  create_key=_descriptor._internal_create_key,
  serialized_pb=b'\n\x13\x63ontour_image.proto\x12\x05\x43\x41RTA\x1a\ndefs.proto\"\xc4\x01\n\x10\x43ontourImageData\x12\x0f\n\x07\x66ile_id\x18\x01 \x01(\x0f\x12\x19\n\x11reference_file_id\x18\x02 \x01(\x07\x12(\n\x0cimage_bounds\x18\x03 \x01(\x0b\x32\x12.CARTA.ImageBounds\x12\x0f\n\x07\x63hannel\x18\x04 \x01(\x0f\x12\x0e\n\x06stokes\x18\x05 \x01(\x0f\x12\'\n\x0c\x63ontour_sets\x18\x06 \x03(\x0b\x32\x11.CARTA.ContourSet\x12\x10\n\x08progress\x18\x07 \x01(\x01\"\x91\x01\n\nContourSet\x12\r\n\x05level\x18\x01 \x01(\x01\x12\x19\n\x11\x64\x65\x63imation_factor\x18\x02 \x01(\x05\x12\x17\n\x0fraw_coordinates\x18\x03 \x01(\x0c\x12\x19\n\x11raw_start_indices\x18\x04 \x01(\x0c\x12%\n\x1duncompressed_coordinates_size\x18\x05 \x01(\x05\x62\x06proto3'
  ,
  dependencies=[defs__pb2.DESCRIPTOR,])




_CONTOURIMAGEDATA = _descriptor.Descriptor(
  name='ContourImageData',
  full_name='CARTA.ContourImageData',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='file_id', full_name='CARTA.ContourImageData.file_id', index=0,
      number=1, type=15, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='reference_file_id', full_name='CARTA.ContourImageData.reference_file_id', index=1,
      number=2, type=7, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='image_bounds', full_name='CARTA.ContourImageData.image_bounds', index=2,
      number=3, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='channel', full_name='CARTA.ContourImageData.channel', index=3,
      number=4, type=15, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='stokes', full_name='CARTA.ContourImageData.stokes', index=4,
      number=5, type=15, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='contour_sets', full_name='CARTA.ContourImageData.contour_sets', index=5,
      number=6, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='progress', full_name='CARTA.ContourImageData.progress', index=6,
      number=7, type=1, cpp_type=5, label=1,
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
  serialized_start=43,
  serialized_end=239,
)


_CONTOURSET = _descriptor.Descriptor(
  name='ContourSet',
  full_name='CARTA.ContourSet',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='level', full_name='CARTA.ContourSet.level', index=0,
      number=1, type=1, cpp_type=5, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='decimation_factor', full_name='CARTA.ContourSet.decimation_factor', index=1,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='raw_coordinates', full_name='CARTA.ContourSet.raw_coordinates', index=2,
      number=3, type=12, cpp_type=9, label=1,
      has_default_value=False, default_value=b"",
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='raw_start_indices', full_name='CARTA.ContourSet.raw_start_indices', index=3,
      number=4, type=12, cpp_type=9, label=1,
      has_default_value=False, default_value=b"",
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='uncompressed_coordinates_size', full_name='CARTA.ContourSet.uncompressed_coordinates_size', index=4,
      number=5, type=5, cpp_type=1, label=1,
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
  serialized_start=242,
  serialized_end=387,
)

_CONTOURIMAGEDATA.fields_by_name['image_bounds'].message_type = defs__pb2._IMAGEBOUNDS
_CONTOURIMAGEDATA.fields_by_name['contour_sets'].message_type = _CONTOURSET
DESCRIPTOR.message_types_by_name['ContourImageData'] = _CONTOURIMAGEDATA
DESCRIPTOR.message_types_by_name['ContourSet'] = _CONTOURSET
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

ContourImageData = _reflection.GeneratedProtocolMessageType('ContourImageData', (_message.Message,), {
  'DESCRIPTOR' : _CONTOURIMAGEDATA,
  '__module__' : 'contour_image_pb2'
  # @@protoc_insertion_point(class_scope:CARTA.ContourImageData)
  })
_sym_db.RegisterMessage(ContourImageData)

ContourSet = _reflection.GeneratedProtocolMessageType('ContourSet', (_message.Message,), {
  'DESCRIPTOR' : _CONTOURSET,
  '__module__' : 'contour_image_pb2'
  # @@protoc_insertion_point(class_scope:CARTA.ContourSet)
  })
_sym_db.RegisterMessage(ContourSet)


# @@protoc_insertion_point(module_scope)
