// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: enums.proto

#ifndef PROTOBUF_INCLUDED_enums_2eproto
#define PROTOBUF_INCLUDED_enums_2eproto

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
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_enums_2eproto 

namespace protobuf_enums_2eproto {
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
}  // namespace protobuf_enums_2eproto
namespace CARTA {
}  // namespace CARTA
namespace CARTA {

enum EventType {
  EMPTY_EVENT = 0,
  REGISTER_VIEWER = 1,
  FILE_LIST_REQUEST = 2,
  FILE_INFO_REQUEST = 3,
  OPEN_FILE = 4,
  SET_IMAGE_CHANNELS = 6,
  SET_CURSOR = 7,
  SET_SPATIAL_REQUIREMENTS = 8,
  SET_HISTOGRAM_REQUIREMENTS = 9,
  SET_STATS_REQUIREMENTS = 10,
  SET_REGION = 11,
  REMOVE_REGION = 12,
  CLOSE_FILE = 13,
  SET_SPECTRAL_REQUIREMENTS = 14,
  START_ANIMATION = 15,
  START_ANIMATION_ACK = 16,
  STOP_ANIMATION = 17,
  REGISTER_VIEWER_ACK = 18,
  FILE_LIST_RESPONSE = 19,
  FILE_INFO_RESPONSE = 20,
  OPEN_FILE_ACK = 21,
  SET_REGION_ACK = 22,
  REGION_HISTOGRAM_DATA = 23,
  SPATIAL_PROFILE_DATA = 25,
  SPECTRAL_PROFILE_DATA = 26,
  REGION_STATS_DATA = 27,
  ERROR_DATA = 28,
  ANIMATION_FLOW_CONTROL = 29,
  ADD_REQUIRED_TILES = 30,
  REMOVE_REQUIRED_TILES = 31,
  RASTER_TILE_DATA = 32,
  REGION_LIST_REQUEST = 33,
  REGION_LIST_RESPONSE = 34,
  REGION_FILE_INFO_REQUEST = 35,
  REGION_FILE_INFO_RESPONSE = 36,
  IMPORT_REGION = 37,
  IMPORT_REGION_ACK = 38,
  EXPORT_REGION = 39,
  EXPORT_REGION_ACK = 40,
  SET_CONTOUR_PARAMETERS = 45,
  CONTOUR_IMAGE_DATA = 46,
  RESUME_SESSION = 47,
  RESUME_SESSION_ACK = 48,
  RASTER_TILE_SYNC = 49,
  CATALOG_LIST_REQUEST = 50,
  CATALOG_LIST_RESPONSE = 51,
  CATALOG_FILE_INFO_REQUEST = 52,
  CATALOG_FILE_INFO_RESPONSE = 53,
  OPEN_CATALOG_FILE = 54,
  OPEN_CATALOG_FILE_ACK = 55,
  CLOSE_CATALOG_FILE = 56,
  CATALOG_FILTER_REQUEST = 57,
  CATALOG_FILTER_RESPONSE = 58,
  SCRIPTING_REQUEST = 59,
  SCRIPTING_RESPONSE = 60,
  MOMENT_REQUEST = 61,
  MOMENT_RESPONSE = 62,
  MOMENT_PROGRESS = 63,
  STOP_MOMENT_CALC = 64,
  SAVE_FILE = 65,
  SAVE_FILE_ACK = 66,
  SPECTRAL_LINE_REQUEST = 67,
  SPECTRAL_LINE_RESPONSE = 68,
  CONCAT_STOKES_FILES = 69,
  CONCAT_STOKES_FILES_ACK = 70,
  FILE_LIST_PROGRESS = 71,
  STOP_FILE_LIST = 72,
  SPLATALOGUE_PING = 73,
  SPLATALOGUE_PONG = 74,
  EventType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  EventType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool EventType_IsValid(int value);
const EventType EventType_MIN = EMPTY_EVENT;
const EventType EventType_MAX = SPLATALOGUE_PONG;
const int EventType_ARRAYSIZE = EventType_MAX + 1;

const ::google::protobuf::EnumDescriptor* EventType_descriptor();
inline const ::std::string& EventType_Name(EventType value) {
  return ::google::protobuf::internal::NameOfEnum(
    EventType_descriptor(), value);
}
inline bool EventType_Parse(
    const ::std::string& name, EventType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EventType>(
    EventType_descriptor(), name, value);
}
enum SessionType {
  NEW = 0,
  RESUMED = 1,
  SessionType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  SessionType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool SessionType_IsValid(int value);
const SessionType SessionType_MIN = NEW;
const SessionType SessionType_MAX = RESUMED;
const int SessionType_ARRAYSIZE = SessionType_MAX + 1;

const ::google::protobuf::EnumDescriptor* SessionType_descriptor();
inline const ::std::string& SessionType_Name(SessionType value) {
  return ::google::protobuf::internal::NameOfEnum(
    SessionType_descriptor(), value);
}
inline bool SessionType_Parse(
    const ::std::string& name, SessionType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<SessionType>(
    SessionType_descriptor(), name, value);
}
enum FileType {
  CASA = 0,
  CRTF = 1,
  DS9_REG = 2,
  FITS = 3,
  HDF5 = 4,
  MIRIAD = 5,
  UNKNOWN = 6,
  FileType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  FileType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool FileType_IsValid(int value);
const FileType FileType_MIN = CASA;
const FileType FileType_MAX = UNKNOWN;
const int FileType_ARRAYSIZE = FileType_MAX + 1;

const ::google::protobuf::EnumDescriptor* FileType_descriptor();
inline const ::std::string& FileType_Name(FileType value) {
  return ::google::protobuf::internal::NameOfEnum(
    FileType_descriptor(), value);
}
inline bool FileType_Parse(
    const ::std::string& name, FileType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<FileType>(
    FileType_descriptor(), name, value);
}
enum RenderMode {
  RASTER = 0,
  CONTOUR = 1,
  RenderMode_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  RenderMode_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool RenderMode_IsValid(int value);
const RenderMode RenderMode_MIN = RASTER;
const RenderMode RenderMode_MAX = CONTOUR;
const int RenderMode_ARRAYSIZE = RenderMode_MAX + 1;

const ::google::protobuf::EnumDescriptor* RenderMode_descriptor();
inline const ::std::string& RenderMode_Name(RenderMode value) {
  return ::google::protobuf::internal::NameOfEnum(
    RenderMode_descriptor(), value);
}
inline bool RenderMode_Parse(
    const ::std::string& name, RenderMode* value) {
  return ::google::protobuf::internal::ParseNamedEnum<RenderMode>(
    RenderMode_descriptor(), name, value);
}
enum CompressionType {
  NONE = 0,
  ZFP = 1,
  SZ = 2,
  CompressionType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  CompressionType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool CompressionType_IsValid(int value);
const CompressionType CompressionType_MIN = NONE;
const CompressionType CompressionType_MAX = SZ;
const int CompressionType_ARRAYSIZE = CompressionType_MAX + 1;

const ::google::protobuf::EnumDescriptor* CompressionType_descriptor();
inline const ::std::string& CompressionType_Name(CompressionType value) {
  return ::google::protobuf::internal::NameOfEnum(
    CompressionType_descriptor(), value);
}
inline bool CompressionType_Parse(
    const ::std::string& name, CompressionType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<CompressionType>(
    CompressionType_descriptor(), name, value);
}
enum RegionType {
  POINT = 0,
  LINE = 1,
  POLYLINE = 2,
  RECTANGLE = 3,
  ELLIPSE = 4,
  ANNULUS = 5,
  POLYGON = 6,
  RegionType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  RegionType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool RegionType_IsValid(int value);
const RegionType RegionType_MIN = POINT;
const RegionType RegionType_MAX = POLYGON;
const int RegionType_ARRAYSIZE = RegionType_MAX + 1;

const ::google::protobuf::EnumDescriptor* RegionType_descriptor();
inline const ::std::string& RegionType_Name(RegionType value) {
  return ::google::protobuf::internal::NameOfEnum(
    RegionType_descriptor(), value);
}
inline bool RegionType_Parse(
    const ::std::string& name, RegionType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<RegionType>(
    RegionType_descriptor(), name, value);
}
enum SmoothingMode {
  NoSmoothing = 0,
  BlockAverage = 1,
  GaussianBlur = 2,
  SmoothingMode_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  SmoothingMode_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool SmoothingMode_IsValid(int value);
const SmoothingMode SmoothingMode_MIN = NoSmoothing;
const SmoothingMode SmoothingMode_MAX = GaussianBlur;
const int SmoothingMode_ARRAYSIZE = SmoothingMode_MAX + 1;

const ::google::protobuf::EnumDescriptor* SmoothingMode_descriptor();
inline const ::std::string& SmoothingMode_Name(SmoothingMode value) {
  return ::google::protobuf::internal::NameOfEnum(
    SmoothingMode_descriptor(), value);
}
inline bool SmoothingMode_Parse(
    const ::std::string& name, SmoothingMode* value) {
  return ::google::protobuf::internal::ParseNamedEnum<SmoothingMode>(
    SmoothingMode_descriptor(), name, value);
}
enum StatsType {
  NumPixels = 0,
  NanCount = 1,
  Sum = 2,
  FluxDensity = 3,
  Mean = 4,
  RMS = 5,
  Sigma = 6,
  SumSq = 7,
  Min = 8,
  Max = 9,
  Extrema = 10,
  Blc = 11,
  Trc = 12,
  MinPos = 13,
  MaxPos = 14,
  Blcf = 15,
  Trcf = 16,
  MinPosf = 17,
  MaxPosf = 18,
  StatsType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  StatsType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool StatsType_IsValid(int value);
const StatsType StatsType_MIN = NumPixels;
const StatsType StatsType_MAX = MaxPosf;
const int StatsType_ARRAYSIZE = StatsType_MAX + 1;

const ::google::protobuf::EnumDescriptor* StatsType_descriptor();
inline const ::std::string& StatsType_Name(StatsType value) {
  return ::google::protobuf::internal::NameOfEnum(
    StatsType_descriptor(), value);
}
inline bool StatsType_Parse(
    const ::std::string& name, StatsType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<StatsType>(
    StatsType_descriptor(), name, value);
}
enum ErrorSeverity {
  DEBUG = 0,
  INFO = 1,
  WARNING = 2,
  ERROR = 3,
  CRITICAL = 4,
  ErrorSeverity_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  ErrorSeverity_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool ErrorSeverity_IsValid(int value);
const ErrorSeverity ErrorSeverity_MIN = DEBUG;
const ErrorSeverity ErrorSeverity_MAX = CRITICAL;
const int ErrorSeverity_ARRAYSIZE = ErrorSeverity_MAX + 1;

const ::google::protobuf::EnumDescriptor* ErrorSeverity_descriptor();
inline const ::std::string& ErrorSeverity_Name(ErrorSeverity value) {
  return ::google::protobuf::internal::NameOfEnum(
    ErrorSeverity_descriptor(), value);
}
inline bool ErrorSeverity_Parse(
    const ::std::string& name, ErrorSeverity* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ErrorSeverity>(
    ErrorSeverity_descriptor(), name, value);
}
enum EntryType {
  STRING = 0,
  FLOAT = 1,
  INT = 2,
  EntryType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  EntryType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool EntryType_IsValid(int value);
const EntryType EntryType_MIN = STRING;
const EntryType EntryType_MAX = INT;
const int EntryType_ARRAYSIZE = EntryType_MAX + 1;

const ::google::protobuf::EnumDescriptor* EntryType_descriptor();
inline const ::std::string& EntryType_Name(EntryType value) {
  return ::google::protobuf::internal::NameOfEnum(
    EntryType_descriptor(), value);
}
inline bool EntryType_Parse(
    const ::std::string& name, EntryType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<EntryType>(
    EntryType_descriptor(), name, value);
}
enum ClientFeatureFlags {
  CLIENT_FEATURE_NONE = 0,
  WEB_GL = 1,
  WEB_GL_2 = 2,
  WEB_ASSEMBLY = 4,
  WEB_ASSEMBLY_THREADS = 8,
  OFFSCREEN_CANVAS = 16,
  ClientFeatureFlags_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  ClientFeatureFlags_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool ClientFeatureFlags_IsValid(int value);
const ClientFeatureFlags ClientFeatureFlags_MIN = CLIENT_FEATURE_NONE;
const ClientFeatureFlags ClientFeatureFlags_MAX = OFFSCREEN_CANVAS;
const int ClientFeatureFlags_ARRAYSIZE = ClientFeatureFlags_MAX + 1;

const ::google::protobuf::EnumDescriptor* ClientFeatureFlags_descriptor();
inline const ::std::string& ClientFeatureFlags_Name(ClientFeatureFlags value) {
  return ::google::protobuf::internal::NameOfEnum(
    ClientFeatureFlags_descriptor(), value);
}
inline bool ClientFeatureFlags_Parse(
    const ::std::string& name, ClientFeatureFlags* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ClientFeatureFlags>(
    ClientFeatureFlags_descriptor(), name, value);
}
enum ServerFeatureFlags {
  SERVER_FEATURE_NONE = 0,
  SZ_COMPRESSION = 1,
  HEVC_COMPRESSION = 2,
  NVENC_COMPRESSION = 4,
  READ_ONLY = 8,
  USER_PREFERENCES = 16,
  USER_LAYOUTS = 32,
  GRPC_SCRIPTING = 64,
  ServerFeatureFlags_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  ServerFeatureFlags_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool ServerFeatureFlags_IsValid(int value);
const ServerFeatureFlags ServerFeatureFlags_MIN = SERVER_FEATURE_NONE;
const ServerFeatureFlags ServerFeatureFlags_MAX = GRPC_SCRIPTING;
const int ServerFeatureFlags_ARRAYSIZE = ServerFeatureFlags_MAX + 1;

const ::google::protobuf::EnumDescriptor* ServerFeatureFlags_descriptor();
inline const ::std::string& ServerFeatureFlags_Name(ServerFeatureFlags value) {
  return ::google::protobuf::internal::NameOfEnum(
    ServerFeatureFlags_descriptor(), value);
}
inline bool ServerFeatureFlags_Parse(
    const ::std::string& name, ServerFeatureFlags* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ServerFeatureFlags>(
    ServerFeatureFlags_descriptor(), name, value);
}
enum FileFeatureFlags {
  FILE_FEATURE_NONE = 0,
  ROTATED_DATASET = 1,
  CHANNEL_HISTOGRAMS = 2,
  CUBE_HISTOGRAMS = 4,
  CHANNEL_STATS = 8,
  MEAN_IMAGE = 16,
  MIP_DATASET = 32,
  FileFeatureFlags_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  FileFeatureFlags_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool FileFeatureFlags_IsValid(int value);
const FileFeatureFlags FileFeatureFlags_MIN = FILE_FEATURE_NONE;
const FileFeatureFlags FileFeatureFlags_MAX = MIP_DATASET;
const int FileFeatureFlags_ARRAYSIZE = FileFeatureFlags_MAX + 1;

const ::google::protobuf::EnumDescriptor* FileFeatureFlags_descriptor();
inline const ::std::string& FileFeatureFlags_Name(FileFeatureFlags value) {
  return ::google::protobuf::internal::NameOfEnum(
    FileFeatureFlags_descriptor(), value);
}
inline bool FileFeatureFlags_Parse(
    const ::std::string& name, FileFeatureFlags* value) {
  return ::google::protobuf::internal::ParseNamedEnum<FileFeatureFlags>(
    FileFeatureFlags_descriptor(), name, value);
}
enum CoordinateType {
  PIXEL = 0,
  WORLD = 1,
  CoordinateType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  CoordinateType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool CoordinateType_IsValid(int value);
const CoordinateType CoordinateType_MIN = PIXEL;
const CoordinateType CoordinateType_MAX = WORLD;
const int CoordinateType_ARRAYSIZE = CoordinateType_MAX + 1;

const ::google::protobuf::EnumDescriptor* CoordinateType_descriptor();
inline const ::std::string& CoordinateType_Name(CoordinateType value) {
  return ::google::protobuf::internal::NameOfEnum(
    CoordinateType_descriptor(), value);
}
inline bool CoordinateType_Parse(
    const ::std::string& name, CoordinateType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<CoordinateType>(
    CoordinateType_descriptor(), name, value);
}
enum CatalogFileType {
  FITSTable = 0,
  VOTable = 1,
  CatalogFileType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  CatalogFileType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool CatalogFileType_IsValid(int value);
const CatalogFileType CatalogFileType_MIN = FITSTable;
const CatalogFileType CatalogFileType_MAX = VOTable;
const int CatalogFileType_ARRAYSIZE = CatalogFileType_MAX + 1;

const ::google::protobuf::EnumDescriptor* CatalogFileType_descriptor();
inline const ::std::string& CatalogFileType_Name(CatalogFileType value) {
  return ::google::protobuf::internal::NameOfEnum(
    CatalogFileType_descriptor(), value);
}
inline bool CatalogFileType_Parse(
    const ::std::string& name, CatalogFileType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<CatalogFileType>(
    CatalogFileType_descriptor(), name, value);
}
enum ColumnType {
  UnsupportedType = 0,
  String = 1,
  Uint8 = 2,
  Int8 = 3,
  Uint16 = 4,
  Int16 = 5,
  Uint32 = 6,
  Int32 = 7,
  Uint64 = 8,
  Int64 = 9,
  Float = 10,
  Double = 11,
  Bool = 12,
  ColumnType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  ColumnType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool ColumnType_IsValid(int value);
const ColumnType ColumnType_MIN = UnsupportedType;
const ColumnType ColumnType_MAX = Bool;
const int ColumnType_ARRAYSIZE = ColumnType_MAX + 1;

const ::google::protobuf::EnumDescriptor* ColumnType_descriptor();
inline const ::std::string& ColumnType_Name(ColumnType value) {
  return ::google::protobuf::internal::NameOfEnum(
    ColumnType_descriptor(), value);
}
inline bool ColumnType_Parse(
    const ::std::string& name, ColumnType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ColumnType>(
    ColumnType_descriptor(), name, value);
}
enum ComparisonOperator {
  Equal = 0,
  NotEqual = 1,
  Lesser = 2,
  Greater = 3,
  LessorOrEqual = 4,
  GreaterOrEqual = 5,
  RangeOpen = 6,
  RangeClosed = 7,
  ComparisonOperator_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  ComparisonOperator_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool ComparisonOperator_IsValid(int value);
const ComparisonOperator ComparisonOperator_MIN = Equal;
const ComparisonOperator ComparisonOperator_MAX = RangeClosed;
const int ComparisonOperator_ARRAYSIZE = ComparisonOperator_MAX + 1;

const ::google::protobuf::EnumDescriptor* ComparisonOperator_descriptor();
inline const ::std::string& ComparisonOperator_Name(ComparisonOperator value) {
  return ::google::protobuf::internal::NameOfEnum(
    ComparisonOperator_descriptor(), value);
}
inline bool ComparisonOperator_Parse(
    const ::std::string& name, ComparisonOperator* value) {
  return ::google::protobuf::internal::ParseNamedEnum<ComparisonOperator>(
    ComparisonOperator_descriptor(), name, value);
}
enum SortingType {
  Ascending = 0,
  Descending = 1,
  SortingType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  SortingType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool SortingType_IsValid(int value);
const SortingType SortingType_MIN = Ascending;
const SortingType SortingType_MAX = Descending;
const int SortingType_ARRAYSIZE = SortingType_MAX + 1;

const ::google::protobuf::EnumDescriptor* SortingType_descriptor();
inline const ::std::string& SortingType_Name(SortingType value) {
  return ::google::protobuf::internal::NameOfEnum(
    SortingType_descriptor(), value);
}
inline bool SortingType_Parse(
    const ::std::string& name, SortingType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<SortingType>(
    SortingType_descriptor(), name, value);
}
enum Moment {
  MEAN_OF_THE_SPECTRUM = 0,
  INTEGRATED_OF_THE_SPECTRUM = 1,
  INTENSITY_WEIGHTED_COORD = 2,
  INTENSITY_WEIGHTED_DISPERSION_OF_THE_COORD = 3,
  MEDIAN_OF_THE_SPECTRUM = 4,
  MEDIAN_COORDINATE = 5,
  STD_ABOUT_THE_MEAN_OF_THE_SPECTRUM = 6,
  RMS_OF_THE_SPECTRUM = 7,
  ABS_MEAN_DEVIATION_OF_THE_SPECTRUM = 8,
  MAX_OF_THE_SPECTRUM = 9,
  COORD_OF_THE_MAX_OF_THE_SPECTRUM = 10,
  MIN_OF_THE_SPECTRUM = 11,
  COORD_OF_THE_MIN_OF_THE_SPECTRUM = 12,
  Moment_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  Moment_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool Moment_IsValid(int value);
const Moment Moment_MIN = MEAN_OF_THE_SPECTRUM;
const Moment Moment_MAX = COORD_OF_THE_MIN_OF_THE_SPECTRUM;
const int Moment_ARRAYSIZE = Moment_MAX + 1;

const ::google::protobuf::EnumDescriptor* Moment_descriptor();
inline const ::std::string& Moment_Name(Moment value) {
  return ::google::protobuf::internal::NameOfEnum(
    Moment_descriptor(), value);
}
inline bool Moment_Parse(
    const ::std::string& name, Moment* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Moment>(
    Moment_descriptor(), name, value);
}
enum MomentAxis {
  SPECTRAL = 0,
  STOKES = 1,
  MomentAxis_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  MomentAxis_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool MomentAxis_IsValid(int value);
const MomentAxis MomentAxis_MIN = SPECTRAL;
const MomentAxis MomentAxis_MAX = STOKES;
const int MomentAxis_ARRAYSIZE = MomentAxis_MAX + 1;

const ::google::protobuf::EnumDescriptor* MomentAxis_descriptor();
inline const ::std::string& MomentAxis_Name(MomentAxis value) {
  return ::google::protobuf::internal::NameOfEnum(
    MomentAxis_descriptor(), value);
}
inline bool MomentAxis_Parse(
    const ::std::string& name, MomentAxis* value) {
  return ::google::protobuf::internal::ParseNamedEnum<MomentAxis>(
    MomentAxis_descriptor(), name, value);
}
enum MomentMask {
  None = 0,
  Include = 1,
  Exclude = 2,
  MomentMask_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  MomentMask_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool MomentMask_IsValid(int value);
const MomentMask MomentMask_MIN = None;
const MomentMask MomentMask_MAX = Exclude;
const int MomentMask_ARRAYSIZE = MomentMask_MAX + 1;

const ::google::protobuf::EnumDescriptor* MomentMask_descriptor();
inline const ::std::string& MomentMask_Name(MomentMask value) {
  return ::google::protobuf::internal::NameOfEnum(
    MomentMask_descriptor(), value);
}
inline bool MomentMask_Parse(
    const ::std::string& name, MomentMask* value) {
  return ::google::protobuf::internal::ParseNamedEnum<MomentMask>(
    MomentMask_descriptor(), name, value);
}
enum StokesType {
  STOKES_TYPE_NONE = 0,
  I = 1,
  Q = 2,
  U = 3,
  V = 4,
  StokesType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  StokesType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool StokesType_IsValid(int value);
const StokesType StokesType_MIN = STOKES_TYPE_NONE;
const StokesType StokesType_MAX = V;
const int StokesType_ARRAYSIZE = StokesType_MAX + 1;

const ::google::protobuf::EnumDescriptor* StokesType_descriptor();
inline const ::std::string& StokesType_Name(StokesType value) {
  return ::google::protobuf::internal::NameOfEnum(
    StokesType_descriptor(), value);
}
inline bool StokesType_Parse(
    const ::std::string& name, StokesType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<StokesType>(
    StokesType_descriptor(), name, value);
}
enum FileListType {
  Image = 0,
  Catalog = 1,
  FileListType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  FileListType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool FileListType_IsValid(int value);
const FileListType FileListType_MIN = Image;
const FileListType FileListType_MAX = Catalog;
const int FileListType_ARRAYSIZE = FileListType_MAX + 1;

const ::google::protobuf::EnumDescriptor* FileListType_descriptor();
inline const ::std::string& FileListType_Name(FileListType value) {
  return ::google::protobuf::internal::NameOfEnum(
    FileListType_descriptor(), value);
}
inline bool FileListType_Parse(
    const ::std::string& name, FileListType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<FileListType>(
    FileListType_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace CARTA

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::CARTA::EventType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::CARTA::EventType>() {
  return ::CARTA::EventType_descriptor();
}
template <> struct is_proto_enum< ::CARTA::SessionType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::CARTA::SessionType>() {
  return ::CARTA::SessionType_descriptor();
}
template <> struct is_proto_enum< ::CARTA::FileType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::CARTA::FileType>() {
  return ::CARTA::FileType_descriptor();
}
template <> struct is_proto_enum< ::CARTA::RenderMode> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::CARTA::RenderMode>() {
  return ::CARTA::RenderMode_descriptor();
}
template <> struct is_proto_enum< ::CARTA::CompressionType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::CARTA::CompressionType>() {
  return ::CARTA::CompressionType_descriptor();
}
template <> struct is_proto_enum< ::CARTA::RegionType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::CARTA::RegionType>() {
  return ::CARTA::RegionType_descriptor();
}
template <> struct is_proto_enum< ::CARTA::SmoothingMode> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::CARTA::SmoothingMode>() {
  return ::CARTA::SmoothingMode_descriptor();
}
template <> struct is_proto_enum< ::CARTA::StatsType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::CARTA::StatsType>() {
  return ::CARTA::StatsType_descriptor();
}
template <> struct is_proto_enum< ::CARTA::ErrorSeverity> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::CARTA::ErrorSeverity>() {
  return ::CARTA::ErrorSeverity_descriptor();
}
template <> struct is_proto_enum< ::CARTA::EntryType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::CARTA::EntryType>() {
  return ::CARTA::EntryType_descriptor();
}
template <> struct is_proto_enum< ::CARTA::ClientFeatureFlags> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::CARTA::ClientFeatureFlags>() {
  return ::CARTA::ClientFeatureFlags_descriptor();
}
template <> struct is_proto_enum< ::CARTA::ServerFeatureFlags> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::CARTA::ServerFeatureFlags>() {
  return ::CARTA::ServerFeatureFlags_descriptor();
}
template <> struct is_proto_enum< ::CARTA::FileFeatureFlags> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::CARTA::FileFeatureFlags>() {
  return ::CARTA::FileFeatureFlags_descriptor();
}
template <> struct is_proto_enum< ::CARTA::CoordinateType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::CARTA::CoordinateType>() {
  return ::CARTA::CoordinateType_descriptor();
}
template <> struct is_proto_enum< ::CARTA::CatalogFileType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::CARTA::CatalogFileType>() {
  return ::CARTA::CatalogFileType_descriptor();
}
template <> struct is_proto_enum< ::CARTA::ColumnType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::CARTA::ColumnType>() {
  return ::CARTA::ColumnType_descriptor();
}
template <> struct is_proto_enum< ::CARTA::ComparisonOperator> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::CARTA::ComparisonOperator>() {
  return ::CARTA::ComparisonOperator_descriptor();
}
template <> struct is_proto_enum< ::CARTA::SortingType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::CARTA::SortingType>() {
  return ::CARTA::SortingType_descriptor();
}
template <> struct is_proto_enum< ::CARTA::Moment> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::CARTA::Moment>() {
  return ::CARTA::Moment_descriptor();
}
template <> struct is_proto_enum< ::CARTA::MomentAxis> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::CARTA::MomentAxis>() {
  return ::CARTA::MomentAxis_descriptor();
}
template <> struct is_proto_enum< ::CARTA::MomentMask> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::CARTA::MomentMask>() {
  return ::CARTA::MomentMask_descriptor();
}
template <> struct is_proto_enum< ::CARTA::StokesType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::CARTA::StokesType>() {
  return ::CARTA::StokesType_descriptor();
}
template <> struct is_proto_enum< ::CARTA::FileListType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::CARTA::FileListType>() {
  return ::CARTA::FileListType_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_enums_2eproto
