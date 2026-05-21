/*
 * PROJECT:    Mouri Internal Library Essentials
 * FILE:       Mile.Mobility.Utilities.FixedInteger.h
 * PURPOSE:    Definition for Mobility Fixed Width Integer Utilities
 *
 * LICENSE:    The MIT License
 *
 * MAINTAINER: MouriNaruto (Kenji.Mouri@outlook.com)
 */

#ifndef MILE_MOBILITY_UTILITIES_FIXEDINTEGER
#define MILE_MOBILITY_UTILITIES_FIXEDINTEGER

#include "Mile.Mobility.Portable.Types.h"

/*
 * - All functions in this header file are C functions.
 * - All functions are prefixed with "MoMileFixedInteger".
 * - Only depends on Mile.Mobility.Portable.Types.h.
 */

/**
  * @brief Performs checked addition of two integer values with a fixed 8-bit
  *        width.
  * @param Result The pointer to the variable that receives the result of
  *               (Left + Right). Result must not be null. If the return value
  *               is MO_FALSE, the value pointed to by Result is not modified.
  * @param Signed Indicates whether the fixed 8-bit integer values are signed
  *               (MO_TRUE) or unsigned (MO_FALSE). If MO_FALSE, the valid range
  *               is 0 to (2 ^ 8) - 1. If MO_TRUE, Left and Right are
  *               interpreted as signed integer values represented as 8-bit
  *               unsigned integer values; a negative value -X is represented as
  *               the 8-bit unsigned integer value (2 ^ 8) - X, and the valid
  *               range is -(2 ^ 7) to (2 ^ 7) - 1. The result is returned using
  *               the same representation.
  * @param Left The first operand.
  * @param Right The second operand.
  * @return MO_TRUE if the addition succeeds and the result is representable in
  *         the range determined by the fixed 8-bit width and Signed. MO_FALSE
  *         if Result is null or the result is out of range.
  */
MO_EXTERN_C MO_BOOL MOAPI MoMileFixedIntegerCheckedAddition8(
    _Mo_Out_ PMO_UINT8 Result,
    _Mo_In_ MO_BOOL Signed,
    _Mo_In_ MO_UINT8 Left,
    _Mo_In_ MO_UINT8 Right);

/**
  * @brief Performs checked subtraction of two integer values with a fixed 8-bit
  *        width.
  * @param Result The pointer to the variable that receives the result of
  *               (Left - Right). Result must not be null. If the return value
  *               is MO_FALSE, the value pointed to by Result is not modified.
  * @param Signed Indicates whether the fixed 8-bit integer values are signed
  *               (MO_TRUE) or unsigned (MO_FALSE). If MO_FALSE, the valid range
  *               is 0 to (2 ^ 8) - 1. If MO_TRUE, Left and Right are
  *               interpreted as signed integer values represented as 8-bit
  *               unsigned integer values; a negative value -X is represented as
  *               the 8-bit unsigned integer value (2 ^ 8) - X, and the valid
  *               range is -(2 ^ 7) to (2 ^ 7) - 1. The result is returned using
  *               the same representation.
  * @param Left The first operand.
  * @param Right The second operand.
  * @return MO_TRUE if the subtraction succeeds and the result is representable
  *         in the range determined by the fixed 8-bit width and Signed.
  *         MO_FALSE if Result is null or the result is out of range.
  */
MO_EXTERN_C MO_BOOL MOAPI MoMileFixedIntegerCheckedSubtraction8(
    _Mo_Out_ PMO_UINT8 Result,
    _Mo_In_ MO_BOOL Signed,
    _Mo_In_ MO_UINT8 Left,
    _Mo_In_ MO_UINT8 Right);

/**
  * @brief Performs checked multiplication of two integer values with a fixed
  *        8-bit width.
  * @param Result The pointer to the variable that receives the result of
  *               (Left * Right). Result must not be null. If the return value
  *               is MO_FALSE, the value pointed to by Result is not modified.
  * @param Signed Indicates whether the fixed 8-bit integer values are signed
  *               (MO_TRUE) or unsigned (MO_FALSE). If MO_FALSE, the valid range
  *               is 0 to (2 ^ 8) - 1. If MO_TRUE, Left and Right are
  *               interpreted as signed integer values represented as 8-bit
  *               unsigned integer values; a negative value -X is represented as
  *               the 8-bit unsigned integer value (2 ^ 8) - X, and the valid
  *               range is -(2 ^ 7) to (2 ^ 7) - 1. The result is returned using
  *               the same representation.
  * @param Left The first operand.
  * @param Right The second operand.
  * @return MO_TRUE if the multiplication succeeds and the result is
  *         representable in the range determined by the fixed 8-bit width and
  *         Signed. MO_FALSE if Result is null or the result is out of range.
  */
MO_EXTERN_C MO_BOOL MOAPI MoMileFixedIntegerCheckedMultiplication8(
    _Mo_Out_ PMO_UINT8 Result,
    _Mo_In_ MO_BOOL Signed,
    _Mo_In_ MO_UINT8 Left,
    _Mo_In_ MO_UINT8 Right);

/**
  * @brief Performs checked addition of two integer values with a fixed 16-bit
  *        width.
  * @param Result The pointer to the variable that receives the result of
  *               (Left + Right). Result must not be null. If the return value
  *               is MO_FALSE, the value pointed to by Result is not modified.
  * @param Signed Indicates whether the fixed 16-bit integer values are signed
  *               (MO_TRUE) or unsigned (MO_FALSE). If MO_FALSE, the valid range
  *               is 0 to (2 ^ 16) - 1. If MO_TRUE, Left and Right are
  *               interpreted as signed integer values represented as 16-bit
  *               unsigned integer values; a negative value -X is represented as
  *               the 16-bit unsigned integer value (2 ^ 16) - X, and the valid
  *               range is -(2 ^ 15) to (2 ^ 15) - 1. The result is returned
  *               using the same representation.
  * @param Left The first operand.
  * @param Right The second operand.
  * @return MO_TRUE if the addition succeeds and the result is representable in
  *         the range determined by the fixed 16-bit width and Signed. MO_FALSE
  *         if Result is null or the result is out of range.
  */
MO_EXTERN_C MO_BOOL MOAPI MoMileFixedIntegerCheckedAddition16(
    _Mo_Out_ PMO_UINT16 Result,
    _Mo_In_ MO_BOOL Signed,
    _Mo_In_ MO_UINT16 Left,
    _Mo_In_ MO_UINT16 Right);

/**
  * @brief Performs checked subtraction of two integer values with a fixed
  *        16-bit width.
  * @param Result The pointer to the variable that receives the result of
  *               (Left - Right). Result must not be null. If the return value
  *               is MO_FALSE, the value pointed to by Result is not modified.
  * @param Signed Indicates whether the fixed 16-bit integer values are signed
  *               (MO_TRUE) or unsigned (MO_FALSE). If MO_FALSE, the valid range
  *               is 0 to (2 ^ 16) - 1. If MO_TRUE, Left and Right are
  *               interpreted as signed integer values represented as 16-bit
  *               unsigned integer values; a negative value -X is represented as
  *               the 16-bit unsigned integer value (2 ^ 16) - X, and the valid
  *               range is -(2 ^ 15) to (2 ^ 15) - 1. The result is returned
  *               using the same representation.
  * @param Left The first operand.
  * @param Right The second operand.
  * @return MO_TRUE if the subtraction succeeds and the result is representable
  *         in the range determined by the fixed 16-bit width and Signed.
  *         MO_FALSE if Result is null or the result is out of range.
  */
MO_EXTERN_C MO_BOOL MOAPI MoMileFixedIntegerCheckedSubtraction16(
    _Mo_Out_ PMO_UINT16 Result,
    _Mo_In_ MO_BOOL Signed,
    _Mo_In_ MO_UINT16 Left,
    _Mo_In_ MO_UINT16 Right);

/**
  * @brief Performs checked multiplication of two integer values with a fixed
  *        16-bit width.
  * @param Result The pointer to the variable that receives the result of
  *               (Left * Right). Result must not be null. If the return value
  *               is MO_FALSE, the value pointed to by Result is not modified.
  * @param Signed Indicates whether the fixed 16-bit integer values are signed
  *               (MO_TRUE) or unsigned (MO_FALSE). If MO_FALSE, the valid range
  *               is 0 to (2 ^ 16) - 1. If MO_TRUE, Left and Right are
  *               interpreted as signed integer values represented as 16-bit
  *               unsigned integer values; a negative value -X is represented as
  *               the 16-bit unsigned integer value (2 ^ 16) - X, and the valid
  *               range is -(2 ^ 15) to (2 ^ 15) - 1. The result is returned
  *               using the same representation.
  * @param Left The first operand.
  * @param Right The second operand.
  * @return MO_TRUE if the multiplication succeeds and the result is
  *         representable in the range determined by the fixed 16-bit width and
  *         Signed. MO_FALSE if Result is null or the result is out of range.
  */
MO_EXTERN_C MO_BOOL MOAPI MoMileFixedIntegerCheckedMultiplication16(
    _Mo_Out_ PMO_UINT16 Result,
    _Mo_In_ MO_BOOL Signed,
    _Mo_In_ MO_UINT16 Left,
    _Mo_In_ MO_UINT16 Right);

/**
  * @brief Performs checked addition of two integer values with a fixed 32-bit
  *        width.
  * @param Result The pointer to the variable that receives the result of
  *               (Left + Right). Result must not be null. If the return value
  *               is MO_FALSE, the value pointed to by Result is not modified.
  * @param Signed Indicates whether the fixed 32-bit integer values are signed
  *               (MO_TRUE) or unsigned (MO_FALSE). If MO_FALSE, the valid range
  *               is 0 to (2 ^ 32) - 1. If MO_TRUE, Left and Right are
  *               interpreted as signed integer values represented as 32-bit
  *               unsigned integer values; a negative value -X is represented as
  *               the 32-bit unsigned integer value (2 ^ 32) - X, and the valid
  *               range is -(2 ^ 31) to (2 ^ 31) - 1. The result is returned
  *               using the same representation.
  * @param Left The first operand.
  * @param Right The second operand.
  * @return MO_TRUE if the addition succeeds and the result is representable in
  *         the range determined by the fixed 32-bit width and Signed. MO_FALSE
  *         if Result is null or the result is out of range.
  */
MO_EXTERN_C MO_BOOL MOAPI MoMileFixedIntegerCheckedAddition32(
    _Mo_Out_ PMO_UINT32 Result,
    _Mo_In_ MO_BOOL Signed,
    _Mo_In_ MO_UINT32 Left,
    _Mo_In_ MO_UINT32 Right);

/**
  * @brief Performs checked subtraction of two integer values with a fixed
  *        32-bit width.
  * @param Result The pointer to the variable that receives the result of
  *               (Left - Right). Result must not be null. If the return value
  *               is MO_FALSE, the value pointed to by Result is not modified.
  * @param Signed Indicates whether the fixed 32-bit integer values are signed
  *               (MO_TRUE) or unsigned (MO_FALSE). If MO_FALSE, the valid range
  *               is 0 to (2 ^ 32) - 1. If MO_TRUE, Left and Right are
  *               interpreted as signed integer values represented as 32-bit
  *               unsigned integer values; a negative value -X is represented as
  *               the 32-bit unsigned integer value (2 ^ 32) - X, and the valid
  *               range is -(2 ^ 31) to (2 ^ 31) - 1. The result is returned
  *               using the same representation.
  * @param Left The first operand.
  * @param Right The second operand.
  * @return MO_TRUE if the subtraction succeeds and the result is representable
  *         in the range determined by the fixed 32-bit width and Signed.
  *         MO_FALSE if Result is null or the result is out of range.
  */
MO_EXTERN_C MO_BOOL MOAPI MoMileFixedIntegerCheckedSubtraction32(
    _Mo_Out_ PMO_UINT32 Result,
    _Mo_In_ MO_BOOL Signed,
    _Mo_In_ MO_UINT32 Left,
    _Mo_In_ MO_UINT32 Right);

/**
  * @brief Performs checked multiplication of two integer values with a fixed
  *        32-bit width.
  * @param Result The pointer to the variable that receives the result of
  *               (Left * Right). Result must not be null. If the return value
  *               is MO_FALSE, the value pointed to by Result is not modified.
  * @param Signed Indicates whether the fixed 32-bit integer values are signed
  *               (MO_TRUE) or unsigned (MO_FALSE). If MO_FALSE, the valid range
  *               is 0 to (2 ^ 32) - 1. If MO_TRUE, Left and Right are
  *               interpreted as signed integer values represented as 32-bit
  *               unsigned integer values; a negative value -X is represented as
  *               the 32-bit unsigned integer value (2 ^ 32) - X, and the valid
  *               range is -(2 ^ 31) to (2 ^ 31) - 1. The result is returned
  *               using the same representation.
  * @param Left The first operand.
  * @param Right The second operand.
  * @return MO_TRUE if the multiplication succeeds and the result is
  *         representable in the range determined by the fixed 32-bit width and
  *         Signed. MO_FALSE if Result is null or the result is out of range.
  */
MO_EXTERN_C MO_BOOL MOAPI MoMileFixedIntegerCheckedMultiplication32(
    _Mo_Out_ PMO_UINT32 Result,
    _Mo_In_ MO_BOOL Signed,
    _Mo_In_ MO_UINT32 Left,
    _Mo_In_ MO_UINT32 Right);

/**
  * @brief Performs checked addition of two integer values with a fixed 64-bit
  *        width.
  * @param Result The pointer to the variable that receives the result of
  *               (Left + Right). Result must not be null. If the return value
  *               is MO_FALSE, the value pointed to by Result is not modified.
  * @param Signed Indicates whether the fixed 64-bit integer values are signed
  *               (MO_TRUE) or unsigned (MO_FALSE). If MO_FALSE, the valid range
  *               is 0 to (2 ^ 64) - 1. If MO_TRUE, Left and Right are
  *               interpreted as signed integer values represented as 64-bit
  *               unsigned integer values; a negative value -X is represented as
  *               the 64-bit unsigned integer value (2 ^ 64) - X, and the valid
  *               range is -(2 ^ 63) to (2 ^ 63) - 1. The result is returned
  *               using the same representation.
  * @param Left The first operand.
  * @param Right The second operand.
  * @return MO_TRUE if the addition succeeds and the result is representable in
  *         the range determined by the fixed 64-bit width and Signed. MO_FALSE
  *         if Result is null or the result is out of range.
  */
MO_EXTERN_C MO_BOOL MOAPI MoMileFixedIntegerCheckedAddition64(
    _Mo_Out_ PMO_UINT64 Result,
    _Mo_In_ MO_BOOL Signed,
    _Mo_In_ MO_UINT64 Left,
    _Mo_In_ MO_UINT64 Right);

/**
  * @brief Performs checked subtraction of two integer values with a fixed
  *        64-bit width.
  * @param Result The pointer to the variable that receives the result of
  *               (Left - Right). Result must not be null. If the return value
  *               is MO_FALSE, the value pointed to by Result is not modified.
  * @param Signed Indicates whether the fixed 64-bit integer values are signed
  *               (MO_TRUE) or unsigned (MO_FALSE). If MO_FALSE, the valid range
  *               is 0 to (2 ^ 64) - 1. If MO_TRUE, Left and Right are
  *               interpreted as signed integer values represented as 64-bit
  *               unsigned integer values; a negative value -X is represented as
  *               the 64-bit unsigned integer value (2 ^ 64) - X, and the valid
  *               range is -(2 ^ 63) to (2 ^ 63) - 1. The result is returned
  *               using the same representation.
  * @param Left The first operand.
  * @param Right The second operand.
  * @return MO_TRUE if the subtraction succeeds and the result is representable
  *         in the range determined by the fixed 64-bit width and Signed.
  *         MO_FALSE if Result is null or the result is out of range.
  */
MO_EXTERN_C MO_BOOL MOAPI MoMileFixedIntegerCheckedSubtraction64(
    _Mo_Out_ PMO_UINT64 Result,
    _Mo_In_ MO_BOOL Signed,
    _Mo_In_ MO_UINT64 Left,
    _Mo_In_ MO_UINT64 Right);

/**
  * @brief Performs checked multiplication of two integer values with a fixed
  *        64-bit width.
  * @param Result The pointer to the variable that receives the result of
  *               (Left * Right). Result must not be null. If the return value
  *               is MO_FALSE, the value pointed to by Result is not modified.
  * @param Signed Indicates whether the fixed 64-bit integer values are signed
  *               (MO_TRUE) or unsigned (MO_FALSE). If MO_FALSE, the valid range
  *               is 0 to (2 ^ 64) - 1. If MO_TRUE, Left and Right are
  *               interpreted as signed integer values represented as 64-bit
  *               unsigned integer values; a negative value -X is represented as
  *               the 64-bit unsigned integer value (2 ^ 64) - X, and the valid
  *               range is -(2 ^ 63) to (2 ^ 63) - 1. The result is returned
  *               using the same representation.
  * @param Left The first operand.
  * @param Right The second operand.
  * @return MO_TRUE if the multiplication succeeds and the result is
  *         representable in the range determined by the fixed 64-bit width and
  *         Signed. MO_FALSE if Result is null or the result is out of range.
  */
MO_EXTERN_C MO_BOOL MOAPI MoMileFixedIntegerCheckedMultiplication64(
    _Mo_Out_ PMO_UINT64 Result,
    _Mo_In_ MO_BOOL Signed,
    _Mo_In_ MO_UINT64 Left,
    _Mo_In_ MO_UINT64 Right);

#endif // !MILE_MOBILITY_UTILITIES_FIXEDINTEGER
