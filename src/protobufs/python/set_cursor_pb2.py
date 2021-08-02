# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: set_cursor.proto
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from src.protobuf import defs_pb2 as defs__pb2
from src.protobuf import region_requirements_pb2 as region__requirements__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='set_cursor.proto',
  package='CARTA',
  syntax='proto3',
  serialized_options=None,
  create_key=_descriptor._internal_create_key,
  serialized_pb=b'\n\x10set_cursor.proto\x12\x05\x43\x41RTA\x1a\ndefs.proto\x1a\x19region_requirements.proto\"v\n\tSetCursor\x12\x0f\n\x07\x66ile_id\x18\x01 \x01(\x0f\x12\x1b\n\x05point\x18\x02 \x01(\x0b\x32\x0c.CARTA.Point\x12;\n\x14spatial_requirements\x18\x03 \x01(\x0b\x32\x1d.CARTA.SetSpatialRequirementsb\x06proto3'
  ,
  dependencies=[defs__pb2.DESCRIPTOR,region__requirements__pb2.DESCRIPTOR,])




_SETCURSOR = _descriptor.Descriptor(
  name='SetCursor',
  full_name='CARTA.SetCursor',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='file_id', full_name='CARTA.SetCursor.file_id', index=0,
      number=1, type=15, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='point', full_name='CARTA.SetCursor.point', index=1,
      number=2, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='spatial_requirements', full_name='CARTA.SetCursor.spatial_requirements', index=2,
      number=3, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
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
  serialized_start=66,
  serialized_end=184,
)

_SETCURSOR.fields_by_name['point'].message_type = defs__pb2._POINT
_SETCURSOR.fields_by_name['spatial_requirements'].message_type = region__requirements__pb2._SETSPATIALREQUIREMENTS
DESCRIPTOR.message_types_by_name['SetCursor'] = _SETCURSOR
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

SetCursor = _reflection.GeneratedProtocolMessageType('SetCursor', (_message.Message,), {
  'DESCRIPTOR' : _SETCURSOR,
  '__module__' : 'set_cursor_pb2'
  # @@protoc_insertion_point(class_scope:CARTA.SetCursor)
  })
_sym_db.RegisterMessage(SetCursor)


# @@protoc_insertion_point(module_scope)
