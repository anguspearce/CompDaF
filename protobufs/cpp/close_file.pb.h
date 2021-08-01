// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: close_file.proto

#ifndef PROTOBUF_INCLUDED_close_5ffile_2eproto
#define PROTOBUF_INCLUDED_close_5ffile_2eproto

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
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_close_5ffile_2eproto 

namespace protobuf_close_5ffile_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_close_5ffile_2eproto
namespace CARTA {
class CloseFile;
class CloseFileDefaultTypeInternal;
extern CloseFileDefaultTypeInternal _CloseFile_default_instance_;
}  // namespace CARTA
namespace google {
namespace protobuf {
template<> ::CARTA::CloseFile* Arena::CreateMaybeMessage<::CARTA::CloseFile>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace CARTA {

// ===================================================================

class CloseFile : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:CARTA.CloseFile) */ {
 public:
  CloseFile();
  virtual ~CloseFile();

  CloseFile(const CloseFile& from);

  inline CloseFile& operator=(const CloseFile& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  CloseFile(CloseFile&& from) noexcept
    : CloseFile() {
    *this = ::std::move(from);
  }

  inline CloseFile& operator=(CloseFile&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const CloseFile& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const CloseFile* internal_default_instance() {
    return reinterpret_cast<const CloseFile*>(
               &_CloseFile_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(CloseFile* other);
  friend void swap(CloseFile& a, CloseFile& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline CloseFile* New() const final {
    return CreateMaybeMessage<CloseFile>(NULL);
  }

  CloseFile* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<CloseFile>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const CloseFile& from);
  void MergeFrom(const CloseFile& from);
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
  void InternalSwap(CloseFile* other);
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

  // sfixed32 file_id = 1;
  void clear_file_id();
  static const int kFileIdFieldNumber = 1;
  ::google::protobuf::int32 file_id() const;
  void set_file_id(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:CARTA.CloseFile)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int32 file_id_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_close_5ffile_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// CloseFile

// sfixed32 file_id = 1;
inline void CloseFile::clear_file_id() {
  file_id_ = 0;
}
inline ::google::protobuf::int32 CloseFile::file_id() const {
  // @@protoc_insertion_point(field_get:CARTA.CloseFile.file_id)
  return file_id_;
}
inline void CloseFile::set_file_id(::google::protobuf::int32 value) {
  
  file_id_ = value;
  // @@protoc_insertion_point(field_set:CARTA.CloseFile.file_id)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace CARTA

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_close_5ffile_2eproto
