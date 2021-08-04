# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: region_file_info.proto
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from protobufs.python import defs_pb2 as defs__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='region_file_info.proto',
  package='CARTA',
  syntax='proto3',
  serialized_options=None,
  create_key=_descriptor._internal_create_key,
  serialized_pb=b'\n\x16region_file_info.proto\x12\x05\x43\x41RTA\x1a\ndefs.proto\"8\n\x15RegionFileInfoRequest\x12\x11\n\tdirectory\x18\x01 \x01(\t\x12\x0c\n\x04\x66ile\x18\x02 \x01(\t\"p\n\x16RegionFileInfoResponse\x12\x0f\n\x07success\x18\x01 \x01(\x08\x12\x0f\n\x07message\x18\x02 \x01(\t\x12\"\n\tfile_info\x18\x03 \x01(\x0b\x32\x0f.CARTA.FileInfo\x12\x10\n\x08\x63ontents\x18\x04 \x03(\tb\x06proto3'
  ,
  dependencies=[defs__pb2.DESCRIPTOR,])




_REGIONFILEINFOREQUEST = _descriptor.Descriptor(
  name='RegionFileInfoRequest',
  full_name='CARTA.RegionFileInfoRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='directory', full_name='CARTA.RegionFileInfoRequest.directory', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='file', full_name='CARTA.RegionFileInfoRequest.file', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
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
  serialized_start=45,
  serialized_end=101,
)


_REGIONFILEINFORESPONSE = _descriptor.Descriptor(
  name='RegionFileInfoResponse',
  full_name='CARTA.RegionFileInfoResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='success', full_name='CARTA.RegionFileInfoResponse.success', index=0,
      number=1, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='message', full_name='CARTA.RegionFileInfoResponse.message', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='file_info', full_name='CARTA.RegionFileInfoResponse.file_info', index=2,
      number=3, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='contents', full_name='CARTA.RegionFileInfoResponse.contents', index=3,
      number=4, type=9, cpp_type=9, label=3,
      has_default_value=False, default_value=[],
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
  serialized_start=103,
  serialized_end=215,
)

_REGIONFILEINFORESPONSE.fields_by_name['file_info'].message_type = defs__pb2._FILEINFO
DESCRIPTOR.message_types_by_name['RegionFileInfoRequest'] = _REGIONFILEINFOREQUEST
DESCRIPTOR.message_types_by_name['RegionFileInfoResponse'] = _REGIONFILEINFORESPONSE
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

RegionFileInfoRequest = _reflection.GeneratedProtocolMessageType('RegionFileInfoRequest', (_message.Message,), {
  'DESCRIPTOR' : _REGIONFILEINFOREQUEST,
  '__module__' : 'region_file_info_pb2'
  # @@protoc_insertion_point(class_scope:CARTA.RegionFileInfoRequest)
  })
_sym_db.RegisterMessage(RegionFileInfoRequest)

RegionFileInfoResponse = _reflection.GeneratedProtocolMessageType('RegionFileInfoResponse', (_message.Message,), {
  'DESCRIPTOR' : _REGIONFILEINFORESPONSE,
  '__module__' : 'region_file_info_pb2'
  # @@protoc_insertion_point(class_scope:CARTA.RegionFileInfoResponse)
  })
_sym_db.RegisterMessage(RegionFileInfoResponse)


# @@protoc_insertion_point(module_scope)
