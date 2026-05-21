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

#include <Mile.Project.Version.h>

#define MILE_MOBILITY_VERSION_UTF8_STRING \
    MILE_PROJECT_VERSION_UTF8_STRING " (Build " \
    MILE_PROJECT_MACRO_TO_UTF8_STRING(MILE_PROJECT_VERSION_BUILD) ")"

#include <cstdio>
#include <cstdlib>

int main()
{
    std::printf(
        "Mile.Mobility Tests (Development Use)"
        " " MILE_MOBILITY_VERSION_UTF8_STRING "\r\n"
        "(c) Kenji Mouri. All rights reserved.\r\n"
        "\r\n");

    std::printf("Under construction.\r\n");

    std::getchar();

    return 0;
}
