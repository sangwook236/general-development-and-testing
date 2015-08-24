// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "AbcDetectorParam.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* AbcDetectorParam_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  AbcDetectorParam_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_AbcDetectorParam_2eproto() {
  protobuf_AddDesc_AbcDetectorParam_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "AbcDetectorParam.proto");
  GOOGLE_CHECK(file != NULL);
  AbcDetectorParam_descriptor_ = file->message_type(0);
  static const int AbcDetectorParam_offsets_[14] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AbcDetectorParam, desc_size_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AbcDetectorParam, desc_step_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AbcDetectorParam, window_desc_step_ratio_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AbcDetectorParam, boosting_rounds_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AbcDetectorParam, num_train_pos_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AbcDetectorParam, num_train_neg_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AbcDetectorParam, feature_type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AbcDetectorParam, param_version_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AbcDetectorParam, do_jitter_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AbcDetectorParam, bootstrap_fraction_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AbcDetectorParam, feature_full_orientation_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AbcDetectorParam, feature_orisize_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AbcDetectorParam, num_train_jitter_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AbcDetectorParam, num_train_bootstrap_),
  };
  AbcDetectorParam_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      AbcDetectorParam_descriptor_,
      AbcDetectorParam::default_instance_,
      AbcDetectorParam_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AbcDetectorParam, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(AbcDetectorParam, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(AbcDetectorParam));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_AbcDetectorParam_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    AbcDetectorParam_descriptor_, &AbcDetectorParam::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_AbcDetectorParam_2eproto() {
  delete AbcDetectorParam::default_instance_;
  delete AbcDetectorParam_reflection_;
}

void protobuf_AddDesc_AbcDetectorParam_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\026AbcDetectorParam.proto\"\240\003\n\020AbcDetector"
    "Param\022\021\n\tdesc_size\030\002 \001(\005\022\021\n\tdesc_step\030\003 "
    "\001(\005\022!\n\026window_desc_step_ratio\030\004 \001(\001:\0011\022\034"
    "\n\017boosting_rounds\030\001 \001(\005:\003500\022\031\n\rnum_trai"
    "n_pos\030\006 \001(\005:\002-1\022\031\n\rnum_train_neg\030\010 \001(\005:\002"
    "-1\022\033\n\014feature_type\030\n \001(\t:\005SHAPE\022\030\n\rparam"
    "_version\030\013 \001(\005:\0010\022\027\n\tdo_jitter\030\014 \001(\010:\004tr"
    "ue\022\035\n\022bootstrap_fraction\030\016 \001(\001:\0010\022\'\n\030fea"
    "ture_full_orientation\030\017 \001(\010:\005false\022\032\n\017fe"
    "ature_orisize\030\021 \001(\005:\0018\022\033\n\020num_train_jitt"
    "er\030\007 \001(\005:\0010\022\036\n\023num_train_bootstrap\030\t \001(\005"
    ":\0010", 443);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "AbcDetectorParam.proto", &protobuf_RegisterTypes);
  AbcDetectorParam::default_instance_ = new AbcDetectorParam();
  AbcDetectorParam::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_AbcDetectorParam_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_AbcDetectorParam_2eproto {
  StaticDescriptorInitializer_AbcDetectorParam_2eproto() {
    protobuf_AddDesc_AbcDetectorParam_2eproto();
  }
} static_descriptor_initializer_AbcDetectorParam_2eproto_;


// ===================================================================

const ::std::string AbcDetectorParam::_default_feature_type_("SHAPE");
#ifndef _MSC_VER
const int AbcDetectorParam::kDescSizeFieldNumber;
const int AbcDetectorParam::kDescStepFieldNumber;
const int AbcDetectorParam::kWindowDescStepRatioFieldNumber;
const int AbcDetectorParam::kBoostingRoundsFieldNumber;
const int AbcDetectorParam::kNumTrainPosFieldNumber;
const int AbcDetectorParam::kNumTrainNegFieldNumber;
const int AbcDetectorParam::kFeatureTypeFieldNumber;
const int AbcDetectorParam::kParamVersionFieldNumber;
const int AbcDetectorParam::kDoJitterFieldNumber;
const int AbcDetectorParam::kBootstrapFractionFieldNumber;
const int AbcDetectorParam::kFeatureFullOrientationFieldNumber;
const int AbcDetectorParam::kFeatureOrisizeFieldNumber;
const int AbcDetectorParam::kNumTrainJitterFieldNumber;
const int AbcDetectorParam::kNumTrainBootstrapFieldNumber;
#endif  // !_MSC_VER

AbcDetectorParam::AbcDetectorParam()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void AbcDetectorParam::InitAsDefaultInstance() {
}

AbcDetectorParam::AbcDetectorParam(const AbcDetectorParam& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void AbcDetectorParam::SharedCtor() {
  _cached_size_ = 0;
  desc_size_ = 0;
  desc_step_ = 0;
  window_desc_step_ratio_ = 1;
  boosting_rounds_ = 500;
  num_train_pos_ = -1;
  num_train_neg_ = -1;
  feature_type_ = const_cast< ::std::string*>(&_default_feature_type_);
  param_version_ = 0;
  do_jitter_ = true;
  bootstrap_fraction_ = 0;
  feature_full_orientation_ = false;
  feature_orisize_ = 8;
  num_train_jitter_ = 0;
  num_train_bootstrap_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

AbcDetectorParam::~AbcDetectorParam() {
  SharedDtor();
}

void AbcDetectorParam::SharedDtor() {
  if (feature_type_ != &_default_feature_type_) {
    delete feature_type_;
  }
  if (this != default_instance_) {
  }
}

void AbcDetectorParam::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* AbcDetectorParam::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return AbcDetectorParam_descriptor_;
}

const AbcDetectorParam& AbcDetectorParam::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_AbcDetectorParam_2eproto();  return *default_instance_;
}

AbcDetectorParam* AbcDetectorParam::default_instance_ = NULL;

AbcDetectorParam* AbcDetectorParam::New() const {
  return new AbcDetectorParam;
}

void AbcDetectorParam::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    desc_size_ = 0;
    desc_step_ = 0;
    window_desc_step_ratio_ = 1;
    boosting_rounds_ = 500;
    num_train_pos_ = -1;
    num_train_neg_ = -1;
    if (has_feature_type()) {
      if (feature_type_ != &_default_feature_type_) {
        feature_type_->assign(_default_feature_type_);
      }
    }
    param_version_ = 0;
  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    do_jitter_ = true;
    bootstrap_fraction_ = 0;
    feature_full_orientation_ = false;
    feature_orisize_ = 8;
    num_train_jitter_ = 0;
    num_train_bootstrap_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool AbcDetectorParam::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 boosting_rounds = 1 [default = 500];
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &boosting_rounds_)));
          set_has_boosting_rounds();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_desc_size;
        break;
      }
      
      // optional int32 desc_size = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_desc_size:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &desc_size_)));
          set_has_desc_size();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_desc_step;
        break;
      }
      
      // optional int32 desc_step = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_desc_step:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &desc_step_)));
          set_has_desc_step();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(33)) goto parse_window_desc_step_ratio;
        break;
      }
      
      // optional double window_desc_step_ratio = 4 [default = 1];
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED64) {
         parse_window_desc_step_ratio:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &window_desc_step_ratio_)));
          set_has_window_desc_step_ratio();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(48)) goto parse_num_train_pos;
        break;
      }
      
      // optional int32 num_train_pos = 6 [default = -1];
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_num_train_pos:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &num_train_pos_)));
          set_has_num_train_pos();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(56)) goto parse_num_train_jitter;
        break;
      }
      
      // optional int32 num_train_jitter = 7 [default = 0];
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_num_train_jitter:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &num_train_jitter_)));
          set_has_num_train_jitter();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(64)) goto parse_num_train_neg;
        break;
      }
      
      // optional int32 num_train_neg = 8 [default = -1];
      case 8: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_num_train_neg:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &num_train_neg_)));
          set_has_num_train_neg();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(72)) goto parse_num_train_bootstrap;
        break;
      }
      
      // optional int32 num_train_bootstrap = 9 [default = 0];
      case 9: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_num_train_bootstrap:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &num_train_bootstrap_)));
          set_has_num_train_bootstrap();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(82)) goto parse_feature_type;
        break;
      }
      
      // optional string feature_type = 10 [default = "SHAPE"];
      case 10: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_feature_type:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_feature_type()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->feature_type().data(), this->feature_type().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(88)) goto parse_param_version;
        break;
      }
      
      // optional int32 param_version = 11 [default = 0];
      case 11: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_param_version:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &param_version_)));
          set_has_param_version();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(96)) goto parse_do_jitter;
        break;
      }
      
      // optional bool do_jitter = 12 [default = true];
      case 12: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_do_jitter:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &do_jitter_)));
          set_has_do_jitter();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(113)) goto parse_bootstrap_fraction;
        break;
      }
      
      // optional double bootstrap_fraction = 14 [default = 0];
      case 14: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED64) {
         parse_bootstrap_fraction:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &bootstrap_fraction_)));
          set_has_bootstrap_fraction();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(120)) goto parse_feature_full_orientation;
        break;
      }
      
      // optional bool feature_full_orientation = 15 [default = false];
      case 15: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_feature_full_orientation:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &feature_full_orientation_)));
          set_has_feature_full_orientation();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(136)) goto parse_feature_orisize;
        break;
      }
      
      // optional int32 feature_orisize = 17 [default = 8];
      case 17: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_feature_orisize:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &feature_orisize_)));
          set_has_feature_orisize();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void AbcDetectorParam::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int32 boosting_rounds = 1 [default = 500];
  if (has_boosting_rounds()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->boosting_rounds(), output);
  }
  
  // optional int32 desc_size = 2;
  if (has_desc_size()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->desc_size(), output);
  }
  
  // optional int32 desc_step = 3;
  if (has_desc_step()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->desc_step(), output);
  }
  
  // optional double window_desc_step_ratio = 4 [default = 1];
  if (has_window_desc_step_ratio()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(4, this->window_desc_step_ratio(), output);
  }
  
  // optional int32 num_train_pos = 6 [default = -1];
  if (has_num_train_pos()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(6, this->num_train_pos(), output);
  }
  
  // optional int32 num_train_jitter = 7 [default = 0];
  if (has_num_train_jitter()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(7, this->num_train_jitter(), output);
  }
  
  // optional int32 num_train_neg = 8 [default = -1];
  if (has_num_train_neg()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(8, this->num_train_neg(), output);
  }
  
  // optional int32 num_train_bootstrap = 9 [default = 0];
  if (has_num_train_bootstrap()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(9, this->num_train_bootstrap(), output);
  }
  
  // optional string feature_type = 10 [default = "SHAPE"];
  if (has_feature_type()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->feature_type().data(), this->feature_type().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      10, this->feature_type(), output);
  }
  
  // optional int32 param_version = 11 [default = 0];
  if (has_param_version()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(11, this->param_version(), output);
  }
  
  // optional bool do_jitter = 12 [default = true];
  if (has_do_jitter()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(12, this->do_jitter(), output);
  }
  
  // optional double bootstrap_fraction = 14 [default = 0];
  if (has_bootstrap_fraction()) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(14, this->bootstrap_fraction(), output);
  }
  
  // optional bool feature_full_orientation = 15 [default = false];
  if (has_feature_full_orientation()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(15, this->feature_full_orientation(), output);
  }
  
  // optional int32 feature_orisize = 17 [default = 8];
  if (has_feature_orisize()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(17, this->feature_orisize(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* AbcDetectorParam::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int32 boosting_rounds = 1 [default = 500];
  if (has_boosting_rounds()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->boosting_rounds(), target);
  }
  
  // optional int32 desc_size = 2;
  if (has_desc_size()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->desc_size(), target);
  }
  
  // optional int32 desc_step = 3;
  if (has_desc_step()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->desc_step(), target);
  }
  
  // optional double window_desc_step_ratio = 4 [default = 1];
  if (has_window_desc_step_ratio()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(4, this->window_desc_step_ratio(), target);
  }
  
  // optional int32 num_train_pos = 6 [default = -1];
  if (has_num_train_pos()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, this->num_train_pos(), target);
  }
  
  // optional int32 num_train_jitter = 7 [default = 0];
  if (has_num_train_jitter()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(7, this->num_train_jitter(), target);
  }
  
  // optional int32 num_train_neg = 8 [default = -1];
  if (has_num_train_neg()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(8, this->num_train_neg(), target);
  }
  
  // optional int32 num_train_bootstrap = 9 [default = 0];
  if (has_num_train_bootstrap()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(9, this->num_train_bootstrap(), target);
  }
  
  // optional string feature_type = 10 [default = "SHAPE"];
  if (has_feature_type()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->feature_type().data(), this->feature_type().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        10, this->feature_type(), target);
  }
  
  // optional int32 param_version = 11 [default = 0];
  if (has_param_version()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(11, this->param_version(), target);
  }
  
  // optional bool do_jitter = 12 [default = true];
  if (has_do_jitter()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(12, this->do_jitter(), target);
  }
  
  // optional double bootstrap_fraction = 14 [default = 0];
  if (has_bootstrap_fraction()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(14, this->bootstrap_fraction(), target);
  }
  
  // optional bool feature_full_orientation = 15 [default = false];
  if (has_feature_full_orientation()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(15, this->feature_full_orientation(), target);
  }
  
  // optional int32 feature_orisize = 17 [default = 8];
  if (has_feature_orisize()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(17, this->feature_orisize(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int AbcDetectorParam::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int32 desc_size = 2;
    if (has_desc_size()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->desc_size());
    }
    
    // optional int32 desc_step = 3;
    if (has_desc_step()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->desc_step());
    }
    
    // optional double window_desc_step_ratio = 4 [default = 1];
    if (has_window_desc_step_ratio()) {
      total_size += 1 + 8;
    }
    
    // optional int32 boosting_rounds = 1 [default = 500];
    if (has_boosting_rounds()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->boosting_rounds());
    }
    
    // optional int32 num_train_pos = 6 [default = -1];
    if (has_num_train_pos()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->num_train_pos());
    }
    
    // optional int32 num_train_neg = 8 [default = -1];
    if (has_num_train_neg()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->num_train_neg());
    }
    
    // optional string feature_type = 10 [default = "SHAPE"];
    if (has_feature_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->feature_type());
    }
    
    // optional int32 param_version = 11 [default = 0];
    if (has_param_version()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->param_version());
    }
    
  }
  if (_has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    // optional bool do_jitter = 12 [default = true];
    if (has_do_jitter()) {
      total_size += 1 + 1;
    }
    
    // optional double bootstrap_fraction = 14 [default = 0];
    if (has_bootstrap_fraction()) {
      total_size += 1 + 8;
    }
    
    // optional bool feature_full_orientation = 15 [default = false];
    if (has_feature_full_orientation()) {
      total_size += 1 + 1;
    }
    
    // optional int32 feature_orisize = 17 [default = 8];
    if (has_feature_orisize()) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->feature_orisize());
    }
    
    // optional int32 num_train_jitter = 7 [default = 0];
    if (has_num_train_jitter()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->num_train_jitter());
    }
    
    // optional int32 num_train_bootstrap = 9 [default = 0];
    if (has_num_train_bootstrap()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->num_train_bootstrap());
    }
    
  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void AbcDetectorParam::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const AbcDetectorParam* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const AbcDetectorParam*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void AbcDetectorParam::MergeFrom(const AbcDetectorParam& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_desc_size()) {
      set_desc_size(from.desc_size());
    }
    if (from.has_desc_step()) {
      set_desc_step(from.desc_step());
    }
    if (from.has_window_desc_step_ratio()) {
      set_window_desc_step_ratio(from.window_desc_step_ratio());
    }
    if (from.has_boosting_rounds()) {
      set_boosting_rounds(from.boosting_rounds());
    }
    if (from.has_num_train_pos()) {
      set_num_train_pos(from.num_train_pos());
    }
    if (from.has_num_train_neg()) {
      set_num_train_neg(from.num_train_neg());
    }
    if (from.has_feature_type()) {
      set_feature_type(from.feature_type());
    }
    if (from.has_param_version()) {
      set_param_version(from.param_version());
    }
  }
  if (from._has_bits_[8 / 32] & (0xffu << (8 % 32))) {
    if (from.has_do_jitter()) {
      set_do_jitter(from.do_jitter());
    }
    if (from.has_bootstrap_fraction()) {
      set_bootstrap_fraction(from.bootstrap_fraction());
    }
    if (from.has_feature_full_orientation()) {
      set_feature_full_orientation(from.feature_full_orientation());
    }
    if (from.has_feature_orisize()) {
      set_feature_orisize(from.feature_orisize());
    }
    if (from.has_num_train_jitter()) {
      set_num_train_jitter(from.num_train_jitter());
    }
    if (from.has_num_train_bootstrap()) {
      set_num_train_bootstrap(from.num_train_bootstrap());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void AbcDetectorParam::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void AbcDetectorParam::CopyFrom(const AbcDetectorParam& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool AbcDetectorParam::IsInitialized() const {
  
  return true;
}

void AbcDetectorParam::Swap(AbcDetectorParam* other) {
  if (other != this) {
    std::swap(desc_size_, other->desc_size_);
    std::swap(desc_step_, other->desc_step_);
    std::swap(window_desc_step_ratio_, other->window_desc_step_ratio_);
    std::swap(boosting_rounds_, other->boosting_rounds_);
    std::swap(num_train_pos_, other->num_train_pos_);
    std::swap(num_train_neg_, other->num_train_neg_);
    std::swap(feature_type_, other->feature_type_);
    std::swap(param_version_, other->param_version_);
    std::swap(do_jitter_, other->do_jitter_);
    std::swap(bootstrap_fraction_, other->bootstrap_fraction_);
    std::swap(feature_full_orientation_, other->feature_full_orientation_);
    std::swap(feature_orisize_, other->feature_orisize_);
    std::swap(num_train_jitter_, other->num_train_jitter_);
    std::swap(num_train_bootstrap_, other->num_train_bootstrap_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata AbcDetectorParam::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = AbcDetectorParam_descriptor_;
  metadata.reflection = AbcDetectorParam_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
