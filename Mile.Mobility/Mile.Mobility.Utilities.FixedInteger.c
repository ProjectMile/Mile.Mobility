/*
 * PROJECT:    Mouri Internal Library Essentials
 * FILE:       Mile.Mobility.Utilities.FixedInteger.c
 * PURPOSE:    Implementation for Mobility Fixed Width Integer Utilities
 *
 * LICENSE:    The MIT License
 *
 * MAINTAINER: MouriNaruto (Kenji.Mouri@outlook.com)
 */

#include "Mile.Mobility.Utilities.FixedInteger.h"

#define MO_INTERNAL_SIGN_BIT_MASK(TYPE) \
    ((TYPE)(((TYPE)(1)) << (sizeof(TYPE) * 8 - 1)))

#define MO_INTERNAL_SIGN_BIT_MASK_8 MO_INTERNAL_SIGN_BIT_MASK(MO_UINT8)
#define MO_INTERNAL_SIGN_BIT_MASK_16 MO_INTERNAL_SIGN_BIT_MASK(MO_UINT16)
#define MO_INTERNAL_SIGN_BIT_MASK_32 MO_INTERNAL_SIGN_BIT_MASK(MO_UINT32)
#define MO_INTERNAL_SIGN_BIT_MASK_64 MO_INTERNAL_SIGN_BIT_MASK(MO_UINT64)

MO_EXTERN_C MO_BOOL MOAPI MoMileFixedIntegerCheckedAddition8(
    _Mo_Out_ PMO_UINT8 Result,
    _Mo_In_ MO_BOOL Signed,
    _Mo_In_ MO_UINT8 Left,
    _Mo_In_ MO_UINT8 Right)
{
#define VALUE_TYPE MO_UINT8
#define VALUE_SIGN_BIT_MASK MO_INTERNAL_SIGN_BIT_MASK_8

    if (!Result)
    {
        // The result pointer must not be null.
        return MO_FALSE;
    }

    {
        VALUE_TYPE Candidate = Left + Right;

        if (Signed)
        {
            VALUE_TYPE SignBitMask = VALUE_SIGN_BIT_MASK;
            if (0 == ((Left ^ Right) & SignBitMask) &&
                0 != ((Left ^ Candidate) & SignBitMask))
            {
                // The signed addition overflowed.
                return MO_FALSE;
            }
        }
        else
        {
            if (Candidate < Left)
            {
                // The unsigned addition overflowed.
                return MO_FALSE;
            }
        }

        // Set the result only when the addition succeeds and the result is
        // representable in the range determined by the fixed width and Signed.
        *Result = Candidate;
    }

    return MO_TRUE;

#undef VALUE_TYPE
#undef VALUE_SIGN_BIT_MASK
}

MO_EXTERN_C MO_BOOL MOAPI MoMileFixedIntegerCheckedSubtraction8(
    _Mo_Out_ PMO_UINT8 Result,
    _Mo_In_ MO_BOOL Signed,
    _Mo_In_ MO_UINT8 Left,
    _Mo_In_ MO_UINT8 Right)
{
#define VALUE_TYPE MO_UINT8
#define VALUE_SIGN_BIT_MASK MO_INTERNAL_SIGN_BIT_MASK_8

    if (!Result)
    {
        // The result pointer must not be null.
        return MO_FALSE;
    }

    if (!Signed && Left < Right)
    {
        // The unsigned subtraction underflowed.
        return MO_FALSE;
    }

    {
        VALUE_TYPE Candidate = Left - Right;

        if (Signed)
        {
            VALUE_TYPE SignBitMask = VALUE_SIGN_BIT_MASK;
            if (0 != ((Left ^ Right) & SignBitMask) &&
                0 != ((Left ^ Candidate) & SignBitMask))
            {
                // The signed subtraction overflowed.
                return MO_FALSE;
            }
        }

        // Set the result only when the subtraction succeeds and the result is
        // representable in the range determined by the fixed width and Signed.
        *Result = Candidate;
    }

    return MO_TRUE;

#undef VALUE_TYPE
#undef VALUE_SIGN_BIT_MASK
}

MO_EXTERN_C MO_BOOL MOAPI MoMileFixedIntegerCheckedMultiplication8(
    _Mo_Out_ PMO_UINT8 Result,
    _Mo_In_ MO_BOOL Signed,
    _Mo_In_ MO_UINT8 Left,
    _Mo_In_ MO_UINT8 Right)
{
#define VALUE_TYPE MO_UINT8
#define VALUE_SIGN_BIT_MASK MO_INTERNAL_SIGN_BIT_MASK_8

    if (!Result)
    {
        // The result pointer must not be null.
        return MO_FALSE;
    }

    {
        VALUE_TYPE LeftMagnitude = 0;
        VALUE_TYPE RightMagnitude = 0;
        VALUE_TYPE Limit = 0;
        MO_BOOL ResultNegative = MO_FALSE;

        if (Signed)
        {
            VALUE_TYPE SignBitMask = VALUE_SIGN_BIT_MASK;
            MO_BOOL LeftNegative = (Left & SignBitMask) ? MO_TRUE : MO_FALSE;
            MO_BOOL RightNegative = (Right & SignBitMask) ? MO_TRUE : MO_FALSE;
            VALUE_TYPE HalfRange = VALUE_SIGN_BIT_MASK;

            LeftMagnitude = LeftNegative
                ? ((VALUE_TYPE)(0) - Left)
                : Left;

            RightMagnitude = RightNegative
                ? ((VALUE_TYPE)(0) - Right)
                : Right;

            ResultNegative = (LeftNegative != RightNegative)
                ? MO_TRUE
                : MO_FALSE;

            Limit = ResultNegative ? HalfRange : HalfRange - 1;
        }
        else
        {
            LeftMagnitude = Left;
            RightMagnitude = Right;
            Limit = ((VALUE_TYPE)(((VALUE_TYPE)(0)) - ((VALUE_TYPE)(1))));
        }

        {
            VALUE_TYPE ResultMagnitude = 0;

            if (0 == LeftMagnitude || 0 == RightMagnitude)
            {
                ResultMagnitude = 0;
            }
            else
            {
                if (LeftMagnitude > Limit || RightMagnitude > Limit)
                {
                    // The multiplication result is out of range.
                    return MO_FALSE;
                }

                if (1 == LeftMagnitude)
                {
                    ResultMagnitude = RightMagnitude;
                }
                else if (1 == RightMagnitude)
                {
                    ResultMagnitude = LeftMagnitude;
                }
                else
                {
                    if (LeftMagnitude > Limit / RightMagnitude)
                    {
                        // The multiplication result is out of range.
                        return MO_FALSE;
                    }

                    ResultMagnitude = LeftMagnitude * RightMagnitude;
                }
            }

            // Set the result only when the multiplication succeeds and the
            // result is representable in the range determined by the fixed
            // width and Signed.
            *Result = (Signed && ResultNegative)
                ? (((VALUE_TYPE)(0)) - ResultMagnitude)
                : ResultMagnitude;
        }
    }

    return MO_TRUE;

#undef VALUE_TYPE
#undef VALUE_SIGN_BIT_MASK
}
