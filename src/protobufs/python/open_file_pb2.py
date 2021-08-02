# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: open_file.proto
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from src.protobuf import defs_pb2 as defs__pb2
from src.protobuf import enums_pb2 as enums__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='open_file.proto',
  package='CARTA',
  syntax='proto3',
  serialized_options=None,
  create_key=_descriptor._internal_create_key,
  serialized_pb=b'\n\x0fopen_file.proto\x12\x05\x43\x41RTA\x1a\ndefs.proto\x1a\x0b\x65nums.proto\"q\n\x08OpenFile\x12\x11\n\tdirectory\x18\x01 \x01(\t\x12\x0c\n\x04\x66ile\x18\x02 \x01(\t\x12\x0b\n\x03hdu\x18\x03 \x01(\t\x12\x0f\n\x07\x66ile_id\x18\x04 \x01(\x0f\x12&\n\x0brender_mode\x18\x05 \x01(\x0e\x32\x11.CARTA.RenderMode\"\xb5\x01\n\x0bOpenFileAck\x12\x0f\n\x07success\x18\x01 \x01(\x08\x12\x0f\n\x07\x66ile_id\x18\x02 \x01(\x0f\x12\x0f\n\x07message\x18\x03 \x01(\t\x12\"\n\tfile_info\x18\x04 \x01(\x0b\x32\x0f.CARTA.FileInfo\x12\x33\n\x12\x66ile_info_extended\x18\x05 \x01(\x0b\x32\x17.CARTA.FileInfoExtended\x12\x1a\n\x12\x66ile_feature_flags\x18\x06 \x01(\x07\x62\x06proto3'
  ,
  dependencies=[defs__pb2.DESCRIPTOR,enums__pb2.DESCRIPTOR,])




_OPENFILE = _descriptor.Descriptor(
  name='OpenFile',
  full_name='CARTA.OpenFile',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='directory', full_name='CARTA.OpenFile.directory', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='file', full_name='CARTA.OpenFile.file', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='hdu', full_name='CARTA.OpenFile.hdu', index=2,
      number=3, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='file_id', full_name='CARTA.OpenFile.file_id', index=3,
      number=4, type=15, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='render_mode', full_name='CARTA.OpenFile.render_mode', index=4,
      number=5, type=14, cpp_type=8, label=1,
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
  serialized_start=51,
  serialized_end=164,
)


_OPENFILEACK = _descriptor.Descriptor(
  name='OpenFileAck',
  full_name='CARTA.OpenFileAck',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='success', full_name='CARTA.OpenFileAck.success', index=0,
      number=1, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='file_id', full_name='CARTA.OpenFileAck.file_id', index=1,
      number=2, type=15, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='message', full_name='CARTA.OpenFileAck.message', index=2,
      number=3, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='file_info', full_name='CARTA.OpenFileAck.file_info', index=3,
      number=4, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='file_info_extended', full_name='CARTA.OpenFileAck.file_info_extended', index=4,
      number=5, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='file_feature_flags', full_name='CARTA.OpenFileAck.file_feature_flags', index=5,
      number=6, type=7, cpp_type=3, label=1,
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
  serialized_start=167,
  serialized_end=348,
)

_OPENFILE.fields_by_name['render_mode'].enum_type = enums__pb2._RENDERMODE
_OPENFILEACK.fields_by_name['file_info'].message_type = defs__pb2._FILEINFO
_OPENFILEACK.fields_by_name['file_info_extended'].message_type = defs__pb2._FILEINFOEXTENDED
DESCRIPTOR.message_types_by_name['OpenFile'] = _OPENFILE
DESCRIPTOR.message_types_by_name['OpenFileAck'] = _OPENFILEACK
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

OpenFile = _reflection.GeneratedProtocolMessageType('OpenFile', (_message.Message,), {
  'DESCRIPTOR' : _OPENFILE,
  '__module__' : 'open_file_pb2'
  # @@protoc_insertion_point(class_scope:CARTA.OpenFile)
  })
_sym_db.RegisterMessage(OpenFile)

OpenFileAck = _reflection.GeneratedProtocolMessageType('OpenFileAck', (_message.Message,), {
  'DESCRIPTOR' : _OPENFILEACK,
  '__module__' : 'open_file_pb2'
  # @@protoc_insertion_point(class_scope:CARTA.OpenFileAck)
  })
_sym_db.RegisterMessage(OpenFileAck)


# @@protoc_insertion_point(module_scope)
