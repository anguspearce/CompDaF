// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: catalog_list.proto

#include "catalog_list.pb.h"

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

namespace protobuf_defs_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_defs_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_DirectoryInfo;
extern PROTOBUF_INTERNAL_EXPORT_protobuf_defs_2eproto ::google::protobuf::internal::SCCInfo<1> scc_info_CatalogFileInfo;
}  // namespace protobuf_defs_2eproto
namespace CARTA {
class CatalogListRequestDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<CatalogListRequest>
      _instance;
} _CatalogListRequest_default_instance_;
class CatalogListResponseDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<CatalogListResponse>
      _instance;
} _CatalogListResponse_default_instance_;
}  // namespace CARTA
namespace protobuf_catalog_5flist_2eproto {
static void InitDefaultsCatalogListRequest() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::CARTA::_CatalogListRequest_default_instance_;
    new (ptr) ::CARTA::CatalogListRequest();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::CARTA::CatalogListRequest::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_CatalogListRequest =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsCatalogListRequest}, {}};

static void InitDefaultsCatalogListResponse() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::CARTA::_CatalogListResponse_default_instance_;
    new (ptr) ::CARTA::CatalogListResponse();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::CARTA::CatalogListResponse::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<2> scc_info_CatalogListResponse =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 2, InitDefaultsCatalogListResponse}, {
      &protobuf_defs_2eproto::scc_info_CatalogFileInfo.base,
      &protobuf_defs_2eproto::scc_info_DirectoryInfo.base,}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_CatalogListRequest.base);
  ::google::protobuf::internal::InitSCC(&scc_info_CatalogListResponse.base);
}

::google::protobuf::Metadata file_level_metadata[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::CARTA::CatalogListRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::CARTA::CatalogListRequest, directory_),
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::CARTA::CatalogListResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::CARTA::CatalogListResponse, success_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::CARTA::CatalogListResponse, message_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::CARTA::CatalogListResponse, directory_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::CARTA::CatalogListResponse, parent_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::CARTA::CatalogListResponse, files_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::CARTA::CatalogListResponse, subdirectories_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::CARTA::CatalogListResponse, cancel_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::CARTA::CatalogListRequest)},
  { 6, -1, sizeof(::CARTA::CatalogListResponse)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::CARTA::_CatalogListRequest_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::CARTA::_CatalogListResponse_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "catalog_list.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\022catalog_list.proto\022\005CARTA\032\ndefs.proto\""
      "\'\n\022CatalogListRequest\022\021\n\tdirectory\030\001 \001(\t"
      "\"\277\001\n\023CatalogListResponse\022\017\n\007success\030\001 \001("
      "\010\022\017\n\007message\030\002 \001(\t\022\021\n\tdirectory\030\003 \001(\t\022\016\n"
      "\006parent\030\004 \001(\t\022%\n\005files\030\005 \003(\0132\026.CARTA.Cat"
      "alogFileInfo\022,\n\016subdirectories\030\006 \003(\0132\024.C"
      "ARTA.DirectoryInfo\022\016\n\006cancel\030\007 \001(\010b\006prot"
      "o3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 282);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "catalog_list.proto", &protobuf_RegisterTypes);
  ::protobuf_defs_2eproto::AddDescriptors();
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
}  // namespace protobuf_catalog_5flist_2eproto
namespace CARTA {

// ===================================================================

void CatalogListRequest::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int CatalogListRequest::kDirectoryFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

CatalogListRequest::CatalogListRequest()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_catalog_5flist_2eproto::scc_info_CatalogListRequest.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:CARTA.CatalogListRequest)
}
CatalogListRequest::CatalogListRequest(const CatalogListRequest& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  directory_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.directory().size() > 0) {
    directory_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.directory_);
  }
  // @@protoc_insertion_point(copy_constructor:CARTA.CatalogListRequest)
}

void CatalogListRequest::SharedCtor() {
  directory_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

CatalogListRequest::~CatalogListRequest() {
  // @@protoc_insertion_point(destructor:CARTA.CatalogListRequest)
  SharedDtor();
}

void CatalogListRequest::SharedDtor() {
  directory_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void CatalogListRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* CatalogListRequest::descriptor() {
  ::protobuf_catalog_5flist_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_catalog_5flist_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const CatalogListRequest& CatalogListRequest::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_catalog_5flist_2eproto::scc_info_CatalogListRequest.base);
  return *internal_default_instance();
}


void CatalogListRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:CARTA.CatalogListRequest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  directory_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  _internal_metadata_.Clear();
}

bool CatalogListRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:CARTA.CatalogListRequest)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string directory = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_directory()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->directory().data(), static_cast<int>(this->directory().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "CARTA.CatalogListRequest.directory"));
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
  // @@protoc_insertion_point(parse_success:CARTA.CatalogListRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:CARTA.CatalogListRequest)
  return false;
#undef DO_
}

void CatalogListRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:CARTA.CatalogListRequest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string directory = 1;
  if (this->directory().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->directory().data(), static_cast<int>(this->directory().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "CARTA.CatalogListRequest.directory");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->directory(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:CARTA.CatalogListRequest)
}

::google::protobuf::uint8* CatalogListRequest::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:CARTA.CatalogListRequest)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string directory = 1;
  if (this->directory().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->directory().data(), static_cast<int>(this->directory().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "CARTA.CatalogListRequest.directory");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->directory(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:CARTA.CatalogListRequest)
  return target;
}

size_t CatalogListRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:CARTA.CatalogListRequest)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string directory = 1;
  if (this->directory().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->directory());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void CatalogListRequest::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:CARTA.CatalogListRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const CatalogListRequest* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const CatalogListRequest>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:CARTA.CatalogListRequest)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:CARTA.CatalogListRequest)
    MergeFrom(*source);
  }
}

void CatalogListRequest::MergeFrom(const CatalogListRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:CARTA.CatalogListRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.directory().size() > 0) {

    directory_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.directory_);
  }
}

void CatalogListRequest::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:CARTA.CatalogListRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CatalogListRequest::CopyFrom(const CatalogListRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:CARTA.CatalogListRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CatalogListRequest::IsInitialized() const {
  return true;
}

void CatalogListRequest::Swap(CatalogListRequest* other) {
  if (other == this) return;
  InternalSwap(other);
}
void CatalogListRequest::InternalSwap(CatalogListRequest* other) {
  using std::swap;
  directory_.Swap(&other->directory_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata CatalogListRequest::GetMetadata() const {
  protobuf_catalog_5flist_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_catalog_5flist_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void CatalogListResponse::InitAsDefaultInstance() {
}
void CatalogListResponse::clear_files() {
  files_.Clear();
}
void CatalogListResponse::clear_subdirectories() {
  subdirectories_.Clear();
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int CatalogListResponse::kSuccessFieldNumber;
const int CatalogListResponse::kMessageFieldNumber;
const int CatalogListResponse::kDirectoryFieldNumber;
const int CatalogListResponse::kParentFieldNumber;
const int CatalogListResponse::kFilesFieldNumber;
const int CatalogListResponse::kSubdirectoriesFieldNumber;
const int CatalogListResponse::kCancelFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

CatalogListResponse::CatalogListResponse()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_catalog_5flist_2eproto::scc_info_CatalogListResponse.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:CARTA.CatalogListResponse)
}
CatalogListResponse::CatalogListResponse(const CatalogListResponse& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      files_(from.files_),
      subdirectories_(from.subdirectories_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  message_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.message().size() > 0) {
    message_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.message_);
  }
  directory_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.directory().size() > 0) {
    directory_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.directory_);
  }
  parent_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.parent().size() > 0) {
    parent_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.parent_);
  }
  ::memcpy(&success_, &from.success_,
    static_cast<size_t>(reinterpret_cast<char*>(&cancel_) -
    reinterpret_cast<char*>(&success_)) + sizeof(cancel_));
  // @@protoc_insertion_point(copy_constructor:CARTA.CatalogListResponse)
}

void CatalogListResponse::SharedCtor() {
  message_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  directory_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  parent_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&success_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&cancel_) -
      reinterpret_cast<char*>(&success_)) + sizeof(cancel_));
}

CatalogListResponse::~CatalogListResponse() {
  // @@protoc_insertion_point(destructor:CARTA.CatalogListResponse)
  SharedDtor();
}

void CatalogListResponse::SharedDtor() {
  message_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  directory_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  parent_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void CatalogListResponse::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* CatalogListResponse::descriptor() {
  ::protobuf_catalog_5flist_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_catalog_5flist_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const CatalogListResponse& CatalogListResponse::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_catalog_5flist_2eproto::scc_info_CatalogListResponse.base);
  return *internal_default_instance();
}


void CatalogListResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:CARTA.CatalogListResponse)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  files_.Clear();
  subdirectories_.Clear();
  message_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  directory_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  parent_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&success_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&cancel_) -
      reinterpret_cast<char*>(&success_)) + sizeof(cancel_));
  _internal_metadata_.Clear();
}

bool CatalogListResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:CARTA.CatalogListResponse)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // bool success = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &success_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string message = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u /* 18 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_message()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->message().data(), static_cast<int>(this->message().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "CARTA.CatalogListResponse.message"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string directory = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_directory()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->directory().data(), static_cast<int>(this->directory().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "CARTA.CatalogListResponse.directory"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string parent = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(34u /* 34 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_parent()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->parent().data(), static_cast<int>(this->parent().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "CARTA.CatalogListResponse.parent"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated .CARTA.CatalogFileInfo files = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(42u /* 42 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
                input, add_files()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated .CARTA.DirectoryInfo subdirectories = 6;
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(50u /* 50 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
                input, add_subdirectories()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bool cancel = 7;
      case 7: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(56u /* 56 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &cancel_)));
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
  // @@protoc_insertion_point(parse_success:CARTA.CatalogListResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:CARTA.CatalogListResponse)
  return false;
#undef DO_
}

void CatalogListResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:CARTA.CatalogListResponse)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bool success = 1;
  if (this->success() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(1, this->success(), output);
  }

  // string message = 2;
  if (this->message().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->message().data(), static_cast<int>(this->message().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "CARTA.CatalogListResponse.message");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->message(), output);
  }

  // string directory = 3;
  if (this->directory().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->directory().data(), static_cast<int>(this->directory().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "CARTA.CatalogListResponse.directory");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->directory(), output);
  }

  // string parent = 4;
  if (this->parent().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->parent().data(), static_cast<int>(this->parent().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "CARTA.CatalogListResponse.parent");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      4, this->parent(), output);
  }

  // repeated .CARTA.CatalogFileInfo files = 5;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->files_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5,
      this->files(static_cast<int>(i)),
      output);
  }

  // repeated .CARTA.DirectoryInfo subdirectories = 6;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->subdirectories_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      6,
      this->subdirectories(static_cast<int>(i)),
      output);
  }

  // bool cancel = 7;
  if (this->cancel() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(7, this->cancel(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:CARTA.CatalogListResponse)
}

::google::protobuf::uint8* CatalogListResponse::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:CARTA.CatalogListResponse)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // bool success = 1;
  if (this->success() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(1, this->success(), target);
  }

  // string message = 2;
  if (this->message().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->message().data(), static_cast<int>(this->message().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "CARTA.CatalogListResponse.message");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->message(), target);
  }

  // string directory = 3;
  if (this->directory().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->directory().data(), static_cast<int>(this->directory().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "CARTA.CatalogListResponse.directory");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->directory(), target);
  }

  // string parent = 4;
  if (this->parent().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->parent().data(), static_cast<int>(this->parent().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "CARTA.CatalogListResponse.parent");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        4, this->parent(), target);
  }

  // repeated .CARTA.CatalogFileInfo files = 5;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->files_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        5, this->files(static_cast<int>(i)), deterministic, target);
  }

  // repeated .CARTA.DirectoryInfo subdirectories = 6;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->subdirectories_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        6, this->subdirectories(static_cast<int>(i)), deterministic, target);
  }

  // bool cancel = 7;
  if (this->cancel() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(7, this->cancel(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:CARTA.CatalogListResponse)
  return target;
}

size_t CatalogListResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:CARTA.CatalogListResponse)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated .CARTA.CatalogFileInfo files = 5;
  {
    unsigned int count = static_cast<unsigned int>(this->files_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->files(static_cast<int>(i)));
    }
  }

  // repeated .CARTA.DirectoryInfo subdirectories = 6;
  {
    unsigned int count = static_cast<unsigned int>(this->subdirectories_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->subdirectories(static_cast<int>(i)));
    }
  }

  // string message = 2;
  if (this->message().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->message());
  }

  // string directory = 3;
  if (this->directory().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->directory());
  }

  // string parent = 4;
  if (this->parent().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->parent());
  }

  // bool success = 1;
  if (this->success() != 0) {
    total_size += 1 + 1;
  }

  // bool cancel = 7;
  if (this->cancel() != 0) {
    total_size += 1 + 1;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void CatalogListResponse::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:CARTA.CatalogListResponse)
  GOOGLE_DCHECK_NE(&from, this);
  const CatalogListResponse* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const CatalogListResponse>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:CARTA.CatalogListResponse)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:CARTA.CatalogListResponse)
    MergeFrom(*source);
  }
}

void CatalogListResponse::MergeFrom(const CatalogListResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:CARTA.CatalogListResponse)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  files_.MergeFrom(from.files_);
  subdirectories_.MergeFrom(from.subdirectories_);
  if (from.message().size() > 0) {

    message_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.message_);
  }
  if (from.directory().size() > 0) {

    directory_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.directory_);
  }
  if (from.parent().size() > 0) {

    parent_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.parent_);
  }
  if (from.success() != 0) {
    set_success(from.success());
  }
  if (from.cancel() != 0) {
    set_cancel(from.cancel());
  }
}

void CatalogListResponse::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:CARTA.CatalogListResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CatalogListResponse::CopyFrom(const CatalogListResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:CARTA.CatalogListResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CatalogListResponse::IsInitialized() const {
  return true;
}

void CatalogListResponse::Swap(CatalogListResponse* other) {
  if (other == this) return;
  InternalSwap(other);
}
void CatalogListResponse::InternalSwap(CatalogListResponse* other) {
  using std::swap;
  CastToBase(&files_)->InternalSwap(CastToBase(&other->files_));
  CastToBase(&subdirectories_)->InternalSwap(CastToBase(&other->subdirectories_));
  message_.Swap(&other->message_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  directory_.Swap(&other->directory_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  parent_.Swap(&other->parent_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(success_, other->success_);
  swap(cancel_, other->cancel_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata CatalogListResponse::GetMetadata() const {
  protobuf_catalog_5flist_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_catalog_5flist_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace CARTA
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::CARTA::CatalogListRequest* Arena::CreateMaybeMessage< ::CARTA::CatalogListRequest >(Arena* arena) {
  return Arena::CreateInternal< ::CARTA::CatalogListRequest >(arena);
}
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::CARTA::CatalogListResponse* Arena::CreateMaybeMessage< ::CARTA::CatalogListResponse >(Arena* arena) {
  return Arena::CreateInternal< ::CARTA::CatalogListResponse >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
