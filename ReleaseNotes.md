# Mile.Mobility Release Notes

**Mile.Mobility 1.0.134.0**

- Initial release.
- Introduce Mile.Mobility.Portable.Types.h for standardized C definitions.
  - Introduce following macros:
    - CONST
    - VOID
    - EXTERN_C
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
      - MO_STRING, MO_WIDE_STRING, 
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
