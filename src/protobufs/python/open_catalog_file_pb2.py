# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: open_catalog_file.proto
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from protobufs.python import defs_pb2 as defs__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='open_catalog_file.proto',
  package='CARTA',
  syntax='proto3',
  serialized_options=None,
  create_key=_descriptor._internal_create_key,
  serialized_pb=b'\n\x17open_catalog_file.proto\x12\x05\x43\x41RTA\x1a\ndefs.proto\"^\n\x0fOpenCatalogFile\x12\x11\n\tdirectory\x18\x01 \x01(\t\x12\x0c\n\x04name\x18\x02 \x01(\t\x12\x0f\n\x07\x66ile_id\x18\x03 \x01(\x0f\x12\x19\n\x11preview_data_size\x18\x04 \x01(\x0f\"\xb5\x02\n\x12OpenCatalogFileAck\x12\x0f\n\x07success\x18\x01 \x01(\x08\x12\x0f\n\x07message\x18\x02 \x01(\t\x12\x0f\n\x07\x66ile_id\x18\x03 \x01(\x0f\x12)\n\tfile_info\x18\x04 \x01(\x0b\x32\x16.CARTA.CatalogFileInfo\x12\x11\n\tdata_size\x18\x05 \x01(\x0f\x12%\n\x07headers\x18\x06 \x03(\x0b\x32\x14.CARTA.CatalogHeader\x12@\n\x0cpreview_data\x18\x07 \x03(\x0b\x32*.CARTA.OpenCatalogFileAck.PreviewDataEntry\x1a\x45\n\x10PreviewDataEntry\x12\x0b\n\x03key\x18\x01 \x01(\x07\x12 \n\x05value\x18\x02 \x01(\x0b\x32\x11.CARTA.ColumnData:\x02\x38\x01\"#\n\x10\x43loseCatalogFile\x12\x0f\n\x07\x66ile_id\x18\x01 \x01(\x0f\x62\x06proto3'
  ,
  dependencies=[defs__pb2.DESCRIPTOR,])




_OPENCATALOGFILE = _descriptor.Descriptor(
  name='OpenCatalogFile',
  full_name='CARTA.OpenCatalogFile',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='directory', full_name='CARTA.OpenCatalogFile.directory', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='name', full_name='CARTA.OpenCatalogFile.name', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='file_id', full_name='CARTA.OpenCatalogFile.file_id', index=2,
      number=3, type=15, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='preview_data_size', full_name='CARTA.OpenCatalogFile.preview_data_size', index=3,
      number=4, type=15, cpp_type=1, label=1,
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
  serialized_start=46,
  serialized_end=140,
)


_OPENCATALOGFILEACK_PREVIEWDATAENTRY = _descriptor.Descriptor(
  name='PreviewDataEntry',
  full_name='CARTA.OpenCatalogFileAck.PreviewDataEntry',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='key', full_name='CARTA.OpenCatalogFileAck.PreviewDataEntry.key', index=0,
      number=1, type=7, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='value', full_name='CARTA.OpenCatalogFileAck.PreviewDataEntry.value', index=1,
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
  serialized_start=383,
  serialized_end=452,
)

_OPENCATALOGFILEACK = _descriptor.Descriptor(
  name='OpenCatalogFileAck',
  full_name='CARTA.OpenCatalogFileAck',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='success', full_name='CARTA.OpenCatalogFileAck.success', index=0,
      number=1, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='message', full_name='CARTA.OpenCatalogFileAck.message', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='file_id', full_name='CARTA.OpenCatalogFileAck.file_id', index=2,
      number=3, type=15, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='file_info', full_name='CARTA.OpenCatalogFileAck.file_info', index=3,
      number=4, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='data_size', full_name='CARTA.OpenCatalogFileAck.data_size', index=4,
      number=5, type=15, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='headers', full_name='CARTA.OpenCatalogFileAck.headers', index=5,
      number=6, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='preview_data', full_name='CARTA.OpenCatalogFileAck.preview_data', index=6,
      number=7, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[_OPENCATALOGFILEACK_PREVIEWDATAENTRY, ],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=143,
  serialized_end=452,
)


_CLOSECATALOGFILE = _descriptor.Descriptor(
  name='CloseCatalogFile',
  full_name='CARTA.CloseCatalogFile',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='file_id', full_name='CARTA.CloseCatalogFile.file_id', index=0,
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
  serialized_start=454,
  serialized_end=489,
)

_OPENCATALOGFILEACK_PREVIEWDATAENTRY.fields_by_name['value'].message_type = defs__pb2._COLUMNDATA
_OPENCATALOGFILEACK_PREVIEWDATAENTRY.containing_type = _OPENCATALOGFILEACK
_OPENCATALOGFILEACK.fields_by_name['file_info'].message_type = defs__pb2._CATALOGFILEINFO
_OPENCATALOGFILEACK.fields_by_name['headers'].message_type = defs__pb2._CATALOGHEADER
_OPENCATALOGFILEACK.fields_by_name['preview_data'].message_type = _OPENCATALOGFILEACK_PREVIEWDATAENTRY
DESCRIPTOR.message_types_by_name['OpenCatalogFile'] = _OPENCATALOGFILE
DESCRIPTOR.message_types_by_name['OpenCatalogFileAck'] = _OPENCATALOGFILEACK
DESCRIPTOR.message_types_by_name['CloseCatalogFile'] = _CLOSECATALOGFILE
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

OpenCatalogFile = _reflection.GeneratedProtocolMessageType('OpenCatalogFile', (_message.Message,), {
  'DESCRIPTOR' : _OPENCATALOGFILE,
  '__module__' : 'open_catalog_file_pb2'
  # @@protoc_insertion_point(class_scope:CARTA.OpenCatalogFile)
  })
_sym_db.RegisterMessage(OpenCatalogFile)

OpenCatalogFileAck = _reflection.GeneratedProtocolMessageType('OpenCatalogFileAck', (_message.Message,), {

  'PreviewDataEntry' : _reflection.GeneratedProtocolMessageType('PreviewDataEntry', (_message.Message,), {
    'DESCRIPTOR' : _OPENCATALOGFILEACK_PREVIEWDATAENTRY,
    '__module__' : 'open_catalog_file_pb2'
    # @@protoc_insertion_point(class_scope:CARTA.OpenCatalogFileAck.PreviewDataEntry)
    })
  ,
  'DESCRIPTOR' : _OPENCATALOGFILEACK,
  '__module__' : 'open_catalog_file_pb2'
  # @@protoc_insertion_point(class_scope:CARTA.OpenCatalogFileAck)
  })
_sym_db.RegisterMessage(OpenCatalogFileAck)
_sym_db.RegisterMessage(OpenCatalogFileAck.PreviewDataEntry)

CloseCatalogFile = _reflection.GeneratedProtocolMessageType('CloseCatalogFile', (_message.Message,), {
  'DESCRIPTOR' : _CLOSECATALOGFILE,
  '__module__' : 'open_catalog_file_pb2'
  # @@protoc_insertion_point(class_scope:CARTA.CloseCatalogFile)
  })
_sym_db.RegisterMessage(CloseCatalogFile)


_OPENCATALOGFILEACK_PREVIEWDATAENTRY._options = None
# @@protoc_insertion_point(module_scope)
