// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: region_list.proto

#ifndef PROTOBUF_INCLUDED_region_5flist_2eproto
#define PROTOBUF_INCLUDED_region_5flist_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "defs.pb.h"
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_region_5flist_2eproto 

namespace protobuf_region_5flist_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_region_5flist_2eproto
namespace CARTA {
class RegionListRequest;
class RegionListRequestDefaultTypeInternal;
extern RegionListRequestDefaultTypeInternal _RegionListRequest_default_instance_;
class RegionListResponse;
class RegionListResponseDefaultTypeInternal;
extern RegionListResponseDefaultTypeInternal _RegionListResponse_default_instance_;
}  // namespace CARTA
namespace google {
namespace protobuf {
template<> ::CARTA::RegionListRequest* Arena::CreateMaybeMessage<::CARTA::RegionListRequest>(Arena*);
template<> ::CARTA::RegionListResponse* Arena::CreateMaybeMessage<::CARTA::RegionListResponse>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace CARTA {

// ===================================================================

class RegionListRequest : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:CARTA.RegionListRequest) */ {
 public:
  RegionListRequest();
  virtual ~RegionListRequest();

  RegionListRequest(const RegionListRequest& from);

  inline RegionListRequest& operator=(const RegionListRequest& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  RegionListRequest(RegionListRequest&& from) noexcept
    : RegionListRequest() {
    *this = ::std::move(from);
  }

  inline RegionListRequest& operator=(RegionListRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const RegionListRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const RegionListRequest* internal_default_instance() {
    return reinterpret_cast<const RegionListRequest*>(
               &_RegionListRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(RegionListRequest* other);
  friend void swap(RegionListRequest& a, RegionListRequest& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline RegionListRequest* New() const final {
    return CreateMaybeMessage<RegionListRequest>(NULL);
  }

  RegionListRequest* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<RegionListRequest>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const RegionListRequest& from);
  void MergeFrom(const RegionListRequest& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(RegionListRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string directory = 1;
  void clear_directory();
  static const int kDirectoryFieldNumber = 1;
  const ::std::string& directory() const;
  void set_directory(const ::std::string& value);
  #if LANG_CXX11
  void set_directory(::std::string&& value);
  #endif
  void set_directory(const char* value);
  void set_directory(const char* value, size_t size);
  ::std::string* mutable_directory();
  ::std::string* release_directory();
  void set_allocated_directory(::std::string* directory);

  // @@protoc_insertion_point(class_scope:CARTA.RegionListRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr directory_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_region_5flist_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class RegionListResponse : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:CARTA.RegionListResponse) */ {
 public:
  RegionListResponse();
  virtual ~RegionListResponse();

  RegionListResponse(const RegionListResponse& from);

  inline RegionListResponse& operator=(const RegionListResponse& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  RegionListResponse(RegionListResponse&& from) noexcept
    : RegionListResponse() {
    *this = ::std::move(from);
  }

  inline RegionListResponse& operator=(RegionListResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const RegionListResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const RegionListResponse* internal_default_instance() {
    return reinterpret_cast<const RegionListResponse*>(
               &_RegionListResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(RegionListResponse* other);
  friend void swap(RegionListResponse& a, RegionListResponse& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline RegionListResponse* New() const final {
    return CreateMaybeMessage<RegionListResponse>(NULL);
  }

  RegionListResponse* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<RegionListResponse>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const RegionListResponse& from);
  void MergeFrom(const RegionListResponse& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(RegionListResponse* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .CARTA.FileInfo files = 5;
  int files_size() const;
  void clear_files();
  static const int kFilesFieldNumber = 5;
  ::CARTA::FileInfo* mutable_files(int index);
  ::google::protobuf::RepeatedPtrField< ::CARTA::FileInfo >*
      mutable_files();
  const ::CARTA::FileInfo& files(int index) const;
  ::CARTA::FileInfo* add_files();
  const ::google::protobuf::RepeatedPtrField< ::CARTA::FileInfo >&
      files() const;

  // repeated .CARTA.DirectoryInfo subdirectories = 6;
  int subdirectories_size() const;
  void clear_subdirectories();
  static const int kSubdirectoriesFieldNumber = 6;
  ::CARTA::DirectoryInfo* mutable_subdirectories(int index);
  ::google::protobuf::RepeatedPtrField< ::CARTA::DirectoryInfo >*
      mutable_subdirectories();
  const ::CARTA::DirectoryInfo& subdirectories(int index) const;
  ::CARTA::DirectoryInfo* add_subdirectories();
  const ::google::protobuf::RepeatedPtrField< ::CARTA::DirectoryInfo >&
      subdirectories() const;

  // string message = 2;
  void clear_message();
  static const int kMessageFieldNumber = 2;
  const ::std::string& message() const;
  void set_message(const ::std::string& value);
  #if LANG_CXX11
  void set_message(::std::string&& value);
  #endif
  void set_message(const char* value);
  void set_message(const char* value, size_t size);
  ::std::string* mutable_message();
  ::std::string* release_message();
  void set_allocated_message(::std::string* message);

  // string directory = 3;
  void clear_directory();
  static const int kDirectoryFieldNumber = 3;
  const ::std::string& directory() const;
  void set_directory(const ::std::string& value);
  #if LANG_CXX11
  void set_directory(::std::string&& value);
  #endif
  void set_directory(const char* value);
  void set_directory(const char* value, size_t size);
  ::std::string* mutable_directory();
  ::std::string* release_directory();
  void set_allocated_directory(::std::string* directory);

  // string parent = 4;
  void clear_parent();
  static const int kParentFieldNumber = 4;
  const ::std::string& parent() const;
  void set_parent(const ::std::string& value);
  #if LANG_CXX11
  void set_parent(::std::string&& value);
  #endif
  void set_parent(const char* value);
  void set_parent(const char* value, size_t size);
  ::std::string* mutable_parent();
  ::std::string* release_parent();
  void set_allocated_parent(::std::string* parent);

  // bool success = 1;
  void clear_success();
  static const int kSuccessFieldNumber = 1;
  bool success() const;
  void set_success(bool value);

  // bool cancel = 7;
  void clear_cancel();
  static const int kCancelFieldNumber = 7;
  bool cancel() const;
  void set_cancel(bool value);

  // @@protoc_insertion_point(class_scope:CARTA.RegionListResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::CARTA::FileInfo > files_;
  ::google::protobuf::RepeatedPtrField< ::CARTA::DirectoryInfo > subdirectories_;
  ::google::protobuf::internal::ArenaStringPtr message_;
  ::google::protobuf::internal::ArenaStringPtr directory_;
  ::google::protobuf::internal::ArenaStringPtr parent_;
  bool success_;
  bool cancel_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_region_5flist_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// RegionListRequest

// string directory = 1;
inline void RegionListRequest::clear_directory() {
  directory_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& RegionListRequest::directory() const {
  // @@protoc_insertion_point(field_get:CARTA.RegionListRequest.directory)
  return directory_.GetNoArena();
}
inline void RegionListRequest::set_directory(const ::std::string& value) {
  
  directory_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:CARTA.RegionListRequest.directory)
}
#if LANG_CXX11
inline void RegionListRequest::set_directory(::std::string&& value) {
  
  directory_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:CARTA.RegionListRequest.directory)
}
#endif
inline void RegionListRequest::set_directory(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  directory_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:CARTA.RegionListRequest.directory)
}
inline void RegionListRequest::set_directory(const char* value, size_t size) {
  
  directory_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:CARTA.RegionListRequest.directory)
}
inline ::std::string* RegionListRequest::mutable_directory() {
  
  // @@protoc_insertion_point(field_mutable:CARTA.RegionListRequest.directory)
  return directory_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* RegionListRequest::release_directory() {
  // @@protoc_insertion_point(field_release:CARTA.RegionListRequest.directory)
  
  return directory_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void RegionListRequest::set_allocated_directory(::std::string* directory) {
  if (directory != NULL) {
    
  } else {
    
  }
  directory_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), directory);
  // @@protoc_insertion_point(field_set_allocated:CARTA.RegionListRequest.directory)
}

// -------------------------------------------------------------------

// RegionListResponse

// bool success = 1;
inline void RegionListResponse::clear_success() {
  success_ = false;
}
inline bool RegionListResponse::success() const {
  // @@protoc_insertion_point(field_get:CARTA.RegionListResponse.success)
  return success_;
}
inline void RegionListResponse::set_success(bool value) {
  
  success_ = value;
  // @@protoc_insertion_point(field_set:CARTA.RegionListResponse.success)
}

// string message = 2;
inline void RegionListResponse::clear_message() {
  message_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& RegionListResponse::message() const {
  // @@protoc_insertion_point(field_get:CARTA.RegionListResponse.message)
  return message_.GetNoArena();
}
inline void RegionListResponse::set_message(const ::std::string& value) {
  
  message_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:CARTA.RegionListResponse.message)
}
#if LANG_CXX11
inline void RegionListResponse::set_message(::std::string&& value) {
  
  message_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:CARTA.RegionListResponse.message)
}
#endif
inline void RegionListResponse::set_message(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  message_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:CARTA.RegionListResponse.message)
}
inline void RegionListResponse::set_message(const char* value, size_t size) {
  
  message_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:CARTA.RegionListResponse.message)
}
inline ::std::string* RegionListResponse::mutable_message() {
  
  // @@protoc_insertion_point(field_mutable:CARTA.RegionListResponse.message)
  return message_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* RegionListResponse::release_message() {
  // @@protoc_insertion_point(field_release:CARTA.RegionListResponse.message)
  
  return message_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void RegionListResponse::set_allocated_message(::std::string* message) {
  if (message != NULL) {
    
  } else {
    
  }
  message_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), message);
  // @@protoc_insertion_point(field_set_allocated:CARTA.RegionListResponse.message)
}

// string directory = 3;
inline void RegionListResponse::clear_directory() {
  directory_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& RegionListResponse::directory() const {
  // @@protoc_insertion_point(field_get:CARTA.RegionListResponse.directory)
  return directory_.GetNoArena();
}
inline void RegionListResponse::set_directory(const ::std::string& value) {
  
  directory_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:CARTA.RegionListResponse.directory)
}
#if LANG_CXX11
inline void RegionListResponse::set_directory(::std::string&& value) {
  
  directory_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:CARTA.RegionListResponse.directory)
}
#endif
inline void RegionListResponse::set_directory(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  directory_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:CARTA.RegionListResponse.directory)
}
inline void RegionListResponse::set_directory(const char* value, size_t size) {
  
  directory_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:CARTA.RegionListResponse.directory)
}
inline ::std::string* RegionListResponse::mutable_directory() {
  
  // @@protoc_insertion_point(field_mutable:CARTA.RegionListResponse.directory)
  return directory_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* RegionListResponse::release_directory() {
  // @@protoc_insertion_point(field_release:CARTA.RegionListResponse.directory)
  
  return directory_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void RegionListResponse::set_allocated_directory(::std::string* directory) {
  if (directory != NULL) {
    
  } else {
    
  }
  directory_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), directory);
  // @@protoc_insertion_point(field_set_allocated:CARTA.RegionListResponse.directory)
}

// string parent = 4;
inline void RegionListResponse::clear_parent() {
  parent_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& RegionListResponse::parent() const {
  // @@protoc_insertion_point(field_get:CARTA.RegionListResponse.parent)
  return parent_.GetNoArena();
}
inline void RegionListResponse::set_parent(const ::std::string& value) {
  
  parent_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:CARTA.RegionListResponse.parent)
}
#if LANG_CXX11
inline void RegionListResponse::set_parent(::std::string&& value) {
  
  parent_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:CARTA.RegionListResponse.parent)
}
#endif
inline void RegionListResponse::set_parent(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  parent_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:CARTA.RegionListResponse.parent)
}
inline void RegionListResponse::set_parent(const char* value, size_t size) {
  
  parent_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:CARTA.RegionListResponse.parent)
}
inline ::std::string* RegionListResponse::mutable_parent() {
  
  // @@protoc_insertion_point(field_mutable:CARTA.RegionListResponse.parent)
  return parent_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* RegionListResponse::release_parent() {
  // @@protoc_insertion_point(field_release:CARTA.RegionListResponse.parent)
  
  return parent_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void RegionListResponse::set_allocated_parent(::std::string* parent) {
  if (parent != NULL) {
    
  } else {
    
  }
  parent_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), parent);
  // @@protoc_insertion_point(field_set_allocated:CARTA.RegionListResponse.parent)
}

// repeated .CARTA.FileInfo files = 5;
inline int RegionListResponse::files_size() const {
  return files_.size();
}
inline ::CARTA::FileInfo* RegionListResponse::mutable_files(int index) {
  // @@protoc_insertion_point(field_mutable:CARTA.RegionListResponse.files)
  return files_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::CARTA::FileInfo >*
RegionListResponse::mutable_files() {
  // @@protoc_insertion_point(field_mutable_list:CARTA.RegionListResponse.files)
  return &files_;
}
inline const ::CARTA::FileInfo& RegionListResponse::files(int index) const {
  // @@protoc_insertion_point(field_get:CARTA.RegionListResponse.files)
  return files_.Get(index);
}
inline ::CARTA::FileInfo* RegionListResponse::add_files() {
  // @@protoc_insertion_point(field_add:CARTA.RegionListResponse.files)
  return files_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::CARTA::FileInfo >&
RegionListResponse::files() const {
  // @@protoc_insertion_point(field_list:CARTA.RegionListResponse.files)
  return files_;
}

// repeated .CARTA.DirectoryInfo subdirectories = 6;
inline int RegionListResponse::subdirectories_size() const {
  return subdirectories_.size();
}
inline ::CARTA::DirectoryInfo* RegionListResponse::mutable_subdirectories(int index) {
  // @@protoc_insertion_point(field_mutable:CARTA.RegionListResponse.subdirectories)
  return subdirectories_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::CARTA::DirectoryInfo >*
RegionListResponse::mutable_subdirectories() {
  // @@protoc_insertion_point(field_mutable_list:CARTA.RegionListResponse.subdirectories)
  return &subdirectories_;
}
inline const ::CARTA::DirectoryInfo& RegionListResponse::subdirectories(int index) const {
  // @@protoc_insertion_point(field_get:CARTA.RegionListResponse.subdirectories)
  return subdirectories_.Get(index);
}
inline ::CARTA::DirectoryInfo* RegionListResponse::add_subdirectories() {
  // @@protoc_insertion_point(field_add:CARTA.RegionListResponse.subdirectories)
  return subdirectories_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::CARTA::DirectoryInfo >&
RegionListResponse::subdirectories() const {
  // @@protoc_insertion_point(field_list:CARTA.RegionListResponse.subdirectories)
  return subdirectories_;
}

// bool cancel = 7;
inline void RegionListResponse::clear_cancel() {
  cancel_ = false;
}
inline bool RegionListResponse::cancel() const {
  // @@protoc_insertion_point(field_get:CARTA.RegionListResponse.cancel)
  return cancel_;
}
inline void RegionListResponse::set_cancel(bool value) {
  
  cancel_ = value;
  // @@protoc_insertion_point(field_set:CARTA.RegionListResponse.cancel)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace CARTA

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_region_5flist_2eproto
