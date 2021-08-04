# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: spectral_line_request.proto
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from protobufs.python import defs_pb2 as defs__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='spectral_line_request.proto',
  package='CARTA',
  syntax='proto3',
  serialized_options=None,
  create_key=_descriptor._internal_create_key,
  serialized_pb=b'\n\x1bspectral_line_request.proto\x12\x05\x43\x41RTA\x1a\ndefs.proto\"g\n\x13SpectralLineRequest\x12,\n\x0f\x66requency_range\x18\x01 \x01(\x0b\x32\x13.CARTA.DoubleBounds\x12\"\n\x1aline_intensity_lower_limit\x18\x02 \x01(\x01\"\x8d\x02\n\x14SpectralLineResponse\x12\x0f\n\x07success\x18\x01 \x01(\x08\x12\x0f\n\x07message\x18\x02 \x01(\t\x12\x11\n\tdata_size\x18\x03 \x01(\x0f\x12%\n\x07headers\x18\x04 \x03(\x0b\x32\x14.CARTA.CatalogHeader\x12M\n\x12spectral_line_data\x18\x05 \x03(\x0b\x32\x31.CARTA.SpectralLineResponse.SpectralLineDataEntry\x1aJ\n\x15SpectralLineDataEntry\x12\x0b\n\x03key\x18\x01 \x01(\x07\x12 \n\x05value\x18\x02 \x01(\x0b\x32\x11.CARTA.ColumnData:\x02\x38\x01\x62\x06proto3'
  ,
  dependencies=[defs__pb2.DESCRIPTOR,])




_SPECTRALLINEREQUEST = _descriptor.Descriptor(
  name='SpectralLineRequest',
  full_name='CARTA.SpectralLineRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='frequency_range', full_name='CARTA.SpectralLineRequest.frequency_range', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='line_intensity_lower_limit', full_name='CARTA.SpectralLineRequest.line_intensity_lower_limit', index=1,
      number=2, type=1, cpp_type=5, label=1,
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
  serialized_start=50,
  serialized_end=153,
)


_SPECTRALLINERESPONSE_SPECTRALLINEDATAENTRY = _descriptor.Descriptor(
  name='SpectralLineDataEntry',
  full_name='CARTA.SpectralLineResponse.SpectralLineDataEntry',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='key', full_name='CARTA.SpectralLineResponse.SpectralLineDataEntry.key', index=0,
      number=1, type=7, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='value', full_name='CARTA.SpectralLineResponse.SpectralLineDataEntry.value', index=1,
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
  serialized_start=351,
  serialized_end=425,
)

_SPECTRALLINERESPONSE = _descriptor.Descriptor(
  name='SpectralLineResponse',
  full_name='CARTA.SpectralLineResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='success', full_name='CARTA.SpectralLineResponse.success', index=0,
      number=1, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='message', full_name='CARTA.SpectralLineResponse.message', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='data_size', full_name='CARTA.SpectralLineResponse.data_size', index=2,
      number=3, type=15, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='headers', full_name='CARTA.SpectralLineResponse.headers', index=3,
      number=4, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='spectral_line_data', full_name='CARTA.SpectralLineResponse.spectral_line_data', index=4,
      number=5, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR,  create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[_SPECTRALLINERESPONSE_SPECTRALLINEDATAENTRY, ],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=156,
  serialized_end=425,
)

_SPECTRALLINEREQUEST.fields_by_name['frequency_range'].message_type = defs__pb2._DOUBLEBOUNDS
_SPECTRALLINERESPONSE_SPECTRALLINEDATAENTRY.fields_by_name['value'].message_type = defs__pb2._COLUMNDATA
_SPECTRALLINERESPONSE_SPECTRALLINEDATAENTRY.containing_type = _SPECTRALLINERESPONSE
_SPECTRALLINERESPONSE.fields_by_name['headers'].message_type = defs__pb2._CATALOGHEADER
_SPECTRALLINERESPONSE.fields_by_name['spectral_line_data'].message_type = _SPECTRALLINERESPONSE_SPECTRALLINEDATAENTRY
DESCRIPTOR.message_types_by_name['SpectralLineRequest'] = _SPECTRALLINEREQUEST
DESCRIPTOR.message_types_by_name['SpectralLineResponse'] = _SPECTRALLINERESPONSE
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

SpectralLineRequest = _reflection.GeneratedProtocolMessageType('SpectralLineRequest', (_message.Message,), {
  'DESCRIPTOR' : _SPECTRALLINEREQUEST,
  '__module__' : 'spectral_line_request_pb2'
  # @@protoc_insertion_point(class_scope:CARTA.SpectralLineRequest)
  })
_sym_db.RegisterMessage(SpectralLineRequest)

SpectralLineResponse = _reflection.GeneratedProtocolMessageType('SpectralLineResponse', (_message.Message,), {

  'SpectralLineDataEntry' : _reflection.GeneratedProtocolMessageType('SpectralLineDataEntry', (_message.Message,), {
    'DESCRIPTOR' : _SPECTRALLINERESPONSE_SPECTRALLINEDATAENTRY,
    '__module__' : 'spectral_line_request_pb2'
    # @@protoc_insertion_point(class_scope:CARTA.SpectralLineResponse.SpectralLineDataEntry)
    })
  ,
  'DESCRIPTOR' : _SPECTRALLINERESPONSE,
  '__module__' : 'spectral_line_request_pb2'
  # @@protoc_insertion_point(class_scope:CARTA.SpectralLineResponse)
  })
_sym_db.RegisterMessage(SpectralLineResponse)
_sym_db.RegisterMessage(SpectralLineResponse.SpectralLineDataEntry)


_SPECTRALLINERESPONSE_SPECTRALLINEDATAENTRY._options = None
# @@protoc_insertion_point(module_scope)
