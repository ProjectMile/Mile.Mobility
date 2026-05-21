/*
 * PROJECT:    Mouri Internal Library Essentials
 * FILE:       Mile.Mobility.Test.cpp
 * PURPOSE:    Implementation for Mile.Mobility Tests
 *
 * LICENSE:    The MIT License
 *
 * MAINTAINER: MouriNaruto (Kenji.Mouri@outlook.com)
 */

#include <Windows.h>

#include <Mile.Mobility.Portable.Types.h>
#include <Mile.Mobility.Utilities.FixedInteger.h>

#include <Mile.Project.Version.h>

#define MILE_MOBILITY_VERSION_UTF8_STRING \
    MILE_PROJECT_VERSION_UTF8_STRING " (Build " \
    MILE_PROJECT_MACRO_TO_UTF8_STRING(MILE_PROJECT_VERSION_BUILD) ")"

#include <cstdio>
#include <cstdlib>

MO_EXTERN_C MO_VOID MoMileFixedIntegerTests();

int main()
{
    std::printf(
        "Mile.Mobility Tests (Development Use)"
        " " MILE_MOBILITY_VERSION_UTF8_STRING "\n"
        "(c) Kenji Mouri. All rights reserved.\n"
        "\n");

    ::MoMileFixedIntegerTests();

    std::printf("\nAll Mile.Mobility Tests executed.\n");

    std::getchar();

    return 0;
}
