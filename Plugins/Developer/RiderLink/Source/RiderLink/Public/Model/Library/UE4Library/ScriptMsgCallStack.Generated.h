//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a RdGen v1.10.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#ifndef SCRIPTMSGCALLSTACK_GENERATED_H
#define SCRIPTMSGCALLSTACK_GENERATED_H

#include "base/ISerializersOwner.h"
#include "base/IUnknownInstance.h"
#include "ext/RdExtBase.h"
#include "impl/RdList.h"
#include "impl/RdMap.h"
#include "impl/RdProperty.h"
#include "impl/RdSet.h"
#include "impl/RdSignal.h"
#include "protocol/Protocol.h"
#include "serialization/ArraySerializer.h"
#include "serialization/ISerializable.h"
#include "serialization/InternedSerializer.h"
#include "serialization/NullableSerializer.h"
#include "serialization/Polymorphic.h"
#include "serialization/SerializationCtx.h"
#include "serialization/Serializers.h"
#include "std/allocator.h"
#include "std/hash.h"
#include "std/to_string.h"
#include "task/RdCall.h"
#include "task/RdEndpoint.h"
#include "task/RdSymmetricCall.h"
#include "types/DateTime.h"
#include "util/enum.h"
#include "util/gen_util.h"

#include <cstdint>
#include <cstring>
#include <ctime>
#include <vector>

#include "instantiations_UE4Library.h"
#include "thirdparty.hpp"

#include "IScriptMsg.Generated.h"
#include "Runtime/Core/Public/Containers/UnrealString.h"
#include "UE4Library/IScriptCallStack.Generated.h"

#include "Runtime/Core/Public/Containers/Array.h"
#include "Runtime/Core/Public/Containers/ContainerAllocationPolicies.h"
#include "UE4TypesMarshallers.h"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4250)
#pragma warning(disable : 4307)
#pragma warning(disable : 4267)
#pragma warning(disable : 4244)
#pragma warning(disable : 4100)
#endif

/// <summary>
/// <p>Generated from: UE4Library.kt:182</p>
/// </summary>
namespace JetBrains {
namespace EditorPlugin {

class RIDERLINK_API ScriptMsgCallStack : public IScriptMsg {

private:
  // custom serializers

public:
  // constants

protected:
  // fields
  FString message_;
  rd::Wrapper<IScriptCallStack> scriptCallStack_;

private:
  // initializer
  void initialize();

public:
  // primary ctor
  ScriptMsgCallStack(FString message_,
                     rd::Wrapper<IScriptCallStack> scriptCallStack_);

  // default ctors and dtors

  ScriptMsgCallStack() = delete;

  ScriptMsgCallStack(ScriptMsgCallStack const &) = default;

  ScriptMsgCallStack &operator=(ScriptMsgCallStack const &) = default;

  ScriptMsgCallStack(ScriptMsgCallStack &&) = default;

  ScriptMsgCallStack &operator=(ScriptMsgCallStack &&) = default;

  virtual ~ScriptMsgCallStack() = default;

  // reader
  static ScriptMsgCallStack read(rd::SerializationCtx &ctx, rd::Buffer &buffer);

  // writer
  void write(rd::SerializationCtx &ctx, rd::Buffer &buffer) const override;

  // virtual init

  // identify

  // getters
  FString const &get_message() const;
  IScriptCallStack const &get_scriptCallStack() const;

  // intern

private:
  // equals trait
  bool equals(rd::ISerializable const &object) const override;

public:
  // equality operators
  friend bool operator==(const ScriptMsgCallStack &lhs,
                         const ScriptMsgCallStack &rhs);
  friend bool operator!=(const ScriptMsgCallStack &lhs,
                         const ScriptMsgCallStack &rhs);
  // hash code trait
  size_t hashCode() const noexcept override;
  // type name trait
  std::string type_name() const override;
  // static type name trait
  static std::string static_type_name();

private:
  // polymorphic to string
  std::string toString() const override;

public:
  // external to string
  friend std::string to_string(const ScriptMsgCallStack &value);
};

} // namespace EditorPlugin
} // namespace JetBrains

// hash code trait
namespace rd {

template <> struct hash<JetBrains::EditorPlugin::ScriptMsgCallStack> {
  size_t operator()(
      const JetBrains::EditorPlugin::ScriptMsgCallStack &value) const noexcept {
    return value.hashCode();
  }
};

} // namespace rd

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif // SCRIPTMSGCALLSTACK_GENERATED_H