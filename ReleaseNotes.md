# Mile.Mobility Release Notes

**Mile.Mobility 1.1.602.0**

- Introduce Mile.Mobility.Utilities.MemoryAccess for Memory Access Utilities.
  - Introduce following functions:
    - Atomic Operations:
      - MoMileInterlockedCompareExchange8
      - MoMileInterlockedCompareExchange16
      - MoMileInterlockedCompareExchange32
      - MoMileInterlockedCompareExchange64
      - MoMileInterlockedCompareExchangePointer
      - MoMileInterlockedExchange32
      - MoMileInterlockedExchangePointer
      - MoMileInterlockedIncrement32
      - MoMileInterlockedDecrement32
      - MoMileInterlockedAnd32
      - MoMileInterlockedOr32
      - MoMileInterlockedXor32
    - Memory Barrier:
      - MoMileCompilerBarrier
      - MoMileMemoryBarrier
- Improve the MSVC ARM32 target check logic for Mile.Mobility.Portable.Types.
- Fix the comment for Mile.Mobility.Utilities.FixedInteger.

**Mile.Mobility 1.1.564.0**

- Introduce Mile.Mobility.Utilities.FixedInteger for Fixed Width Integer
  Utilities.
  - Introduce following functions:
    - Checked Arithmetic:
      - MoMileFixedIntegerCheckedAddition8
      - MoMileFixedIntegerCheckedSubtraction8
      - MoMileFixedIntegerCheckedMultiplication8
      - MoMileFixedIntegerCheckedAddition16
      - MoMileFixedIntegerCheckedSubtraction16
      - MoMileFixedIntegerCheckedMultiplication16
      - MoMileFixedIntegerCheckedAddition32
      - MoMileFixedIntegerCheckedSubtraction32
      - MoMileFixedIntegerCheckedMultiplication32
      - MoMileFixedIntegerCheckedAddition64
      - MoMileFixedIntegerCheckedSubtraction64
      - MoMileFixedIntegerCheckedMultiplication64
      - MoMileFixedIntegerCheckedAddition
      - MoMileFixedIntegerCheckedSubtraction
      - MoMileFixedIntegerCheckedMultiplication
    - Read and Write:
      - MoMileFixedIntegerRead8
      - MoMileFixedIntegerWrite8
      - MoMileFixedIntegerReadBigEndian16
      - MoMileFixedIntegerWriteBigEndian16
      - MoMileFixedIntegerReadLittleEndian16
      - MoMileFixedIntegerWriteLittleEndian16
      - MoMileFixedIntegerReadBigEndian32
      - MoMileFixedIntegerWriteBigEndian32
      - MoMileFixedIntegerReadLittleEndian32
      - MoMileFixedIntegerWriteLittleEndian32
      - MoMileFixedIntegerReadBigEndian64
      - MoMileFixedIntegerWriteBigEndian64
      - MoMileFixedIntegerReadLittleEndian64
      - MoMileFixedIntegerWriteLittleEndian64
      - MoMileFixedIntegerReadBigEndian
      - MoMileFixedIntegerWriteBigEndian
      - MoMileFixedIntegerReadLittleEndian
      - MoMileFixedIntegerWriteLittleEndian
    - Sequence Compare:
      - MoMileFixedIntegerSequenceCompare8
      - MoMileFixedIntegerSequenceCompare16
      - MoMileFixedIntegerSequenceCompare32
      - MoMileFixedIntegerSequenceCompare64
      - MoMileFixedIntegerSequenceCompare
- Simplify the MO_FORCEINLINE definition in Mile.Mobility.Portable.Types.
- Add Mile.Mobility.Test project.

**Mile.Mobility 1.1.544.0**

- Improve Mile.Mobility.Portable.Types.h.
  - Introduce following macros:
    - MO_CONST
    - MO_VOID
    - MO_EXTERN_C
    - MO_NULL
    - \_Mo\_In\_, \_Mo\_In\_Opt\_
    - \_Mo\_Out\_, \_Mo\_Out\_Opt\_
    - \_Mo\_InOut\_, \_Mo\_InOut\_Opt\_
  - Fix the definitions of MO_UNREFERENCED_PARAMETER and MO_DECLSPEC_ALIGN.
  - Fix the comments.
- Introduce Mile.Mobility.Portable.Types.Legacy.h for legacy C definitions of
  Mile.Mobility.Portable.Types.h.
  - Move following macros from Mile.Mobility.Portable.Types.h to this header:
    - CONST
    - VOID
    - EXTERN_C
    - MILE_MOBILITY_ENABLE_MINIMUM_SAL
    - \_In\_, \_In\_opt\_
    - \_Out\_, \_Out\_opt\_
    - \_Inout\_, \_Inout\_opt\_
  - Introduce following types:
    - Windows SDK Workarounds
      - CHAR, SHORT, LONG, INT
- Update Mile.Project.Configurations to 1.0.1917.

**Mile.Mobility 1.0.372.0**

- Improve Mile.Mobility.Portable.Types.h.
  - Add pointer types definitions for MO_INTN and MO_UINTN.
  - Introduce following macros:
    - MO_FORCEINLINE
    - MO_NOINLINE
  - Introduce following constant values:
    - Platform Width
      - MO_POINTER_SIZE, MO_POINTER_WIDTH
  - Extend following definitions with MO_POINTER_SIZE macro:
    - MO_INTN, MO_UINTN
    - MO_INTN_MIN, MO_INTN_MAX, MO_UINTN_MAX

**Mile.Mobility 1.0.306.0**

- Improve Mile.Mobility.Portable.Types.h.
  - Introduce following macros:
    - MO_RESULT_SUCCESS_OK
    - MO_RESULT_SUCCESS_FALSE
    - MO_RESULT_ERROR_UNEXPECTED
    - MO_RESULT_ERROR_NOT_IMPLEMENTED
    - MO_RESULT_ERROR_OUT_OF_MEMORY
    - MO_RESULT_ERROR_INVALID_PARAMETER
    - MO_RESULT_ERROR_NO_INTERFACE
    - MO_RESULT_ERROR_INVALID_POINTER
    - MO_RESULT_ERROR_INVALID_HANDLE
    - MO_RESULT_ERROR_OPERATION_ABORTED
    - MO_RESULT_ERROR_FAIL
    - MO_RESULT_ERROR_ACCESS_DENIED
    - MO_RESULT_ERROR_PENDING
    - MO_RESULT_ERROR_OUT_OF_BOUNDS
    - MO_RESULT_ERROR_CHANGED_STATE
    - MO_RESULT_ERROR_ILLEGAL_STATE_CHANGE
    - MO_RESULT_ERROR_ILLEGAL_METHOD_CALL
    - MO_RESULT_ERROR_ILLEGAL_DELEGATE_ASSIGNMENT
  - Introduce following types:
    - Result Code
      - MO_RESULT
- Fix the source code file header comment format.

**Mile.Mobility 1.0.212.0**

- Improve Mile.Mobility.Portable.Types.h.
  - Introduce following macros:
    - MO_DECLSPEC_ALIGN
    - MO_ANYSIZE_ARRAY
  - Introduce following types:
    - Globally Unique Identifiers
      - MO_GUID
  - Fix the comments.

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
