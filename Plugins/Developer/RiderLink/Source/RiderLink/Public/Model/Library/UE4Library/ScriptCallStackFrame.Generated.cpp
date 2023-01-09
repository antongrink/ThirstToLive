//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a RdGen v1.10.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#include "ScriptCallStackFrame.Generated.h"

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
void ScriptCallStackFrame::initialize() {}
// primary ctor
ScriptCallStackFrame::ScriptCallStackFrame(FString entry_)
    : rd::IPolymorphicSerializable(), entry_(std::move(entry_)) {
  initialize();
}
// secondary constructor
// default ctors and dtors
// reader
ScriptCallStackFrame ScriptCallStackFrame::read(rd::SerializationCtx &ctx,
                                                rd::Buffer &buffer) {
  auto entry_ = rd::Polymorphic<FString>::read(ctx, buffer);
  ScriptCallStackFrame res{std::move(entry_)};
  return res;
}
// writer
void ScriptCallStackFrame::write(rd::SerializationCtx &ctx,
                                 rd::Buffer &buffer) const {
  rd::Polymorphic<std::decay_t<decltype(entry_)>>::write(ctx, buffer, entry_);
}
// virtual init
// identify
// getters
FString const &ScriptCallStackFrame::get_entry() const { return entry_; }
// intern
// equals trait
bool ScriptCallStackFrame::equals(rd::ISerializable const &object) const {
  auto const &other = dynamic_cast<ScriptCallStackFrame const &>(object);
  if (this == &other)
    return true;
  if (this->entry_ != other.entry_)
    return false;

  return true;
}
// equality operators
bool operator==(const ScriptCallStackFrame &lhs,
                const ScriptCallStackFrame &rhs) {
  if (lhs.type_name() != rhs.type_name())
    return false;
  return lhs.equals(rhs);
}
bool operator!=(const ScriptCallStackFrame &lhs,
                const ScriptCallStackFrame &rhs) {
  return !(lhs == rhs);
}
// hash code trait
size_t ScriptCallStackFrame::hashCode() const noexcept {
  size_t __r = 0;
  __r = __r * 31 + (rd::hash<FString>()(get_entry()));
  return __r;
}
// type name trait
std::string ScriptCallStackFrame::type_name() const {
  return "ScriptCallStackFrame";
}
// static type name trait
std::string ScriptCallStackFrame::static_type_name() {
  return "ScriptCallStackFrame";
}
// polymorphic to string
std::string ScriptCallStackFrame::toString() const {
  std::string res = "ScriptCallStackFrame\n";
  res += "\tentry = ";
  res += rd::to_string(entry_);
  res += '\n';
  return res;
}
// external to string
std::string to_string(const ScriptCallStackFrame &value) {
  return value.toString();
}
} // namespace EditorPlugin
} // namespace JetBrains

#ifdef _MSC_VER
#pragma warning(pop)
#endif
