# Definitions in Mile.Mobility.Portable.Types.h

- All types in this header file are C types with the C++ compatibility.
- Every mentioned type definition is prefixed with "MO_", has a corresponding
  pointer type definition prefixed with "PMO_".
- All mentioned constant value definitions are prefixed with "MO_".

### Macros

- CONST
- VOID
- EXTERN_C
- MILE_MOBILITY_ENABLE_MINIMUM_SAL
- \_In\_, \_In\_opt\_, \_Out\_, \_Out\_opt\_
- MOAPI
- NULL
- nullptr
- MO_UNREFERENCED_PARAMETER
- MO_FIELD_OFFSET
- MO_FIELD_SIZE
- MO_FIELD_SIZE_THROUGH
- MO_FIELD_CONTAINS
- MO_C_STATIC_ASSERT
- MO_DECLARE_HANDLE
- MO_MAX
- MO_MIN
- MO_ABS
- MO_ARRAY_SIZE

### Types

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
- Pointer
  - MO_POINTER
- Constant Pointer
  - MO_CONSTANT_POINTER

### Constant Values

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
