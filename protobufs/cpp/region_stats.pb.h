// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: region_stats.proto

#ifndef PROTOBUF_INCLUDED_region_5fstats_2eproto
#define PROTOBUF_INCLUDED_region_5fstats_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_protobuf_region_5fstats_2eproto 

namespace protobuf_region_5fstats_2eproto {
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
}  // namespace protobuf_region_5fstats_2eproto
namespace CARTA {
class RegionStatsData;
class RegionStatsDataDefaultTypeInternal;
extern RegionStatsDataDefaultTypeInternal _RegionStatsData_default_instance_;
}  // namespace CARTA
namespace google {
namespace protobuf {
template<> ::CARTA::RegionStatsData* Arena::CreateMaybeMessage<::CARTA::RegionStatsData>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace CARTA {

// ===================================================================

class RegionStatsData : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:CARTA.RegionStatsData) */ {
 public:
  RegionStatsData();
  virtual ~RegionStatsData();

  RegionStatsData(const RegionStatsData& from);

  inline RegionStatsData& operator=(const RegionStatsData& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  RegionStatsData(RegionStatsData&& from) noexcept
    : RegionStatsData() {
    *this = ::std::move(from);
  }

  inline RegionStatsData& operator=(RegionStatsData&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const RegionStatsData& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const RegionStatsData* internal_default_instance() {
    return reinterpret_cast<const RegionStatsData*>(
               &_RegionStatsData_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(RegionStatsData* other);
  friend void swap(RegionStatsData& a, RegionStatsData& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline RegionStatsData* New() const final {
    return CreateMaybeMessage<RegionStatsData>(NULL);
  }

  RegionStatsData* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<RegionStatsData>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const RegionStatsData& from);
  void MergeFrom(const RegionStatsData& from);
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
  void InternalSwap(RegionStatsData* other);
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

  // repeated .CARTA.StatisticsValue statistics = 5;
  int statistics_size() const;
  void clear_statistics();
  static const int kStatisticsFieldNumber = 5;
  ::CARTA::StatisticsValue* mutable_statistics(int index);
  ::google::protobuf::RepeatedPtrField< ::CARTA::StatisticsValue >*
      mutable_statistics();
  const ::CARTA::StatisticsValue& statistics(int index) const;
  ::CARTA::StatisticsValue* add_statistics();
  const ::google::protobuf::RepeatedPtrField< ::CARTA::StatisticsValue >&
      statistics() const;

  // sfixed32 file_id = 1;
  void clear_file_id();
  static const int kFileIdFieldNumber = 1;
  ::google::protobuf::int32 file_id() const;
  void set_file_id(::google::protobuf::int32 value);

  // sfixed32 region_id = 2;
  void clear_region_id();
  static const int kRegionIdFieldNumber = 2;
  ::google::protobuf::int32 region_id() const;
  void set_region_id(::google::protobuf::int32 value);

  // sfixed32 channel = 3;
  void clear_channel();
  static const int kChannelFieldNumber = 3;
  ::google::protobuf::int32 channel() const;
  void set_channel(::google::protobuf::int32 value);

  // sfixed32 stokes = 4;
  void clear_stokes();
  static const int kStokesFieldNumber = 4;
  ::google::protobuf::int32 stokes() const;
  void set_stokes(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:CARTA.RegionStatsData)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::CARTA::StatisticsValue > statistics_;
  ::google::protobuf::int32 file_id_;
  ::google::protobuf::int32 region_id_;
  ::google::protobuf::int32 channel_;
  ::google::protobuf::int32 stokes_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_region_5fstats_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// RegionStatsData

// sfixed32 file_id = 1;
inline void RegionStatsData::clear_file_id() {
  file_id_ = 0;
}
inline ::google::protobuf::int32 RegionStatsData::file_id() const {
  // @@protoc_insertion_point(field_get:CARTA.RegionStatsData.file_id)
  return file_id_;
}
inline void RegionStatsData::set_file_id(::google::protobuf::int32 value) {
  
  file_id_ = value;
  // @@protoc_insertion_point(field_set:CARTA.RegionStatsData.file_id)
}

// sfixed32 region_id = 2;
inline void RegionStatsData::clear_region_id() {
  region_id_ = 0;
}
inline ::google::protobuf::int32 RegionStatsData::region_id() const {
  // @@protoc_insertion_point(field_get:CARTA.RegionStatsData.region_id)
  return region_id_;
}
inline void RegionStatsData::set_region_id(::google::protobuf::int32 value) {
  
  region_id_ = value;
  // @@protoc_insertion_point(field_set:CARTA.RegionStatsData.region_id)
}

// sfixed32 channel = 3;
inline void RegionStatsData::clear_channel() {
  channel_ = 0;
}
inline ::google::protobuf::int32 RegionStatsData::channel() const {
  // @@protoc_insertion_point(field_get:CARTA.RegionStatsData.channel)
  return channel_;
}
inline void RegionStatsData::set_channel(::google::protobuf::int32 value) {
  
  channel_ = value;
  // @@protoc_insertion_point(field_set:CARTA.RegionStatsData.channel)
}

// sfixed32 stokes = 4;
inline void RegionStatsData::clear_stokes() {
  stokes_ = 0;
}
inline ::google::protobuf::int32 RegionStatsData::stokes() const {
  // @@protoc_insertion_point(field_get:CARTA.RegionStatsData.stokes)
  return stokes_;
}
inline void RegionStatsData::set_stokes(::google::protobuf::int32 value) {
  
  stokes_ = value;
  // @@protoc_insertion_point(field_set:CARTA.RegionStatsData.stokes)
}

// repeated .CARTA.StatisticsValue statistics = 5;
inline int RegionStatsData::statistics_size() const {
  return statistics_.size();
}
inline ::CARTA::StatisticsValue* RegionStatsData::mutable_statistics(int index) {
  // @@protoc_insertion_point(field_mutable:CARTA.RegionStatsData.statistics)
  return statistics_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::CARTA::StatisticsValue >*
RegionStatsData::mutable_statistics() {
  // @@protoc_insertion_point(field_mutable_list:CARTA.RegionStatsData.statistics)
  return &statistics_;
}
inline const ::CARTA::StatisticsValue& RegionStatsData::statistics(int index) const {
  // @@protoc_insertion_point(field_get:CARTA.RegionStatsData.statistics)
  return statistics_.Get(index);
}
inline ::CARTA::StatisticsValue* RegionStatsData::add_statistics() {
  // @@protoc_insertion_point(field_add:CARTA.RegionStatsData.statistics)
  return statistics_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::CARTA::StatisticsValue >&
RegionStatsData::statistics() const {
  // @@protoc_insertion_point(field_list:CARTA.RegionStatsData.statistics)
  return statistics_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace CARTA

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_region_5fstats_2eproto
