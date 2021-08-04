# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: save_file.proto
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from protobufs.python import enums_pb2 as enums__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='save_file.proto',
  package='CARTA',
  syntax='proto3',
  serialized_options=None,
  create_key=_descriptor._internal_create_key,
  serialized_pb=b'\n\x0fsave_file.proto\x12\x05\x43\x41RTA\x1a\x0b\x65nums.proto\"\x7f\n\x08SaveFile\x12\x0f\n\x07\x66ile_id\x18\x01 \x01(\x0f\x12\x1d\n\x15output_file_directory\x18\x02 \x01(\t\x12\x18\n\x10output_file_name\x18\x03 \x01(\t\x12)\n\x10output_file_type\x18\x04 \x01(\x0e\x32\x0f.CARTA.FileType\"@\n\x0bSaveFileAck\x12\x0f\n\x07\x66ile_id\x18\x01 \x01(\x0f\x12\x0f\n\x07success\x18\x02 \x01(\x08\x12\x0f\n\x07message\x18\x03 \x01(\tb\x06proto3'
  ,
  dependencies=[enums__pb2.DESCRIPTOR,])




_SAVEFILE = _descriptor.Descriptor(
  name='SaveFile',
  full_name='CARTA.SaveFile',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='file_id', full_name='CARTA.SaveFile.file_id', index=0,
      number=1, type=15, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='output_file_directory', full_name='CARTA.SaveFile.output_file_directory', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='output_file_name', full_name='CARTA.SaveFile.output_file_name', index=2,
      number=3, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='output_file_type', full_name='CARTA.SaveFile.output_file_type', index=3,
      number=4, type=14, cpp_type=8, label=1,
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
  serialized_start=39,
  serialized_end=166,
)


_SAVEFILEACK = _descriptor.Descriptor(
  name='SaveFileAck',
  full_name='CARTA.SaveFileAck',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='file_id', full_name='CARTA.SaveFileAck.file_id', index=0,
      number=1, type=15, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='success', full_name='CARTA.SaveFileAck.success', index=1,
      number=2, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='message', full_name='CARTA.SaveFileAck.message', index=2,
      number=3, type=9, cpp_type=9, label=1,
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
  serialized_start=168,
  serialized_end=232,
)

_SAVEFILE.fields_by_name['output_file_type'].enum_type = enums__pb2._FILETYPE
DESCRIPTOR.message_types_by_name['SaveFile'] = _SAVEFILE
DESCRIPTOR.message_types_by_name['SaveFileAck'] = _SAVEFILEACK
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

SaveFile = _reflection.GeneratedProtocolMessageType('SaveFile', (_message.Message,), {
  'DESCRIPTOR' : _SAVEFILE,
  '__module__' : 'save_file_pb2'
  # @@protoc_insertion_point(class_scope:CARTA.SaveFile)
  })
_sym_db.RegisterMessage(SaveFile)

SaveFileAck = _reflection.GeneratedProtocolMessageType('SaveFileAck', (_message.Message,), {
  'DESCRIPTOR' : _SAVEFILEACK,
  '__module__' : 'save_file_pb2'
  # @@protoc_insertion_point(class_scope:CARTA.SaveFileAck)
  })
_sym_db.RegisterMessage(SaveFileAck)


# @@protoc_insertion_point(module_scope)
