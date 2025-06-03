﻿# Mile.Mobility Release Notes

**Mile.Mobility 1.0.2xx.0**

- Improve Mile.Mobility.Portable.Types.h.
  - Introduce following macros:
    - MO_DECLSPEC_ALIGN
    - MO_ANYSIZE_ARRAY

**Mile.Mobility 1.0.206.0**

- Improve Mile.Mobility.Portable.Types.h.
  - Introduce following macros:
    - \_Inout\_
    - \_Inout\_opt\_

**Mile.Mobility 1.0.172.0**

- Improve Mile.Mobility.Portable.Types.h.
  - Introduce following types:
    - Constant Character
      - MO_CONSTANT_CHAR, MO_CONSTANT_WIDE_CHAR
  - Fix the definitions of MO_CONSTANT_STRING and MO_CONSTANT_WIDE_STRING.

**Mile.Mobility 1.0.165.0**

- Improve Mile.Mobility.Portable.Types.h.
  - Introduce following macros:
    - MO_GET_ALIGNED_SIZE
    - MO_GET_VARIABLE_ADDRESS
    - MO_VARIABLE_ARGUMENT_START
    - MO_VARIABLE_ARGUMENT_READ
    - MO_VARIABLE_ARGUMENT_END
    - MO_VARIABLE_ARGUMENT_COPY
  - Introduce following types:
    - Variable Argument List
      - MO_VARIABLE_ARGUMENT_LIST

**Mile.Mobility 1.0.156.0**

- Improve Mile.Mobility.Portable.Types.h.
  - Introduce following macros:
    - MO_DECLARE_HANDLE
    - MO_MAX
    - MO_MIN
    - MO_ABS
    - MO_ARRAY_SIZE
  - Introduce following types:
    - Pointer
      - MO_POINTER
    - Constant Pointer
      - MO_CONSTANT_POINTER

**Mile.Mobility 1.0.142.0**

- Make MO_INT* and MO_UINT* macro constants preprocessor friendly.

**Mile.Mobility 1.0.137.0**

- Improve Mile.Mobility.Portable.Types.h.
  - Introduce following macros:
    - NULL
    - nullptr
    - MO_UNREFERENCED_PARAMETER
    - MO_FIELD_OFFSET
    - MO_FIELD_SIZE
    - MO_FIELD_SIZE_THROUGH
    - MO_FIELD_CONTAINS
    - MO_C_STATIC_ASSERT

**Mile.Mobility 1.0.136.0**

- Initial release.
- Introduce Mile.Mobility.Portable.Types.h for standardized C definitions.
  - Introduce following macros:
    - CONST
    - VOID
    - EXTERN_C
    - MILE_MOBILITY_ENABLE_MINIMUM_SAL
    - \_In\_, \_In\_opt\_, \_Out\_, \_Out\_opt\_
    - MOAPI
  - Introduce following types:
    - Signed Integer
      - MO_INT8, MO_INT16, MO_INT32, MO_INT64
    - Unsigned Integer
      - MO_UINT8, MO_UINT16, MO_UINT32, MO_UINT64
    - Native Integer
      - MO_INTN, MO_UINTN
    - Bool
      - MO_BOOL
    - Character 
      - MO_CHAR, MO_WIDE_CHAR
    - String
      - MO_STRING, MO_WIDE_STRING
    - Constant String
      - MO_CONSTANT_STRING, MO_CONSTANT_WIDE_STRING
  - Introduce following constant values:
    - Signed Integer 
      - MO_INT8_MIN, MO_INT16_MIN, MO_INT32_MIN, MO_INT64_MIN
      - MO_INT8_MAX, MO_INT16_MAX, MO_INT32_MAX, MO_INT64_MAX
    - Unsigned Integer
      - MO_UINT8_MAX, MO_UINT16_MAX, MO_UINT32_MAX, MO_UINT64_MAX
    - Native Integer
      - MO_INTN_MIN, MO_INTN_MAX, MO_UINTN_MAX
    - Bool
      - MO_FALSE, MO_TRUE
    - Character 
      - MO_CHAR_MIN, MO_CHAR_MAX, MO_WIDE_CHAR_MIN, MO_WIDE_CHAR_MAX
- Provide NuGet package.
