//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a RdGen v1.10.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#include "RequestSucceed.Generated.h"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4250)
#pragma warning(disable : 4307)
#pragma warning(disable : 4267)
#pragma warning(disable : 4244)
#pragma warning(disable : 4100)
#endif

namespace JetBrains {
namespace EditorPlugin {
// companion
// constants
// initializer
void RequestSucceed::initialize() {}
// primary ctor
RequestSucceed::RequestSucceed(int32_t requestID_)
    : RequestResultBase(std::move(requestID_))

{
  initialize();
}
// secondary constructor
// default ctors and dtors
// reader
RequestSucceed RequestSucceed::read(rd::SerializationCtx &ctx,
                                    rd::Buffer &buffer) {
  auto requestID_ = buffer.read_integral<int32_t>();
  RequestSucceed res{std::move(requestID_)};
  return res;
}
// writer
void RequestSucceed::write(rd::SerializationCtx &ctx,
                           rd::Buffer &buffer) const {
  buffer.write_integral(requestID_);
}
// virtual init
// identify
// getters
// intern
// equals trait
bool RequestSucceed::equals(rd::ISerializable const &object) const {
  auto const &other = dynamic_cast<RequestSucceed const &>(object);
  if (this == &other)
    return true;
  if (this->requestID_ != other.requestID_)
    return false;

  return true;
}
// equality operators
bool operator==(const RequestSucceed &lhs, const RequestSucceed &rhs) {
  if (lhs.type_name() != rhs.type_name())
    return false;
  return lhs.equals(rhs);
}
bool operator!=(const RequestSucceed &lhs, const RequestSucceed &rhs) {
  return !(lhs == rhs);
}
// hash code trait
size_t RequestSucceed::hashCode() const noexcept {
  size_t __r = 0;
  __r = __r * 31 + (rd::hash<int32_t>()(get_requestID()));
  return __r;
}
// type name trait
std::string RequestSucceed::type_name() const { return "RequestSucceed"; }
// static type name trait
std::string RequestSucceed::static_type_name() { return "RequestSucceed"; }
// polymorphic to string
std::string RequestSucceed::toString() const {
  std::string res = "RequestSucceed\n";
  res += "\trequestID = ";
  res += rd::to_string(requestID_);
  res += '\n';
  return res;
}
// external to string
std::string to_string(const RequestSucceed &value) { return value.toString(); }
} // namespace EditorPlugin
} // namespace JetBrains

#ifdef _MSC_VER
#pragma warning(pop)
#endif
