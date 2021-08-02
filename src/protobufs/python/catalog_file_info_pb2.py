# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: catalog_file_info.proto
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from src.protobuf import defs_pb2 as defs__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='catalog_file_info.proto',
  package='CARTA',
  syntax='proto3',
  serialized_options=None,
  create_key=_descriptor._internal_create_key,
  serialized_pb=b'\n\x17\x63\x61talog_file_info.proto\x12\x05\x43\x41RTA\x1a\ndefs.proto\"9\n\x16\x43\x61talogFileInfoRequest\x12\x11\n\tdirectory\x18\x01 \x01(\t\x12\x0c\n\x04name\x18\x02 \x01(\t\"\x8d\x01\n\x17\x43\x61talogFileInfoResponse\x12\x0f\n\x07success\x18\x01 \x01(\x08\x12\x0f\n\x07message\x18\x02 \x01(\t\x12)\n\tfile_info\x18\x03 \x01(\x0b\x32\x16.CARTA.CatalogFileInfo\x12%\n\x07headers\x18\x04 \x03(\x0b\x32\x14.CARTA.CatalogHeaderb\x06proto3'
  ,
  dependencies=[defs__pb2.DESCRIPTOR,])




_CATALOGFILEINFOREQUEST = _descriptor.Descriptor(
  name='CatalogFileInfoRequest',
  full_name='CARTA.CatalogFileInfoRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='directory', full_name='CARTA.CatalogFileInfoRequest.directory', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='name', full_name='CARTA.CatalogFileInfoRequest.name', index=1,
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
  serialized_start=46,
  serialized_end=103,
)


_CATALOGFILEINFORESPONSE = _descriptor.Descriptor(
  name='CatalogFileInfoResponse',
  full_name='CARTA.CatalogFileInfoResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='success', full_name='CARTA.CatalogFileInfoResponse.success', index=0,
      number=1, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='message', full_name='CARTA.CatalogFileInfoResponse.message', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='file_info', full_name='CARTA.CatalogFileInfoResponse.file_info', index=2,
      number=3, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='headers', full_name='CARTA.CatalogFileInfoResponse.headers', index=3,
      number=4, type=11, cpp_type=10, label=3,
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
  serialized_start=106,
  serialized_end=247,
)

_CATALOGFILEINFORESPONSE.fields_by_name['file_info'].message_type = defs__pb2._CATALOGFILEINFO
_CATALOGFILEINFORESPONSE.fields_by_name['headers'].message_type = defs__pb2._CATALOGHEADER
DESCRIPTOR.message_types_by_name['CatalogFileInfoRequest'] = _CATALOGFILEINFOREQUEST
DESCRIPTOR.message_types_by_name['CatalogFileInfoResponse'] = _CATALOGFILEINFORESPONSE
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

CatalogFileInfoRequest = _reflection.GeneratedProtocolMessageType('CatalogFileInfoRequest', (_message.Message,), {
  'DESCRIPTOR' : _CATALOGFILEINFOREQUEST,
  '__module__' : 'catalog_file_info_pb2'
  # @@protoc_insertion_point(class_scope:CARTA.CatalogFileInfoRequest)
  })
_sym_db.RegisterMessage(CatalogFileInfoRequest)

CatalogFileInfoResponse = _reflection.GeneratedProtocolMessageType('CatalogFileInfoResponse', (_message.Message,), {
  'DESCRIPTOR' : _CATALOGFILEINFORESPONSE,
  '__module__' : 'catalog_file_info_pb2'
  # @@protoc_insertion_point(class_scope:CARTA.CatalogFileInfoResponse)
  })
_sym_db.RegisterMessage(CatalogFileInfoResponse)


# @@protoc_insertion_point(module_scope)
