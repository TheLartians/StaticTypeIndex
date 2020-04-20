[![Actions Status](https://github.com/TheLartians/StaticTypeInfo/workflows/MacOS/badge.svg)](https://github.com/TheLartians/StaticTypeInfo/actions)
[![Actions Status](https://github.com/TheLartians/StaticTypeInfo/workflows/Windows/badge.svg)](https://github.com/TheLartians/StaticTypeInfo/actions)
[![Actions Status](https://github.com/TheLartians/StaticTypeInfo/workflows/Ubuntu/badge.svg)](https://github.com/TheLartians/StaticTypeInfo/actions)
[![Actions Status](https://github.com/TheLartians/StaticTypeInfo/workflows/Style/badge.svg)](https://github.com/TheLartians/StaticTypeInfo/actions)
[![Actions Status](https://github.com/TheLartians/StaticTypeInfo/workflows/Install/badge.svg)](https://github.com/TheLartians/StaticTypeInfo/actions)
[![codecov](https://codecov.io/gh/TheLartians/StaticTypeInfo/branch/master/graph/badge.svg)](https://codecov.io/gh/TheLartians/StaticTypeInfo)

# StaticTypeInfo

A simple C++17 compile-time type info library. 

## API

The header-only library exposes two main `constexpr` functions: `constexpr TypeName getTypeName<T>()` and `constexpr TypeIndex getTypeIndex<T>()`.
The TypeIndex may be used as a key in any hash-based container.

```cpp
#include <iostream>
#include <static_type_info.h>

void example() {
  using namespace static_type_info;

  // compile-time type names
  constexpr auto name = getTypeName<int>();
  static_assert(name == "int");

  // compile-time type indices
  constexpr auto intIdx = getTypeIndex<int>();
  constexpr auto floatIdx = getTypeIndex<float>();
  static_assert(intIdx != floatIdx);

  // combine both in a single type
  constexpr auto typeID = getTypeID<int>();
  static_assert(typeID.name == "int");
  static_assert(typeID.index == getTypeIndex<int>());
}
```

## How it works

The type name is extracted from the macro `__PRETTY_FUNCTION__` (clang/gcc) or `__FUNCSIG__` (on MSVC) inside a probe function and converted to a `string_view` using the `constexpr` constructor.
The type index is a 64 bit fnv1a hash of the type name.

## Compatibility

The library has been tested with AppleClang 11, Visual Studio 16 2019, and gcc-9.

## How to integrate

Use [CPM.cmake](https://github.com/TheLartians/CPM.cmake) to easily add the headers to your CMake project.

```cmake
CPMAddPackage(
  NAME StaticTypeInfo
  VERSION 1.1
  GIT_REPOSITORY https://github.com/TheLartians/StaticTypeInfo
)

target_link_libraries(myProject StaticTypeInfo)
```

## Licence

The library is released under the MIT license.
See the [LICENSE](LICENSE) for more info.
