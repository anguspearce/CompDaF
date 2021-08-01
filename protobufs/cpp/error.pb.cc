// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: error.proto

#include "error.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace CARTA {
class ErrorDataDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<ErrorData>
      _instance;
} _ErrorData_default_instance_;
}  // namespace CARTA
namespace protobuf_error_2eproto {
static void InitDefaultsErrorData() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::CARTA::_ErrorData_default_instance_;
    new (ptr) ::CARTA::ErrorData();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::CARTA::ErrorData::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_ErrorData =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsErrorData}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_ErrorData.base);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::CARTA::ErrorData, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::CARTA::ErrorData, severity_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::CARTA::ErrorData, tags_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::CARTA::ErrorData, message_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::CARTA::ErrorData, data_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::CARTA::ErrorData)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::CARTA::_ErrorData_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "error.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\013error.proto\022\005CARTA\032\013enums.proto\"`\n\tErr"
      "orData\022&\n\010severity\030\001 \001(\0162\024.CARTA.ErrorSe"
      "verity\022\014\n\004tags\030\002 \003(\t\022\017\n\007message\030\003 \001(\t\022\014\n"
      "\004data\030\004 \001(\tb\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 139);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "error.proto", &protobuf_RegisterTypes);
  ::protobuf_enums_2eproto::AddDescriptors();
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_error_2eproto
namespace CARTA {

// ===================================================================

void ErrorData::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ErrorData::kSeverityFieldNumber;
const int ErrorData::kTagsFieldNumber;
const int ErrorData::kMessageFieldNumber;
const int ErrorData::kDataFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ErrorData::ErrorData()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_error_2eproto::scc_info_ErrorData.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:CARTA.ErrorData)
}
ErrorData::ErrorData(const ErrorData& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      tags_(from.tags_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  message_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.message().size() > 0) {
    message_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.message_);
  }
  data_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.data().size() > 0) {
    data_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.data_);
  }
  severity_ = from.severity_;
  // @@protoc_insertion_point(copy_constructor:CARTA.ErrorData)
}

void ErrorData::SharedCtor() {
  message_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  data_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  severity_ = 0;
}

ErrorData::~ErrorData() {
  // @@protoc_insertion_point(destructor:CARTA.ErrorData)
  SharedDtor();
}

void ErrorData::SharedDtor() {
  message_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  data_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void ErrorData::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* ErrorData::descriptor() {
  ::protobuf_error_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_error_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const ErrorData& ErrorData::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_error_2eproto::scc_info_ErrorData.base);
  return *internal_default_instance();
}


void ErrorData::Clear() {
// @@protoc_insertion_point(message_clear_start:CARTA.ErrorData)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  tags_.Clear();
  message_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  data_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  severity_ = 0;
  _internal_metadata_.Clear();
}

bool ErrorData::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:CARTA.ErrorData)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // .CARTA.ErrorSeverity severity = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_severity(static_cast< ::CARTA::ErrorSeverity >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated string tags = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_tags()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->tags(this->tags_size() - 1).data(),
            static_cast<int>(this->tags(this->tags_size() - 1).length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "CARTA.ErrorData.tags"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string message = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_message()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->message().data(), static_cast<int>(this->message().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "CARTA.ErrorData.message"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string data = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(34u /* 34 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_data()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->data().data(), static_cast<int>(this->data().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "CARTA.ErrorData.data"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:CARTA.ErrorData)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:CARTA.ErrorData)
  return false;
#undef DO_
}

void ErrorData::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:CARTA.ErrorData)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .CARTA.ErrorSeverity severity = 1;
  if (this->severity() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->severity(), output);
  }

  // repeated string tags = 2;
  for (int i = 0, n = this->tags_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->tags(i).data(), static_cast<int>(this->tags(i).length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "CARTA.ErrorData.tags");
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->tags(i), output);
  }

  // string message = 3;
  if (this->message().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->message().data(), static_cast<int>(this->message().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "CARTA.ErrorData.message");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->message(), output);
  }

  // string data = 4;
  if (this->data().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->data().data(), static_cast<int>(this->data().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "CARTA.ErrorData.data");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->data(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:CARTA.ErrorData)
}

::google::protobuf::uint8* ErrorData::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:CARTA.ErrorData)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .CARTA.ErrorSeverity severity = 1;
  if (this->severity() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->severity(), target);
  }

  // repeated string tags = 2;
  for (int i = 0, n = this->tags_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->tags(i).data(), static_cast<int>(this->tags(i).length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "CARTA.ErrorData.tags");
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(2, this->tags(i), target);
  }

  // string message = 3;
  if (this->message().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->message().data(), static_cast<int>(this->message().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "CARTA.ErrorData.message");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->message(), target);
  }

  // string data = 4;
  if (this->data().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->data().data(), static_cast<int>(this->data().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "CARTA.ErrorData.data");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->data(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:CARTA.ErrorData)
  return target;
}

size_t ErrorData::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:CARTA.ErrorData)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated string tags = 2;
  total_size += 1 *
      ::google::protobuf::internal::FromIntSize(this->tags_size());
  for (int i = 0, n = this->tags_size(); i < n; i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->tags(i));
  }

  // string message = 3;
  if (this->message().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->message());
  }

  // string data = 4;
  if (this->data().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->data());
  }

  // .CARTA.ErrorSeverity severity = 1;
  if (this->severity() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->severity());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void ErrorData::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:CARTA.ErrorData)
  GOOGLE_DCHECK_NE(&from, this);
  const ErrorData* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const ErrorData>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:CARTA.ErrorData)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:CARTA.ErrorData)
    MergeFrom(*source);
  }
}

void ErrorData::MergeFrom(const ErrorData& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:CARTA.ErrorData)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  tags_.MergeFrom(from.tags_);
  if (from.message().size() > 0) {

    message_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.message_);
  }
  if (from.data().size() > 0) {

    data_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.data_);
  }
  if (from.severity() != 0) {
    set_severity(from.severity());
  }
}

void ErrorData::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:CARTA.ErrorData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ErrorData::CopyFrom(const ErrorData& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:CARTA.ErrorData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ErrorData::IsInitialized() const {
  return true;
}

void ErrorData::Swap(ErrorData* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ErrorData::InternalSwap(ErrorData* other) {
  using std::swap;
  tags_.InternalSwap(CastToBase(&other->tags_));
  message_.Swap(&other->message_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  data_.Swap(&other->data_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(severity_, other->severity_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata ErrorData::GetMetadata() const {
  protobuf_error_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_error_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace CARTA
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::CARTA::ErrorData* Arena::CreateMaybeMessage< ::CARTA::ErrorData >(Arena* arena) {
  return Arena::CreateInternal< ::CARTA::ErrorData >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
