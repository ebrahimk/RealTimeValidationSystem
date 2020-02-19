// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: packet.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_packet_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_packet_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011002 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_packet_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_packet_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_packet_2eproto;
namespace packet {
class FramePacket;
class FramePacketDefaultTypeInternal;
extern FramePacketDefaultTypeInternal _FramePacket_default_instance_;
}  // namespace packet
PROTOBUF_NAMESPACE_OPEN
template<> ::packet::FramePacket* Arena::CreateMaybeMessage<::packet::FramePacket>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace packet {

// ===================================================================

class FramePacket :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:packet.FramePacket) */ {
 public:
  FramePacket();
  virtual ~FramePacket();

  FramePacket(const FramePacket& from);
  FramePacket(FramePacket&& from) noexcept
    : FramePacket() {
    *this = ::std::move(from);
  }

  inline FramePacket& operator=(const FramePacket& from) {
    CopyFrom(from);
    return *this;
  }
  inline FramePacket& operator=(FramePacket&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const FramePacket& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const FramePacket* internal_default_instance() {
    return reinterpret_cast<const FramePacket*>(
               &_FramePacket_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(FramePacket& a, FramePacket& b) {
    a.Swap(&b);
  }
  inline void Swap(FramePacket* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline FramePacket* New() const final {
    return CreateMaybeMessage<FramePacket>(nullptr);
  }

  FramePacket* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<FramePacket>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const FramePacket& from);
  void MergeFrom(const FramePacket& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(FramePacket* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "packet.FramePacket";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_packet_2eproto);
    return ::descriptor_table_packet_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMatDataAFieldNumber = 5,
    kMatDataBFieldNumber = 6,
    kRowsFieldNumber = 1,
    kColsFieldNumber = 2,
    kEltTypeFieldNumber = 3,
    kEltSizeaFieldNumber = 4,
    kEltSizebFieldNumber = 7,
    kRowsbFieldNumber = 8,
    kColsbFieldNumber = 9,
  };
  // bytes mat_dataA = 5;
  void clear_mat_dataa();
  const std::string& mat_dataa() const;
  void set_mat_dataa(const std::string& value);
  void set_mat_dataa(std::string&& value);
  void set_mat_dataa(const char* value);
  void set_mat_dataa(const void* value, size_t size);
  std::string* mutable_mat_dataa();
  std::string* release_mat_dataa();
  void set_allocated_mat_dataa(std::string* mat_dataa);
  private:
  const std::string& _internal_mat_dataa() const;
  void _internal_set_mat_dataa(const std::string& value);
  std::string* _internal_mutable_mat_dataa();
  public:

  // bytes mat_dataB = 6;
  void clear_mat_datab();
  const std::string& mat_datab() const;
  void set_mat_datab(const std::string& value);
  void set_mat_datab(std::string&& value);
  void set_mat_datab(const char* value);
  void set_mat_datab(const void* value, size_t size);
  std::string* mutable_mat_datab();
  std::string* release_mat_datab();
  void set_allocated_mat_datab(std::string* mat_datab);
  private:
  const std::string& _internal_mat_datab() const;
  void _internal_set_mat_datab(const std::string& value);
  std::string* _internal_mutable_mat_datab();
  public:

  // int32 rows = 1;
  void clear_rows();
  ::PROTOBUF_NAMESPACE_ID::int32 rows() const;
  void set_rows(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_rows() const;
  void _internal_set_rows(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 cols = 2;
  void clear_cols();
  ::PROTOBUF_NAMESPACE_ID::int32 cols() const;
  void set_cols(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_cols() const;
  void _internal_set_cols(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 elt_type = 3;
  void clear_elt_type();
  ::PROTOBUF_NAMESPACE_ID::int32 elt_type() const;
  void set_elt_type(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_elt_type() const;
  void _internal_set_elt_type(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 elt_sizea = 4;
  void clear_elt_sizea();
  ::PROTOBUF_NAMESPACE_ID::int32 elt_sizea() const;
  void set_elt_sizea(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_elt_sizea() const;
  void _internal_set_elt_sizea(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 elt_sizeb = 7;
  void clear_elt_sizeb();
  ::PROTOBUF_NAMESPACE_ID::int32 elt_sizeb() const;
  void set_elt_sizeb(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_elt_sizeb() const;
  void _internal_set_elt_sizeb(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 rowsb = 8;
  void clear_rowsb();
  ::PROTOBUF_NAMESPACE_ID::int32 rowsb() const;
  void set_rowsb(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_rowsb() const;
  void _internal_set_rowsb(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 colsb = 9;
  void clear_colsb();
  ::PROTOBUF_NAMESPACE_ID::int32 colsb() const;
  void set_colsb(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_colsb() const;
  void _internal_set_colsb(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:packet.FramePacket)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr mat_dataa_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr mat_datab_;
  ::PROTOBUF_NAMESPACE_ID::int32 rows_;
  ::PROTOBUF_NAMESPACE_ID::int32 cols_;
  ::PROTOBUF_NAMESPACE_ID::int32 elt_type_;
  ::PROTOBUF_NAMESPACE_ID::int32 elt_sizea_;
  ::PROTOBUF_NAMESPACE_ID::int32 elt_sizeb_;
  ::PROTOBUF_NAMESPACE_ID::int32 rowsb_;
  ::PROTOBUF_NAMESPACE_ID::int32 colsb_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_packet_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// FramePacket

// int32 rows = 1;
inline void FramePacket::clear_rows() {
  rows_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 FramePacket::_internal_rows() const {
  return rows_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 FramePacket::rows() const {
  // @@protoc_insertion_point(field_get:packet.FramePacket.rows)
  return _internal_rows();
}
inline void FramePacket::_internal_set_rows(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  rows_ = value;
}
inline void FramePacket::set_rows(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_rows(value);
  // @@protoc_insertion_point(field_set:packet.FramePacket.rows)
}

// int32 cols = 2;
inline void FramePacket::clear_cols() {
  cols_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 FramePacket::_internal_cols() const {
  return cols_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 FramePacket::cols() const {
  // @@protoc_insertion_point(field_get:packet.FramePacket.cols)
  return _internal_cols();
}
inline void FramePacket::_internal_set_cols(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  cols_ = value;
}
inline void FramePacket::set_cols(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_cols(value);
  // @@protoc_insertion_point(field_set:packet.FramePacket.cols)
}

// int32 elt_type = 3;
inline void FramePacket::clear_elt_type() {
  elt_type_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 FramePacket::_internal_elt_type() const {
  return elt_type_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 FramePacket::elt_type() const {
  // @@protoc_insertion_point(field_get:packet.FramePacket.elt_type)
  return _internal_elt_type();
}
inline void FramePacket::_internal_set_elt_type(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  elt_type_ = value;
}
inline void FramePacket::set_elt_type(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_elt_type(value);
  // @@protoc_insertion_point(field_set:packet.FramePacket.elt_type)
}

// int32 elt_sizea = 4;
inline void FramePacket::clear_elt_sizea() {
  elt_sizea_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 FramePacket::_internal_elt_sizea() const {
  return elt_sizea_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 FramePacket::elt_sizea() const {
  // @@protoc_insertion_point(field_get:packet.FramePacket.elt_sizea)
  return _internal_elt_sizea();
}
inline void FramePacket::_internal_set_elt_sizea(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  elt_sizea_ = value;
}
inline void FramePacket::set_elt_sizea(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_elt_sizea(value);
  // @@protoc_insertion_point(field_set:packet.FramePacket.elt_sizea)
}

// int32 elt_sizeb = 7;
inline void FramePacket::clear_elt_sizeb() {
  elt_sizeb_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 FramePacket::_internal_elt_sizeb() const {
  return elt_sizeb_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 FramePacket::elt_sizeb() const {
  // @@protoc_insertion_point(field_get:packet.FramePacket.elt_sizeb)
  return _internal_elt_sizeb();
}
inline void FramePacket::_internal_set_elt_sizeb(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  elt_sizeb_ = value;
}
inline void FramePacket::set_elt_sizeb(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_elt_sizeb(value);
  // @@protoc_insertion_point(field_set:packet.FramePacket.elt_sizeb)
}

// int32 rowsb = 8;
inline void FramePacket::clear_rowsb() {
  rowsb_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 FramePacket::_internal_rowsb() const {
  return rowsb_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 FramePacket::rowsb() const {
  // @@protoc_insertion_point(field_get:packet.FramePacket.rowsb)
  return _internal_rowsb();
}
inline void FramePacket::_internal_set_rowsb(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  rowsb_ = value;
}
inline void FramePacket::set_rowsb(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_rowsb(value);
  // @@protoc_insertion_point(field_set:packet.FramePacket.rowsb)
}

// int32 colsb = 9;
inline void FramePacket::clear_colsb() {
  colsb_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 FramePacket::_internal_colsb() const {
  return colsb_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 FramePacket::colsb() const {
  // @@protoc_insertion_point(field_get:packet.FramePacket.colsb)
  return _internal_colsb();
}
inline void FramePacket::_internal_set_colsb(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  colsb_ = value;
}
inline void FramePacket::set_colsb(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_colsb(value);
  // @@protoc_insertion_point(field_set:packet.FramePacket.colsb)
}

// bytes mat_dataA = 5;
inline void FramePacket::clear_mat_dataa() {
  mat_dataa_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& FramePacket::mat_dataa() const {
  // @@protoc_insertion_point(field_get:packet.FramePacket.mat_dataA)
  return _internal_mat_dataa();
}
inline void FramePacket::set_mat_dataa(const std::string& value) {
  _internal_set_mat_dataa(value);
  // @@protoc_insertion_point(field_set:packet.FramePacket.mat_dataA)
}
inline std::string* FramePacket::mutable_mat_dataa() {
  // @@protoc_insertion_point(field_mutable:packet.FramePacket.mat_dataA)
  return _internal_mutable_mat_dataa();
}
inline const std::string& FramePacket::_internal_mat_dataa() const {
  return mat_dataa_.GetNoArena();
}
inline void FramePacket::_internal_set_mat_dataa(const std::string& value) {
  
  mat_dataa_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void FramePacket::set_mat_dataa(std::string&& value) {
  
  mat_dataa_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:packet.FramePacket.mat_dataA)
}
inline void FramePacket::set_mat_dataa(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  mat_dataa_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:packet.FramePacket.mat_dataA)
}
inline void FramePacket::set_mat_dataa(const void* value, size_t size) {
  
  mat_dataa_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:packet.FramePacket.mat_dataA)
}
inline std::string* FramePacket::_internal_mutable_mat_dataa() {
  
  return mat_dataa_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* FramePacket::release_mat_dataa() {
  // @@protoc_insertion_point(field_release:packet.FramePacket.mat_dataA)
  
  return mat_dataa_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void FramePacket::set_allocated_mat_dataa(std::string* mat_dataa) {
  if (mat_dataa != nullptr) {
    
  } else {
    
  }
  mat_dataa_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), mat_dataa);
  // @@protoc_insertion_point(field_set_allocated:packet.FramePacket.mat_dataA)
}

// bytes mat_dataB = 6;
inline void FramePacket::clear_mat_datab() {
  mat_datab_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& FramePacket::mat_datab() const {
  // @@protoc_insertion_point(field_get:packet.FramePacket.mat_dataB)
  return _internal_mat_datab();
}
inline void FramePacket::set_mat_datab(const std::string& value) {
  _internal_set_mat_datab(value);
  // @@protoc_insertion_point(field_set:packet.FramePacket.mat_dataB)
}
inline std::string* FramePacket::mutable_mat_datab() {
  // @@protoc_insertion_point(field_mutable:packet.FramePacket.mat_dataB)
  return _internal_mutable_mat_datab();
}
inline const std::string& FramePacket::_internal_mat_datab() const {
  return mat_datab_.GetNoArena();
}
inline void FramePacket::_internal_set_mat_datab(const std::string& value) {
  
  mat_datab_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void FramePacket::set_mat_datab(std::string&& value) {
  
  mat_datab_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:packet.FramePacket.mat_dataB)
}
inline void FramePacket::set_mat_datab(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  mat_datab_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:packet.FramePacket.mat_dataB)
}
inline void FramePacket::set_mat_datab(const void* value, size_t size) {
  
  mat_datab_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:packet.FramePacket.mat_dataB)
}
inline std::string* FramePacket::_internal_mutable_mat_datab() {
  
  return mat_datab_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* FramePacket::release_mat_datab() {
  // @@protoc_insertion_point(field_release:packet.FramePacket.mat_dataB)
  
  return mat_datab_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void FramePacket::set_allocated_mat_datab(std::string* mat_datab) {
  if (mat_datab != nullptr) {
    
  } else {
    
  }
  mat_datab_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), mat_datab);
  // @@protoc_insertion_point(field_set_allocated:packet.FramePacket.mat_dataB)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace packet

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_packet_2eproto
