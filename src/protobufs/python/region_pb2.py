# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: region.proto
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from src.protobuf import defs_pb2 as defs__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='region.proto',
  package='CARTA',
  syntax='proto3',
  serialized_options=None,
  create_key=_descriptor._internal_create_key,
  serialized_pb=b'\n\x0cregion.proto\x12\x05\x43\x41RTA\x1a\ndefs.proto\"W\n\tSetRegion\x12\x0f\n\x07\x66ile_id\x18\x01 \x01(\x0f\x12\x11\n\tregion_id\x18\x02 \x01(\x0f\x12&\n\x0bregion_info\x18\x03 \x01(\x0b\x32\x11.CARTA.RegionInfo\"C\n\x0cSetRegionAck\x12\x0f\n\x07success\x18\x01 \x01(\x08\x12\x0f\n\x07message\x18\x02 \x01(\t\x12\x11\n\tregion_id\x18\x03 \x01(\x0f\"!\n\x0cRemoveRegion\x12\x11\n\tregion_id\x18\x01 \x01(\x0f\x62\x06proto3'
  ,
  dependencies=[defs__pb2.DESCRIPTOR,])




_SETREGION = _descriptor.Descriptor(
  name='SetRegion',
  full_name='CARTA.SetRegion',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='file_id', full_name='CARTA.SetRegion.file_id', index=0,
      number=1, type=15, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='region_id', full_name='CARTA.SetRegion.region_id', index=1,
      number=2, type=15, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='region_info', full_name='CARTA.SetRegion.region_info', index=2,
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
  serialized_start=35,
  serialized_end=122,
)


_SETREGIONACK = _descriptor.Descriptor(
  name='SetRegionAck',
  full_name='CARTA.SetRegionAck',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='success', full_name='CARTA.SetRegionAck.success', index=0,
      number=1, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='message', full_name='CARTA.SetRegionAck.message', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='region_id', full_name='CARTA.SetRegionAck.region_id', index=2,
      number=3, type=15, cpp_type=1, label=1,
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
  serialized_start=124,
  serialized_end=191,
)


_REMOVEREGION = _descriptor.Descriptor(
  name='RemoveRegion',
  full_name='CARTA.RemoveRegion',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='region_id', full_name='CARTA.RemoveRegion.region_id', index=0,
      number=1, type=15, cpp_type=1, label=1,
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
  serialized_start=193,
  serialized_end=226,
)

_SETREGION.fields_by_name['region_info'].message_type = defs__pb2._REGIONINFO
DESCRIPTOR.message_types_by_name['SetRegion'] = _SETREGION
DESCRIPTOR.message_types_by_name['SetRegionAck'] = _SETREGIONACK
DESCRIPTOR.message_types_by_name['RemoveRegion'] = _REMOVEREGION
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

SetRegion = _reflection.GeneratedProtocolMessageType('SetRegion', (_message.Message,), {
  'DESCRIPTOR' : _SETREGION,
  '__module__' : 'region_pb2'
  # @@protoc_insertion_point(class_scope:CARTA.SetRegion)
  })
_sym_db.RegisterMessage(SetRegion)

SetRegionAck = _reflection.GeneratedProtocolMessageType('SetRegionAck', (_message.Message,), {
  'DESCRIPTOR' : _SETREGIONACK,
  '__module__' : 'region_pb2'
  # @@protoc_insertion_point(class_scope:CARTA.SetRegionAck)
  })
_sym_db.RegisterMessage(SetRegionAck)

RemoveRegion = _reflection.GeneratedProtocolMessageType('RemoveRegion', (_message.Message,), {
  'DESCRIPTOR' : _REMOVEREGION,
  '__module__' : 'region_pb2'
  # @@protoc_insertion_point(class_scope:CARTA.RemoveRegion)
  })
_sym_db.RegisterMessage(RemoveRegion)


# @@protoc_insertion_point(module_scope)
