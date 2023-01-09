//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a RdGen v1.10.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#ifndef ISCRIPTCALLSTACK_GENERATED_H
#define ISCRIPTCALLSTACK_GENERATED_H

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
/// <p>Generated from: UE4Library.kt:150</p>
/// </summary>
namespace JetBrains {
namespace EditorPlugin {

// abstract
class RIDERLINK_API IScriptCallStack : public rd::IPolymorphicSerializable {

private:
  // custom serializers

public:
  // constants
  static constexpr rd::wstring_view header{L"Script call stack:", 18};

protected:
  // fields

private:
  // initializer
  void initialize();

public:
  // default ctors and dtors

  IScriptCallStack();

  IScriptCallStack(IScriptCallStack const &) = default;

  IScriptCallStack &operator=(IScriptCallStack const &) = default;

  IScriptCallStack(IScriptCallStack &&) = default;

  IScriptCallStack &operator=(IScriptCallStack &&) = default;

  virtual ~IScriptCallStack() = default;

  // reader
  static rd::Wrapper<IScriptCallStack>
  readUnknownInstance(rd::SerializationCtx &ctx, rd::Buffer &buffer,
                      rd::RdId const &unknownId, int32_t size);

  // writer
  virtual void write(rd::SerializationCtx &ctx,
                     rd::Buffer &buffer) const override = 0;

  // virtual init

  // identify

  // getters

  // intern

private:
  // equals trait

public:
  // equality operators
  friend bool operator==(const IScriptCallStack &lhs,
                         const IScriptCallStack &rhs);
  friend bool operator!=(const IScriptCallStack &lhs,
                         const IScriptCallStack &rhs);
  // hash code trait
  virtual size_t hashCode() const noexcept override = 0;
  // type name trait
  std::string type_name() const override;
  // static type name trait
  static std::string static_type_name();

private:
  // polymorphic to string
  std::string toString() const override;

public:
  // external to string
  friend std::string to_string(const IScriptCallStack &value);
};

} // namespace EditorPlugin
} // namespace JetBrains

// hash code trait
namespace rd {

template <> struct hash<JetBrains::EditorPlugin::IScriptCallStack> {
  size_t operator()(
      const JetBrains::EditorPlugin::IScriptCallStack &value) const noexcept {
    return value.hashCode();
  }
};

} // namespace rd

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#endif // ISCRIPTCALLSTACK_GENERATED_H
