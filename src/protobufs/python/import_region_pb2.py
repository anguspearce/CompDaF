# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: import_region.proto
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from protobufs.python import defs_pb2 as defs__pb2
from protobufs.python import enums_pb2 as enums__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='import_region.proto',
  package='CARTA',
  syntax='proto3',
  serialized_options=None,
  create_key=_descriptor._internal_create_key,
  serialized_pb=b'\n\x13import_region.proto\x12\x05\x43\x41RTA\x1a\ndefs.proto\x1a\x0b\x65nums.proto\"r\n\x0cImportRegion\x12\x10\n\x08group_id\x18\x01 \x01(\x0f\x12\x1d\n\x04type\x18\x02 \x01(\x0e\x32\x0f.CARTA.FileType\x12\x11\n\tdirectory\x18\x03 \x01(\t\x12\x0c\n\x04\x66ile\x18\x04 \x01(\t\x12\x10\n\x08\x63ontents\x18\x05 \x03(\t\"\xb6\x02\n\x0fImportRegionAck\x12\x0f\n\x07success\x18\x01 \x01(\x08\x12\x0f\n\x07message\x18\x02 \x01(\t\x12\x34\n\x07regions\x18\x03 \x03(\x0b\x32#.CARTA.ImportRegionAck.RegionsEntry\x12?\n\rregion_styles\x18\x04 \x03(\x0b\x32(.CARTA.ImportRegionAck.RegionStylesEntry\x1a\x41\n\x0cRegionsEntry\x12\x0b\n\x03key\x18\x01 \x01(\x0f\x12 \n\x05value\x18\x02 \x01(\x0b\x32\x11.CARTA.RegionInfo:\x02\x38\x01\x1aG\n\x11RegionStylesEntry\x12\x0b\n\x03key\x18\x01 \x01(\x0f\x12!\n\x05value\x18\x02 \x01(\x0b\x32\x12.CARTA.RegionStyle:\x02\x38\x01\x62\x06proto3'
  ,
  dependencies=[defs__pb2.DESCRIPTOR,enums__pb2.DESCRIPTOR,])




_IMPORTREGION = _descriptor.Descriptor(
  name='ImportRegion',
  full_name='CARTA.ImportRegion',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='group_id', full_name='CARTA.ImportRegion.group_id', index=0,
      number=1, type=15, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='type', full_name='CARTA.ImportRegion.type', index=1,
      number=2, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='directory', full_name='CARTA.ImportRegion.directory', index=2,
      number=3, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='file', full_name='CARTA.ImportRegion.file', index=3,
      number=4, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='contents', full_name='CARTA.ImportRegion.contents', index=4,
      number=5, type=9, cpp_type=9, label=3,
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
  serialized_start=55,
  serialized_end=169,
)


_IMPORTREGIONACK_REGIONSENTRY = _descriptor.Descriptor(
  name='RegionsEntry',
  full_name='CARTA.ImportRegionAck.RegionsEntry',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='key', full_name='CARTA.ImportRegionAck.RegionsEntry.key', index=0,
      number=1, type=15, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='value', full_name='CARTA.ImportRegionAck.RegionsEntry.value', index=1,
      number=2, type=11, cpp_type=10, label=1,
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
  serialized_options=b'8\001',
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=344,
  serialized_end=409,
)

_IMPORTREGIONACK_REGIONSTYLESENTRY = _descriptor.Descriptor(
  name='RegionStylesEntry',
  full_name='CARTA.ImportRegionAck.RegionStylesEntry',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='key', full_name='CARTA.ImportRegionAck.RegionStylesEntry.key', index=0,
      number=1, type=15, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='value', full_name='CARTA.ImportRegionAck.RegionStylesEntry.value', index=1,
      number=2, type=11, cpp_type=10, label=1,
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
  serialized_options=b'8\001',
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=411,
  serialized_end=482,
)

_IMPORTREGIONACK = _descriptor.Descriptor(
  name='ImportRegionAck',
  full_name='CARTA.ImportRegionAck',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='success', full_name='CARTA.ImportRegionAck.success', index=0,
      number=1, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='message', full_name='CARTA.ImportRegionAck.message', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='regions', full_name='CARTA.ImportRegionAck.regions', index=2,
      number=3, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='region_styles', full_name='CARTA.ImportRegionAck.region_styles', index=3,
      number=4, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[_IMPORTREGIONACK_REGIONSENTRY, _IMPORTREGIONACK_REGIONSTYLESENTRY, ],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=172,
  serialized_end=482,
)

_IMPORTREGION.fields_by_name['type'].enum_type = enums__pb2._FILETYPE
_IMPORTREGIONACK_REGIONSENTRY.fields_by_name['value'].message_type = defs__pb2._REGIONINFO
_IMPORTREGIONACK_REGIONSENTRY.containing_type = _IMPORTREGIONACK
_IMPORTREGIONACK_REGIONSTYLESENTRY.fields_by_name['value'].message_type = defs__pb2._REGIONSTYLE
_IMPORTREGIONACK_REGIONSTYLESENTRY.containing_type = _IMPORTREGIONACK
_IMPORTREGIONACK.fields_by_name['regions'].message_type = _IMPORTREGIONACK_REGIONSENTRY
_IMPORTREGIONACK.fields_by_name['region_styles'].message_type = _IMPORTREGIONACK_REGIONSTYLESENTRY
DESCRIPTOR.message_types_by_name['ImportRegion'] = _IMPORTREGION
DESCRIPTOR.message_types_by_name['ImportRegionAck'] = _IMPORTREGIONACK
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

ImportRegion = _reflection.GeneratedProtocolMessageType('ImportRegion', (_message.Message,), {
  'DESCRIPTOR' : _IMPORTREGION,
  '__module__' : 'import_region_pb2'
  # @@protoc_insertion_point(class_scope:CARTA.ImportRegion)
  })
_sym_db.RegisterMessage(ImportRegion)

ImportRegionAck = _reflection.GeneratedProtocolMessageType('ImportRegionAck', (_message.Message,), {

  'RegionsEntry' : _reflection.GeneratedProtocolMessageType('RegionsEntry', (_message.Message,), {
    'DESCRIPTOR' : _IMPORTREGIONACK_REGIONSENTRY,
    '__module__' : 'import_region_pb2'
    # @@protoc_insertion_point(class_scope:CARTA.ImportRegionAck.RegionsEntry)
    })
  ,

  'RegionStylesEntry' : _reflection.GeneratedProtocolMessageType('RegionStylesEntry', (_message.Message,), {
    'DESCRIPTOR' : _IMPORTREGIONACK_REGIONSTYLESENTRY,
    '__module__' : 'import_region_pb2'
    # @@protoc_insertion_point(class_scope:CARTA.ImportRegionAck.RegionStylesEntry)
    })
  ,
  'DESCRIPTOR' : _IMPORTREGIONACK,
  '__module__' : 'import_region_pb2'
  # @@protoc_insertion_point(class_scope:CARTA.ImportRegionAck)
  })
_sym_db.RegisterMessage(ImportRegionAck)
_sym_db.RegisterMessage(ImportRegionAck.RegionsEntry)
_sym_db.RegisterMessage(ImportRegionAck.RegionStylesEntry)


_IMPORTREGIONACK_REGIONSENTRY._options = None
_IMPORTREGIONACK_REGIONSTYLESENTRY._options = None
# @@protoc_insertion_point(module_scope)
