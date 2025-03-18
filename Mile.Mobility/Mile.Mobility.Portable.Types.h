/*
 * PROJECT:   Mouri Internal Library Essentials
 * FILE:      Mile.Mobility.Portable.Types.h
 * PURPOSE:   Definition for Mobility Portable Types
 *
 * LICENSE:   The MIT License
 *
 * MAINTAINER: MouriNaruto (Kenji.Mouri@outlook.com)
 */

#ifndef MILE_MOBILITY_PORTABLE_TYPES
#define MILE_MOBILITY_PORTABLE_TYPES

#ifndef CONST
#define CONST const
#endif

#ifndef VOID
#define VOID void
#endif

#ifndef EXTERN_C
#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C extern
#endif
#endif

#ifndef _In_
#define _In_
#endif

#ifndef _In_opt_
#define _In_opt_
#endif

#ifndef _Out_
#define _Out_
#endif

#ifndef _Out_opt_
#define _Out_opt_
#endif

#ifndef MOAPI
#define MOAPI
#endif

#ifdef _MSC_VER
typedef signed char MO_INT8, *PMO_INT8;
typedef signed short MO_INT16, *PMO_INT16;
typedef signed int MO_INT32, *PMO_INT32;
typedef signed __int64 MO_INT64, *PMO_INT64;

typedef unsigned char MO_UINT8, *PMO_UINT8;
typedef unsigned short MO_UINT16, *PMO_UINT16;
typedef unsigned int MO_UINT32, *PMO_UINT32;
typedef unsigned __int64 MO_UINT64, *PMO_UINT64;
#else
typedef signed char MO_INT8, *PMO_INT8;
typedef signed short MO_INT16, *PMO_INT16;
typedef signed int MO_INT32, *PMO_INT32;
typedef signed long long MO_INT64, *PMO_INT64;

typedef unsigned char MO_UINT8, *PMO_UINT8;
typedef unsigned short MO_UINT16, *PMO_UINT16;
typedef unsigned int MO_UINT32, *PMO_UINT32;
typedef unsigned long long MO_UINT64, *PMO_UINT64;
#endif

#define MO_INT8_MIN (((MO_INT8)-127) - 1)
#define MO_INT16_MIN (((MO_INT16)-32767) - 1)
#define MO_INT32_MIN (((MO_INT32)-2147483647) - 1)
#define MO_INT64_MIN (((MO_INT64)-9223372036854775807LL) - 1)

#define MO_INT8_MAX ((MO_INT8)0x7F)
#define MO_INT16_MAX ((MO_INT16)0x7FFF)
#define MO_INT32_MAX ((MO_INT32)0x7FFFFFFF)
#define MO_INT64_MAX ((MO_INT64)0x7FFFFFFFFFFFFFFFULL)

#define MO_UINT8_MAX ((MO_UINT8)0xFF)
#define MO_UINT16_MAX ((MO_UINT16)0xFFFF)
#define MO_UINT32_MAX ((MO_UINT32)0xFFFFFFFF)
#define MO_UINT64_MAX ((MO_UINT64)0xFFFFFFFFFFFFFFFFULL)

#if defined(_WIN64) || defined(_LP64) || defined(__LP64__)
typedef MO_INT64 MO_INTN;
typedef MO_UINT64 MO_UINTN;

#define MO_INTN_MIN MO_INT64_MIN
#define MO_INTN_MAX MO_INT64_MAX
#define MO_UINTN_MAX MO_UINT64_MAX
#elif
typedef MO_INT32 MO_INTN;
typedef MO_UINT32 MO_UINTN;

#define MO_INTN_MIN MO_INT32_MIN
#define MO_INTN_MAX MO_INT32_MAX
#define MO_UINTN_MAX MO_UINT32_MAX
#endif

typedef MO_UINT8 MO_BOOL, *PMO_BOOL;
#define MO_FALSE 0
#define MO_TRUE 1

typedef char MO_CHAR, *PMO_CHAR;
#define MO_CHAR_MIN 0x00
#define MO_CHAR_MAX 0xFF

#ifdef _WCHAR_T_DEFINED
typedef wchar_t MO_WIDE_CHAR, *PMO_WIDE_CHAR;
#else
typedef MO_UINT16 MO_WIDE_CHAR, *PMO_WIDE_CHAR;
#endif
#define MO_WIDE_CHAR_MIN 0x0000
#define MO_WIDE_CHAR_MAX 0xFFFF

typedef PMO_CHAR MO_STRING, *PMO_STRING;
typedef PMO_WIDE_CHAR MO_WIDE_STRING, *PMO_WIDE_STRING;
typedef CONST MO_STRING MO_CONSTANT_STRING, *PMO_CONSTANT_STRING;
typedef CONST MO_WIDE_STRING MO_CONSTANT_WIDE_STRING, *PMO_CONSTANT_WIDE_STRING;

#endif // !MILE_MOBILITY_PORTABLE_TYPES
