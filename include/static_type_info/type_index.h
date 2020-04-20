#pragma once

#include <static_type_info/hash.h>
#include <static_type_info/type_name.h>

namespace static_type_info {

  using TypeIndex = uint64_t;

  template <class T> constexpr TypeIndex getTypeIndex() {
    return hash_64_fnv1a_const(getTypeName<T>());
  }

}  // namespace static_type_info
