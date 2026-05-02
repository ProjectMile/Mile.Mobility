/*
 * PROJECT:    Mouri Internal Library Essentials
 * FILE:       Mile.Mobility.Portable.Types.Legacy.h
 * PURPOSE:    Definition for Mobility Portable Legacy Types
 *
 * LICENSE:    The MIT License
 *
 * MAINTAINER: MouriNaruto (Kenji.Mouri@outlook.com)
 */

#ifndef MILE_MOBILITY_PORTABLE_TYPES_LEGACY
#define MILE_MOBILITY_PORTABLE_TYPES_LEGACY

#include "Mile.Mobility.Portable.Types.h"

#ifndef CONST
#define CONST MO_CONST
#endif /* !CONST */

#ifndef VOID
#define VOID MO_VOID
#endif /* !VOID */

/* Workaround for Windows SDK, which defines these types in #ifndef VOID */
/* block. That design is terrible, but needs to have a workaround. */
#ifdef VOID
typedef char CHAR;
typedef short SHORT;
typedef long LONG;
#if !defined(MIDL_PASS)
typedef int INT;
#endif /* !MIDL_PASS */
#endif /* VOID */

#ifndef EXTERN_C
#define EXTERN_C MO_EXTERN_C
#endif /* !EXTERN_C */

#ifdef MILE_MOBILITY_ENABLE_MINIMUM_SAL
#ifndef _In_
#define _In_
#endif /* !_In_ */

#ifndef _In_opt_
#define _In_opt_
#endif /* !_In_opt_ */

#ifndef _Out_
#define _Out_
#endif /* !_Out_ */

#ifndef _Out_opt_
#define _Out_opt_
#endif /* !_Out_opt_ */

#ifndef _Inout_
#define _Inout_
#endif /* !_Inout_ */

#ifndef _Inout_opt_
#define _Inout_opt_
#endif /* !_Inout_opt_ */
#endif /* MILE_MOBILITY_ENABLE_MINIMUM_SAL */

#endif /* !MILE_MOBILITY_PORTABLE_TYPES_LEGACY */
