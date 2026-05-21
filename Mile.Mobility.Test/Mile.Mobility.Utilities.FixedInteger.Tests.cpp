/*
 * PROJECT:    Mouri Internal Library Essentials
 * FILE:       Mile.Mobility.Utilities.FixedInteger.Tests.cpp
 * PURPOSE:    Implementation for Mile.Mobility.Utilities.FixedInteger Tests
 *
 * LICENSE:    The MIT License
 *
 * MAINTAINER: MouriNaruto (Kenji.Mouri@outlook.com)
 */

#include <Windows.h>

#include <Mile.Mobility.Utilities.FixedInteger.h>

#include <cstdio>
#include <cstdlib>
#include <source_location>
#include <string_view>

namespace
{
    [[noreturn]] inline void Fail(
        std::string_view Message = {},
        std::source_location const& Location = std::source_location::current())
    {
        std::fprintf(stderr, "Test failed: ");
        std::fwrite(Message.data(), 1, Message.size(), stderr);
        std::fprintf(
            stderr,
            " (%s:%u, function %s)\n",
            Location.file_name(),
            Location.line(),
            Location.function_name());
        std::fflush(stderr);
        std::abort();
    }

    inline void Check(
        bool Condition,
        std::string_view Message = {},
        std::source_location const& Location = std::source_location::current())
    {
        if (!Condition)
        {
            Fail(Message, Location);
        }
    }
}

namespace
{
    void MoMileFixedIntegerCheckedAddition8Test()
    {
        auto Test = [](
            MO_BOOL Signed,
            MO_UINT8 Left,
            MO_UINT8 Right,
            MO_BOOL Expected,
            MO_UINT8 ExpectedResult,
            std::string_view Message = {},
            std::source_location const& Location = std::source_location::current())
        {
            MO_UINT8 const Sentinel = static_cast<MO_UINT8>(0xA5);
            MO_UINT8 Result = Sentinel;

            MO_BOOL Actual = ::MoMileFixedIntegerCheckedAddition8(
                &Result,
                Signed,
                Left,
                Right);

            ::Check(
                Expected == Actual,
                Message,
                Location);

            if (Expected)
            {
                ::Check(
                    ExpectedResult == Result,
                    Message,
                    Location);
            }
            else
            {
                ::Check(
                    Sentinel == Result,
                    Message,
                    Location);
            }
        };

        auto Negative = [](
            MO_UINT8 Magnitude) -> MO_UINT8
        {
            return static_cast<MO_UINT8>(0) - Magnitude;
        };

        MO_UINT8 const U8Maximum = static_cast<MO_UINT8>(
            static_cast<MO_UINT8>(0) - static_cast<MO_UINT8>(1));

        MO_UINT8 const S8Maximum =
            static_cast<MO_UINT8>((static_cast<MO_UINT8>(1) << 7) - 1);

        MO_UINT8 const S8Minimum =
            static_cast<MO_UINT8>(static_cast<MO_UINT8>(1) << 7);

        ::Check(
            MO_FALSE == ::MoMileFixedIntegerCheckedAddition8(
                nullptr,
                MO_FALSE,
                0,
                0),
            "null Result is invalid");

        Test(
            MO_FALSE,
            0,
            0,
            MO_TRUE,
            0,
            "unsigned 8-bit accepts 0 + 0");

        Test(
            MO_FALSE,
            1,
            2,
            MO_TRUE,
            3,
            "unsigned 8-bit accepts 1 + 2");

        Test(
            MO_FALSE,
            254,
            1,
            MO_TRUE,
            255,
            "unsigned 8-bit accepts 254 + 1");

        Test(
            MO_FALSE,
            U8Maximum,
            0,
            MO_TRUE,
            U8Maximum,
            "unsigned 8-bit accepts maximum + 0");

        Test(
            MO_FALSE,
            U8Maximum,
            1,
            MO_FALSE,
            0,
            "unsigned 8-bit rejects maximum + 1");

        Test(
            MO_FALSE,
            128,
            128,
            MO_FALSE,
            0,
            "unsigned 8-bit rejects 128 + 128");

        Test(
            MO_FALSE,
            200,
            55,
            MO_TRUE,
            255,
            "unsigned 8-bit accepts 200 + 55");

        Test(
            MO_FALSE,
            200,
            56,
            MO_FALSE,
            0,
            "unsigned 8-bit rejects 200 + 56");

        Test(
            MO_TRUE,
            0,
            0,
            MO_TRUE,
            0,
            "signed 8-bit accepts 0 + 0");

        Test(
            MO_TRUE,
            1,
            1,
            MO_TRUE,
            2,
            "signed 8-bit accepts 1 + 1");

        Test(
            MO_TRUE,
            S8Maximum,
            0,
            MO_TRUE,
            S8Maximum,
            "signed 8-bit accepts maximum + 0");

        Test(
            MO_TRUE,
            126,
            1,
            MO_TRUE,
            127,
            "signed 8-bit accepts 126 + 1");

        Test(
            MO_TRUE,
            S8Maximum,
            1,
            MO_FALSE,
            0,
            "signed 8-bit rejects maximum + 1");

        Test(
            MO_TRUE,
            64,
            63,
            MO_TRUE,
            127,
            "signed 8-bit accepts 64 + 63");

        Test(
            MO_TRUE,
            64,
            64,
            MO_FALSE,
            0,
            "signed 8-bit rejects 64 + 64");

        Test(
            MO_TRUE,
            Negative(1),
            1,
            MO_TRUE,
            0,
            "signed 8-bit accepts -1 + 1");

        Test(
            MO_TRUE,
            Negative(1),
            Negative(1),
            MO_TRUE,
            Negative(2),
            "signed 8-bit accepts -1 + -1");

        Test(
            MO_TRUE,
            S8Minimum,
            0,
            MO_TRUE,
            S8Minimum,
            "signed 8-bit accepts minimum + 0");

        Test(
            MO_TRUE,
            S8Minimum,
            1,
            MO_TRUE,
            Negative(127),
            "signed 8-bit accepts minimum + 1");

        Test(
            MO_TRUE,
            S8Minimum,
            Negative(1),
            MO_FALSE,
            0,
            "signed 8-bit rejects minimum + -1");

        Test(
            MO_TRUE,
            Negative(127),
            Negative(1),
            MO_TRUE,
            S8Minimum,
            "signed 8-bit accepts -127 + -1");

        Test(
            MO_TRUE,
            S8Minimum,
            S8Minimum,
            MO_FALSE,
            0,
            "signed 8-bit rejects minimum + minimum");

        Test(
            MO_TRUE,
            S8Maximum,
            Negative(1),
            MO_TRUE,
            126,
            "signed 8-bit accepts maximum + -1");

        Test(
            MO_TRUE,
            S8Minimum,
            S8Maximum,
            MO_TRUE,
            Negative(1),
            "signed 8-bit accepts minimum + maximum");

        std::printf("MoMileFixedIntegerCheckedAddition8Test passed.\n");
    }

    void MoMileFixedIntegerCheckedSubtraction8Test()
    {
        auto Test = [](
            MO_BOOL Signed,
            MO_UINT8 Left,
            MO_UINT8 Right,
            MO_BOOL Expected,
            MO_UINT8 ExpectedResult,
            std::string_view Message = {},
            std::source_location const& Location = std::source_location::current())
        {
            MO_UINT8 const Sentinel = static_cast<MO_UINT8>(0xA5);
            MO_UINT8 Result = Sentinel;

            MO_BOOL Actual = ::MoMileFixedIntegerCheckedSubtraction8(
                &Result,
                Signed,
                Left,
                Right);

            ::Check(
                Expected == Actual,
                Message,
                Location);

            if (Expected)
            {
                ::Check(
                    ExpectedResult == Result,
                    Message,
                    Location);
            }
            else
            {
                ::Check(
                    Sentinel == Result,
                    Message,
                    Location);
            }
        };

        auto Negative = [](
            MO_UINT8 Magnitude) -> MO_UINT8
        {
            return static_cast<MO_UINT8>(0) - Magnitude;
        };

        MO_UINT8 const U8Maximum = static_cast<MO_UINT8>(
            static_cast<MO_UINT8>(0) - static_cast<MO_UINT8>(1));

        MO_UINT8 const S8Maximum =
            static_cast<MO_UINT8>((static_cast<MO_UINT8>(1) << 7) - 1);

        MO_UINT8 const S8Minimum =
            static_cast<MO_UINT8>(static_cast<MO_UINT8>(1) << 7);

        ::Check(
            MO_FALSE == ::MoMileFixedIntegerCheckedSubtraction8(
                nullptr,
                MO_FALSE,
                0,
                0),
            "null Result is invalid");

        Test(
            MO_FALSE,
            0,
            0,
            MO_TRUE,
            0,
            "unsigned 8-bit accepts 0 - 0");

        Test(
            MO_FALSE,
            3,
            2,
            MO_TRUE,
            1,
            "unsigned 8-bit accepts 3 - 2");

        Test(
            MO_FALSE,
            U8Maximum,
            0,
            MO_TRUE,
            U8Maximum,
            "unsigned 8-bit accepts maximum - 0");

        Test(
            MO_FALSE,
            U8Maximum,
            U8Maximum,
            MO_TRUE,
            0,
            "unsigned 8-bit accepts maximum - maximum");

        Test(
            MO_FALSE,
            0,
            1,
            MO_FALSE,
            0,
            "unsigned 8-bit rejects 0 - 1");

        Test(
            MO_FALSE,
            100,
            101,
            MO_FALSE,
            0,
            "unsigned 8-bit rejects 100 - 101");

        Test(
            MO_TRUE,
            0,
            0,
            MO_TRUE,
            0,
            "signed 8-bit accepts 0 - 0");

        Test(
            MO_TRUE,
            1,
            0,
            MO_TRUE,
            1,
            "signed 8-bit accepts 1 - 0");

        Test(
            MO_TRUE,
            1,
            1,
            MO_TRUE,
            0,
            "signed 8-bit accepts 1 - 1");

        Test(
            MO_TRUE,
            0,
            1,
            MO_TRUE,
            Negative(1),
            "signed 8-bit accepts 0 - 1");

        Test(
            MO_TRUE,
            S8Maximum,
            0,
            MO_TRUE,
            S8Maximum,
            "signed 8-bit accepts maximum - 0");

        Test(
            MO_TRUE,
            S8Maximum,
            1,
            MO_TRUE,
            126,
            "signed 8-bit accepts maximum - 1");

        Test(
            MO_TRUE,
            S8Maximum,
            Negative(1),
            MO_FALSE,
            0,
            "signed 8-bit rejects maximum - -1");

        Test(
            MO_TRUE,
            0,
            Negative(1),
            MO_TRUE,
            1,
            "signed 8-bit accepts 0 - -1");

        Test(
            MO_TRUE,
            100,
            Negative(27),
            MO_TRUE,
            127,
            "signed 8-bit accepts 100 - -27");

        Test(
            MO_TRUE,
            100,
            Negative(28),
            MO_FALSE,
            0,
            "signed 8-bit rejects 100 - -28");

        Test(
            MO_TRUE,
            S8Minimum,
            0,
            MO_TRUE,
            S8Minimum,
            "signed 8-bit accepts minimum - 0");

        Test(
            MO_TRUE,
            S8Minimum,
            Negative(1),
            MO_TRUE,
            Negative(127),
            "signed 8-bit accepts minimum - -1");

        Test(
            MO_TRUE,
            S8Minimum,
            1,
            MO_FALSE,
            0,
            "signed 8-bit rejects minimum - 1");

        Test(
            MO_TRUE,
            Negative(127),
            1,
            MO_TRUE,
            S8Minimum,
            "signed 8-bit accepts -127 - 1");

        Test(
            MO_TRUE,
            Negative(127),
            2,
            MO_FALSE,
            0,
            "signed 8-bit rejects -127 - 2");

        Test(
            MO_TRUE,
            Negative(1),
            Negative(1),
            MO_TRUE,
            0,
            "signed 8-bit accepts -1 - -1");

        Test(
            MO_TRUE,
            S8Maximum,
            S8Minimum,
            MO_FALSE,
            0,
            "signed 8-bit rejects maximum - minimum");

        Test(
            MO_TRUE,
            S8Minimum,
            S8Maximum,
            MO_FALSE,
            0,
            "signed 8-bit rejects minimum - maximum");

        std::printf("MoMileFixedIntegerCheckedSubtraction8Test passed.\n");
    }

    void MoMileFixedIntegerCheckedMultiplication8Test()
    {
        auto Test = [](
            MO_BOOL Signed,
            MO_UINT8 Left,
            MO_UINT8 Right,
            MO_BOOL Expected,
            MO_UINT8 ExpectedResult,
            std::string_view Message = {},
            std::source_location const& Location = std::source_location::current())
        {
            MO_UINT8 const Sentinel = static_cast<MO_UINT8>(0xA5);
            MO_UINT8 Result = Sentinel;

            MO_BOOL Actual = ::MoMileFixedIntegerCheckedMultiplication8(
                &Result,
                Signed,
                Left,
                Right);

            ::Check(
                Expected == Actual,
                Message,
                Location);

            if (Expected)
            {
                ::Check(
                    ExpectedResult == Result,
                    Message,
                    Location);
            }
            else
            {
                ::Check(
                    Sentinel == Result,
                    Message,
                    Location);
            }
        };

        auto Negative = [](
            MO_UINT8 Magnitude) -> MO_UINT8
        {
            return static_cast<MO_UINT8>(0) - Magnitude;
        };

        MO_UINT8 const U8Maximum = static_cast<MO_UINT8>(
            static_cast<MO_UINT8>(0) - static_cast<MO_UINT8>(1));

        MO_UINT8 const S8Maximum =
            static_cast<MO_UINT8>((static_cast<MO_UINT8>(1) << 7) - 1);

        MO_UINT8 const S8Minimum =
            static_cast<MO_UINT8>(static_cast<MO_UINT8>(1) << 7);

        ::Check(
            MO_FALSE == ::MoMileFixedIntegerCheckedMultiplication8(
                nullptr,
                MO_FALSE,
                0,
                0),
            "null Result is invalid");

        Test(
            MO_FALSE,
            0,
            0,
            MO_TRUE,
            0,
            "unsigned 8-bit accepts 0 * 0");

        Test(
            MO_FALSE,
            0,
            U8Maximum,
            MO_TRUE,
            0,
            "unsigned 8-bit accepts 0 * maximum");

        Test(
            MO_FALSE,
            1,
            U8Maximum,
            MO_TRUE,
            U8Maximum,
            "unsigned 8-bit accepts 1 * maximum");

        Test(
            MO_FALSE,
            15,
            17,
            MO_TRUE,
            255,
            "unsigned 8-bit accepts 15 * 17");

        Test(
            MO_FALSE,
            16,
            16,
            MO_FALSE,
            0,
            "unsigned 8-bit rejects 16 * 16");

        Test(
            MO_FALSE,
            U8Maximum,
            1,
            MO_TRUE,
            U8Maximum,
            "unsigned 8-bit accepts maximum * 1");

        Test(
            MO_FALSE,
            U8Maximum,
            2,
            MO_FALSE,
            0,
            "unsigned 8-bit rejects maximum * 2");

        Test(
            MO_FALSE,
            128,
            2,
            MO_FALSE,
            0,
            "unsigned 8-bit rejects 128 * 2");

        Test(
            MO_TRUE,
            0,
            0,
            MO_TRUE,
            0,
            "signed 8-bit accepts 0 * 0");

        Test(
            MO_TRUE,
            0,
            S8Minimum,
            MO_TRUE,
            0,
            "signed 8-bit accepts 0 * minimum");

        Test(
            MO_TRUE,
            1,
            S8Maximum,
            MO_TRUE,
            S8Maximum,
            "signed 8-bit accepts 1 * maximum");

        Test(
            MO_TRUE,
            S8Maximum,
            1,
            MO_TRUE,
            S8Maximum,
            "signed 8-bit accepts maximum * 1");

        Test(
            MO_TRUE,
            S8Maximum,
            2,
            MO_FALSE,
            0,
            "signed 8-bit rejects maximum * 2");

        Test(
            MO_TRUE,
            11,
            11,
            MO_TRUE,
            121,
            "signed 8-bit accepts 11 * 11");

        Test(
            MO_TRUE,
            12,
            11,
            MO_FALSE,
            0,
            "signed 8-bit rejects 12 * 11");

        Test(
            MO_TRUE,
            Negative(1),
            1,
            MO_TRUE,
            Negative(1),
            "signed 8-bit accepts -1 * 1");

        Test(
            MO_TRUE,
            Negative(1),
            Negative(1),
            MO_TRUE,
            1,
            "signed 8-bit accepts -1 * -1");

        Test(
            MO_TRUE,
            S8Minimum,
            1,
            MO_TRUE,
            S8Minimum,
            "signed 8-bit accepts minimum * 1");

        Test(
            MO_TRUE,
            S8Minimum,
            0,
            MO_TRUE,
            0,
            "signed 8-bit accepts minimum * 0");

        Test(
            MO_TRUE,
            S8Minimum,
            Negative(1),
            MO_FALSE,
            0,
            "signed 8-bit rejects minimum * -1");

        Test(
            MO_TRUE,
            Negative(64),
            2,
            MO_TRUE,
            S8Minimum,
            "signed 8-bit accepts -64 * 2");

        Test(
            MO_TRUE,
            Negative(65),
            2,
            MO_FALSE,
            0,
            "signed 8-bit rejects -65 * 2");

        Test(
            MO_TRUE,
            Negative(16),
            Negative(8),
            MO_FALSE,
            0,
            "signed 8-bit rejects -16 * -8");

        Test(
            MO_TRUE,
            Negative(15),
            Negative(8),
            MO_TRUE,
            120,
            "signed 8-bit accepts -15 * -8");

        Test(
            MO_TRUE,
            Negative(127),
            1,
            MO_TRUE,
            Negative(127),
            "signed 8-bit accepts -127 * 1");

        Test(
            MO_TRUE,
            Negative(127),
            2,
            MO_FALSE,
            0,
            "signed 8-bit rejects -127 * 2");

        Test(
            MO_TRUE,
            S8Minimum,
            S8Minimum,
            MO_FALSE,
            0,
            "signed 8-bit rejects minimum * minimum");

        std::printf("MoMileFixedIntegerCheckedSubtraction8Test passed.\n");
    }

    void MoMileFixedIntegerCheckedAddition16Test()
    {
        auto Test = [](
            MO_BOOL Signed,
            MO_UINT16 Left,
            MO_UINT16 Right,
            MO_BOOL Expected,
            MO_UINT16 ExpectedResult,
            std::string_view Message = {},
            std::source_location const& Location = std::source_location::current())
        {
            MO_UINT16 const Sentinel = static_cast<MO_UINT16>(0xA5A5);
            MO_UINT16 Result = Sentinel;

            MO_BOOL Actual = ::MoMileFixedIntegerCheckedAddition16(
                &Result,
                Signed,
                Left,
                Right);

            ::Check(
                Expected == Actual,
                Message,
                Location);

            if (Expected)
            {
                ::Check(
                    ExpectedResult == Result,
                    Message,
                    Location);
            }
            else
            {
                ::Check(
                    Sentinel == Result,
                    Message,
                    Location);
            }
        };

        auto Negative = [](
            MO_UINT16 Magnitude) -> MO_UINT16
        {
            return static_cast<MO_UINT16>(0) - Magnitude;
        };

        MO_UINT16 const U16Maximum = static_cast<MO_UINT16>(
            static_cast<MO_UINT16>(0) - static_cast<MO_UINT16>(1));

        MO_UINT16 const S16Maximum =
            static_cast<MO_UINT16>((static_cast<MO_UINT16>(1) << 15) - 1);

        MO_UINT16 const S16Minimum =
            static_cast<MO_UINT16>(static_cast<MO_UINT16>(1) << 15);

        ::Check(
            MO_FALSE == ::MoMileFixedIntegerCheckedAddition16(
                nullptr,
                MO_FALSE,
                0,
                0),
            "null Result is invalid");

        Test(
            MO_FALSE,
            0,
            0,
            MO_TRUE,
            0,
            "unsigned 16-bit accepts 0 + 0");

        Test(
            MO_FALSE,
            1,
            2,
            MO_TRUE,
            3,
            "unsigned 16-bit accepts 1 + 2");

        Test(
            MO_FALSE,
            65534,
            1,
            MO_TRUE,
            65535,
            "unsigned 16-bit accepts 65534 + 1");

        Test(
            MO_FALSE,
            U16Maximum,
            0,
            MO_TRUE,
            U16Maximum,
            "unsigned 16-bit accepts maximum + 0");

        Test(
            MO_FALSE,
            U16Maximum,
            1,
            MO_FALSE,
            0,
            "unsigned 16-bit rejects maximum + 1");

        Test(
            MO_FALSE,
            32768,
            32768,
            MO_FALSE,
            0,
            "unsigned 16-bit rejects 32768 + 32768");

        Test(
            MO_FALSE,
            60000,
            5535,
            MO_TRUE,
            65535,
            "unsigned 16-bit accepts 60000 + 5535");

        Test(
            MO_FALSE,
            60000,
            5536,
            MO_FALSE,
            0,
            "unsigned 16-bit rejects 60000 + 5536");

        Test(
            MO_TRUE,
            0,
            0,
            MO_TRUE,
            0,
            "signed 16-bit accepts 0 + 0");

        Test(
            MO_TRUE,
            1,
            1,
            MO_TRUE,
            2,
            "signed 16-bit accepts 1 + 1");

        Test(
            MO_TRUE,
            S16Maximum,
            0,
            MO_TRUE,
            S16Maximum,
            "signed 16-bit accepts maximum + 0");

        Test(
            MO_TRUE,
            32766,
            1,
            MO_TRUE,
            32767,
            "signed 16-bit accepts 32766 + 1");

        Test(
            MO_TRUE,
            S16Maximum,
            1,
            MO_FALSE,
            0,
            "signed 16-bit rejects maximum + 1");

        Test(
            MO_TRUE,
            16384,
            16383,
            MO_TRUE,
            32767,
            "signed 16-bit accepts 16384 + 16383");

        Test(
            MO_TRUE,
            16384,
            16384,
            MO_FALSE,
            0,
            "signed 16-bit rejects 16384 + 16384");

        Test(
            MO_TRUE,
            Negative(1),
            1,
            MO_TRUE,
            0,
            "signed 16-bit accepts -1 + 1");

        Test(
            MO_TRUE,
            Negative(1),
            Negative(1),
            MO_TRUE,
            Negative(2),
            "signed 16-bit accepts -1 + -1");

        Test(
            MO_TRUE,
            S16Minimum,
            0,
            MO_TRUE,
            S16Minimum,
            "signed 16-bit accepts minimum + 0");

        Test(
            MO_TRUE,
            S16Minimum,
            1,
            MO_TRUE,
            Negative(32767),
            "signed 16-bit accepts minimum + 1");

        Test(
            MO_TRUE,
            S16Minimum,
            Negative(1),
            MO_FALSE,
            0,
            "signed 16-bit rejects minimum + -1");

        Test(
            MO_TRUE,
            Negative(32767),
            Negative(1),
            MO_TRUE,
            S16Minimum,
            "signed 16-bit accepts -32767 + -1");

        Test(
            MO_TRUE,
            S16Minimum,
            S16Minimum,
            MO_FALSE,
            0,
            "signed 16-bit rejects minimum + minimum");

        Test(
            MO_TRUE,
            S16Maximum,
            Negative(1),
            MO_TRUE,
            32766,
            "signed 16-bit accepts maximum + -1");

        Test(
            MO_TRUE,
            S16Minimum,
            S16Maximum,
            MO_TRUE,
            Negative(1),
            "signed 16-bit accepts minimum + maximum");

        std::printf("MoMileFixedIntegerCheckedAddition16Test passed.\n");
    }

    void MoMileFixedIntegerCheckedSubtraction16Test()
    {
        auto Test = [](
            MO_BOOL Signed,
            MO_UINT16 Left,
            MO_UINT16 Right,
            MO_BOOL Expected,
            MO_UINT16 ExpectedResult,
            std::string_view Message = {},
            std::source_location const& Location = std::source_location::current())
        {
            MO_UINT16 const Sentinel = static_cast<MO_UINT16>(0xA5A5);
            MO_UINT16 Result = Sentinel;

            MO_BOOL Actual = ::MoMileFixedIntegerCheckedSubtraction16(
                &Result,
                Signed,
                Left,
                Right);

            ::Check(
                Expected == Actual,
                Message,
                Location);

            if (Expected)
            {
                ::Check(
                    ExpectedResult == Result,
                    Message,
                    Location);
            }
            else
            {
                ::Check(
                    Sentinel == Result,
                    Message,
                    Location);
            }
        };

        auto Negative = [](
            MO_UINT16 Magnitude) -> MO_UINT16
        {
            return static_cast<MO_UINT16>(0) - Magnitude;
        };

        MO_UINT16 const U16Maximum = static_cast<MO_UINT16>(
            static_cast<MO_UINT16>(0) - static_cast<MO_UINT16>(1));

        MO_UINT16 const S16Maximum =
            static_cast<MO_UINT16>((static_cast<MO_UINT16>(1) << 15) - 1);

        MO_UINT16 const S16Minimum =
            static_cast<MO_UINT16>(static_cast<MO_UINT16>(1) << 15);

        ::Check(
            MO_FALSE == ::MoMileFixedIntegerCheckedSubtraction16(
                nullptr,
                MO_FALSE,
                0,
                0),
            "null Result is invalid");

        Test(
            MO_FALSE,
            0,
            0,
            MO_TRUE,
            0,
            "unsigned 16-bit accepts 0 - 0");

        Test(
            MO_FALSE,
            3,
            2,
            MO_TRUE,
            1,
            "unsigned 16-bit accepts 3 - 2");

        Test(
            MO_FALSE,
            U16Maximum,
            0,
            MO_TRUE,
            U16Maximum,
            "unsigned 16-bit accepts maximum - 0");

        Test(
            MO_FALSE,
            U16Maximum,
            U16Maximum,
            MO_TRUE,
            0,
            "unsigned 16-bit accepts maximum - maximum");

        Test(
            MO_FALSE,
            0,
            1,
            MO_FALSE,
            0,
            "unsigned 16-bit rejects 0 - 1");

        Test(
            MO_FALSE,
            10000,
            10001,
            MO_FALSE,
            0,
            "unsigned 16-bit rejects 10000 - 10001");

        Test(
            MO_TRUE,
            0,
            0,
            MO_TRUE,
            0,
            "signed 16-bit accepts 0 - 0");

        Test(
            MO_TRUE,
            1,
            0,
            MO_TRUE,
            1,
            "signed 16-bit accepts 1 - 0");

        Test(
            MO_TRUE,
            1,
            1,
            MO_TRUE,
            0,
            "signed 16-bit accepts 1 - 1");

        Test(
            MO_TRUE,
            0,
            1,
            MO_TRUE,
            Negative(1),
            "signed 16-bit accepts 0 - 1");

        Test(
            MO_TRUE,
            S16Maximum,
            0,
            MO_TRUE,
            S16Maximum,
            "signed 16-bit accepts maximum - 0");

        Test(
            MO_TRUE,
            S16Maximum,
            1,
            MO_TRUE,
            32766,
            "signed 16-bit accepts maximum - 1");

        Test(
            MO_TRUE,
            S16Maximum,
            Negative(1),
            MO_FALSE,
            0,
            "signed 16-bit rejects maximum - -1");

        Test(
            MO_TRUE,
            0,
            Negative(1),
            MO_TRUE,
            1,
            "signed 16-bit accepts 0 - -1");

        Test(
            MO_TRUE,
            30000,
            Negative(2767),
            MO_TRUE,
            32767,
            "signed 16-bit accepts 30000 - -2767");

        Test(
            MO_TRUE,
            30000,
            Negative(2768),
            MO_FALSE,
            0,
            "signed 16-bit rejects 30000 - -2768");

        Test(
            MO_TRUE,
            S16Minimum,
            0,
            MO_TRUE,
            S16Minimum,
            "signed 16-bit accepts minimum - 0");

        Test(
            MO_TRUE,
            S16Minimum,
            Negative(1),
            MO_TRUE,
            Negative(32767),
            "signed 16-bit accepts minimum - -1");

        Test(
            MO_TRUE,
            S16Minimum,
            1,
            MO_FALSE,
            0,
            "signed 16-bit rejects minimum - 1");

        Test(
            MO_TRUE,
            Negative(32767),
            1,
            MO_TRUE,
            S16Minimum,
            "signed 16-bit accepts -32767 - 1");

        Test(
            MO_TRUE,
            Negative(32767),
            2,
            MO_FALSE,
            0,
            "signed 16-bit rejects -32767 - 2");

        Test(
            MO_TRUE,
            Negative(1),
            Negative(1),
            MO_TRUE,
            0,
            "signed 16-bit accepts -1 - -1");

        Test(
            MO_TRUE,
            S16Maximum,
            S16Minimum,
            MO_FALSE,
            0,
            "signed 16-bit rejects maximum - minimum");

        Test(
            MO_TRUE,
            S16Minimum,
            S16Maximum,
            MO_FALSE,
            0,
            "signed 16-bit rejects minimum - maximum");

        std::printf("MoMileFixedIntegerCheckedSubtraction16Test passed.\n");
    }

    void MoMileFixedIntegerCheckedMultiplication16Test()
    {
        auto Test = [](
            MO_BOOL Signed,
            MO_UINT16 Left,
            MO_UINT16 Right,
            MO_BOOL Expected,
            MO_UINT16 ExpectedResult,
            std::string_view Message = {},
            std::source_location const& Location = std::source_location::current())
        {
            MO_UINT16 const Sentinel = static_cast<MO_UINT16>(0xA5A5);
            MO_UINT16 Result = Sentinel;

            MO_BOOL Actual = ::MoMileFixedIntegerCheckedMultiplication16(
                &Result,
                Signed,
                Left,
                Right);

            ::Check(
                Expected == Actual,
                Message,
                Location);

            if (Expected)
            {
                ::Check(
                    ExpectedResult == Result,
                    Message,
                    Location);
            }
            else
            {
                ::Check(
                    Sentinel == Result,
                    Message,
                    Location);
            }
        };

        auto Negative = [](
            MO_UINT16 Magnitude) -> MO_UINT16
        {
            return static_cast<MO_UINT16>(0) - Magnitude;
        };

        MO_UINT16 const U16Maximum = static_cast<MO_UINT16>(
            static_cast<MO_UINT16>(0) - static_cast<MO_UINT16>(1));

        MO_UINT16 const S16Maximum =
            static_cast<MO_UINT16>((static_cast<MO_UINT16>(1) << 15) - 1);

        MO_UINT16 const S16Minimum =
            static_cast<MO_UINT16>(static_cast<MO_UINT16>(1) << 15);

        ::Check(
            MO_FALSE == ::MoMileFixedIntegerCheckedMultiplication16(
                nullptr,
                MO_FALSE,
                0,
                0),
            "null Result is invalid");

        Test(
            MO_FALSE,
            0,
            0,
            MO_TRUE,
            0,
            "unsigned 16-bit accepts 0 * 0");

        Test(
            MO_FALSE,
            0,
            U16Maximum,
            MO_TRUE,
            0,
            "unsigned 16-bit accepts 0 * maximum");

        Test(
            MO_FALSE,
            1,
            U16Maximum,
            MO_TRUE,
            U16Maximum,
            "unsigned 16-bit accepts 1 * maximum");

        Test(
            MO_FALSE,
            255,
            257,
            MO_TRUE,
            65535,
            "unsigned 16-bit accepts 255 * 257");

        Test(
            MO_FALSE,
            256,
            256,
            MO_FALSE,
            0,
            "unsigned 16-bit rejects 256 * 256");

        Test(
            MO_FALSE,
            U16Maximum,
            1,
            MO_TRUE,
            U16Maximum,
            "unsigned 16-bit accepts maximum * 1");

        Test(
            MO_FALSE,
            U16Maximum,
            2,
            MO_FALSE,
            0,
            "unsigned 16-bit rejects maximum * 2");

        Test(
            MO_FALSE,
            32768,
            2,
            MO_FALSE,
            0,
            "unsigned 16-bit rejects 32768 * 2");

        Test(
            MO_TRUE,
            0,
            0,
            MO_TRUE,
            0,
            "signed 16-bit accepts 0 * 0");

        Test(
            MO_TRUE,
            0,
            S16Minimum,
            MO_TRUE,
            0,
            "signed 16-bit accepts 0 * minimum");

        Test(
            MO_TRUE,
            1,
            S16Maximum,
            MO_TRUE,
            S16Maximum,
            "signed 16-bit accepts 1 * maximum");

        Test(
            MO_TRUE,
            S16Maximum,
            1,
            MO_TRUE,
            S16Maximum,
            "signed 16-bit accepts maximum * 1");

        Test(
            MO_TRUE,
            S16Maximum,
            2,
            MO_FALSE,
            0,
            "signed 16-bit rejects maximum * 2");

        Test(
            MO_TRUE,
            181,
            181,
            MO_TRUE,
            32761,
            "signed 16-bit accepts 181 * 181");

        Test(
            MO_TRUE,
            182,
            181,
            MO_FALSE,
            0,
            "signed 16-bit rejects 182 * 181");

        Test(
            MO_TRUE,
            Negative(1),
            1,
            MO_TRUE,
            Negative(1),
            "signed 16-bit accepts -1 * 1");

        Test(
            MO_TRUE,
            Negative(1),
            Negative(1),
            MO_TRUE,
            1,
            "signed 16-bit accepts -1 * -1");

        Test(
            MO_TRUE,
            S16Minimum,
            1,
            MO_TRUE,
            S16Minimum,
            "signed 16-bit accepts minimum * 1");

        Test(
            MO_TRUE,
            S16Minimum,
            0,
            MO_TRUE,
            0,
            "signed 16-bit accepts minimum * 0");

        Test(
            MO_TRUE,
            S16Minimum,
            Negative(1),
            MO_FALSE,
            0,
            "signed 16-bit rejects minimum * -1");

        Test(
            MO_TRUE,
            Negative(16384),
            2,
            MO_TRUE,
            S16Minimum,
            "signed 16-bit accepts -16384 * 2");

        Test(
            MO_TRUE,
            Negative(16385),
            2,
            MO_FALSE,
            0,
            "signed 16-bit rejects -16385 * 2");

        Test(
            MO_TRUE,
            Negative(256),
            Negative(128),
            MO_FALSE,
            0,
            "signed 16-bit rejects -256 * -128");

        Test(
            MO_TRUE,
            Negative(255),
            Negative(128),
            MO_TRUE,
            32640,
            "signed 16-bit accepts -255 * -128");

        Test(
            MO_TRUE,
            Negative(32767),
            1,
            MO_TRUE,
            Negative(32767),
            "signed 16-bit accepts -32767 * 1");

        Test(
            MO_TRUE,
            Negative(32767),
            2,
            MO_FALSE,
            0,
            "signed 16-bit rejects -32767 * 2");

        Test(
            MO_TRUE,
            S16Minimum,
            S16Minimum,
            MO_FALSE,
            0,
            "signed 16-bit rejects minimum * minimum");

        std::printf("MoMileFixedIntegerCheckedMultiplication16Test passed.\n");
    }

    void MoMileFixedIntegerCheckedAddition32Test()
    {
        auto Test = [](
            MO_BOOL Signed,
            MO_UINT32 Left,
            MO_UINT32 Right,
            MO_BOOL Expected,
            MO_UINT32 ExpectedResult,
            std::string_view Message = {},
            std::source_location const& Location = std::source_location::current())
        {
            MO_UINT32 const Sentinel = static_cast<MO_UINT32>(0xA5A5A5A5u);
            MO_UINT32 Result = Sentinel;

            MO_BOOL Actual = ::MoMileFixedIntegerCheckedAddition32(
                &Result,
                Signed,
                Left,
                Right);

            ::Check(
                Expected == Actual,
                Message,
                Location);

            if (Expected)
            {
                ::Check(
                    ExpectedResult == Result,
                    Message,
                    Location);
            }
            else
            {
                ::Check(
                    Sentinel == Result,
                    Message,
                    Location);
            }
        };

        auto Negative = [](
            MO_UINT32 Magnitude) -> MO_UINT32
        {
            return static_cast<MO_UINT32>(0) - Magnitude;
        };

        MO_UINT32 const U32Maximum = static_cast<MO_UINT32>(
            static_cast<MO_UINT32>(0) - static_cast<MO_UINT32>(1));

        MO_UINT32 const S32Maximum =
            (static_cast<MO_UINT32>(1) << 31) - 1;

        MO_UINT32 const S32Minimum =
            static_cast<MO_UINT32>(1) << 31;

        ::Check(
            MO_FALSE == ::MoMileFixedIntegerCheckedAddition32(
                nullptr,
                MO_FALSE,
                0,
                0),
            "null Result is invalid");

        Test(
            MO_FALSE,
            0,
            0,
            MO_TRUE,
            0,
            "unsigned 32-bit accepts 0 + 0");

        Test(
            MO_FALSE,
            1,
            2,
            MO_TRUE,
            3,
            "unsigned 32-bit accepts 1 + 2");

        Test(
            MO_FALSE,
            U32Maximum - 1,
            1,
            MO_TRUE,
            U32Maximum,
            "unsigned 32-bit accepts maximum - 1 + 1");

        Test(
            MO_FALSE,
            U32Maximum,
            0,
            MO_TRUE,
            U32Maximum,
            "unsigned 32-bit accepts maximum + 0");

        Test(
            MO_FALSE,
            U32Maximum,
            1,
            MO_FALSE,
            0,
            "unsigned 32-bit rejects maximum + 1");

        Test(
            MO_FALSE,
            static_cast<MO_UINT32>(1) << 31,
            static_cast<MO_UINT32>(1) << 31,
            MO_FALSE,
            0,
            "unsigned 32-bit rejects high-bit + high-bit");

        Test(
            MO_FALSE,
            4000000000u,
            294967295u,
            MO_TRUE,
            U32Maximum,
            "unsigned 32-bit accepts 4000000000 + 294967295");

        Test(
            MO_FALSE,
            4000000000u,
            294967296u,
            MO_FALSE,
            0,
            "unsigned 32-bit rejects 4000000000 + 294967296");

        Test(
            MO_TRUE,
            0,
            0,
            MO_TRUE,
            0,
            "signed 32-bit accepts 0 + 0");

        Test(
            MO_TRUE,
            1,
            1,
            MO_TRUE,
            2,
            "signed 32-bit accepts 1 + 1");

        Test(
            MO_TRUE,
            S32Maximum,
            0,
            MO_TRUE,
            S32Maximum,
            "signed 32-bit accepts maximum + 0");

        Test(
            MO_TRUE,
            S32Maximum - 1,
            1,
            MO_TRUE,
            S32Maximum,
            "signed 32-bit accepts maximum - 1 + 1");

        Test(
            MO_TRUE,
            S32Maximum,
            1,
            MO_FALSE,
            0,
            "signed 32-bit rejects maximum + 1");

        Test(
            MO_TRUE,
            static_cast<MO_UINT32>(1) << 30,
            (static_cast<MO_UINT32>(1) << 30) - 1,
            MO_TRUE,
            S32Maximum,
            "signed 32-bit accepts 2^30 + (2^30 - 1)");

        Test(
            MO_TRUE,
            static_cast<MO_UINT32>(1) << 30,
            static_cast<MO_UINT32>(1) << 30,
            MO_FALSE,
            0,
            "signed 32-bit rejects 2^30 + 2^30");

        Test(
            MO_TRUE,
            Negative(1),
            1,
            MO_TRUE,
            0,
            "signed 32-bit accepts -1 + 1");

        Test(
            MO_TRUE,
            Negative(1),
            Negative(1),
            MO_TRUE,
            Negative(2),
            "signed 32-bit accepts -1 + -1");

        Test(
            MO_TRUE,
            S32Minimum,
            0,
            MO_TRUE,
            S32Minimum,
            "signed 32-bit accepts minimum + 0");

        Test(
            MO_TRUE,
            S32Minimum,
            1,
            MO_TRUE,
            Negative(2147483647u),
            "signed 32-bit accepts minimum + 1");

        Test(
            MO_TRUE,
            S32Minimum,
            Negative(1),
            MO_FALSE,
            0,
            "signed 32-bit rejects minimum + -1");

        Test(
            MO_TRUE,
            Negative(2147483647u),
            Negative(1),
            MO_TRUE,
            S32Minimum,
            "signed 32-bit accepts -2147483647 + -1");

        Test(
            MO_TRUE,
            S32Minimum,
            S32Minimum,
            MO_FALSE,
            0,
            "signed 32-bit rejects minimum + minimum");

        Test(
            MO_TRUE,
            S32Maximum,
            Negative(1),
            MO_TRUE,
            S32Maximum - 1,
            "signed 32-bit accepts maximum + -1");

        Test(
            MO_TRUE,
            S32Minimum,
            S32Maximum,
            MO_TRUE,
            Negative(1),
            "signed 32-bit accepts minimum + maximum");

        std::printf("MoMileFixedIntegerCheckedAddition32Test passed.\n");
    }

    void MoMileFixedIntegerCheckedSubtraction32Test()
    {
        auto Test = [](
            MO_BOOL Signed,
            MO_UINT32 Left,
            MO_UINT32 Right,
            MO_BOOL Expected,
            MO_UINT32 ExpectedResult,
            std::string_view Message = {},
            std::source_location const& Location = std::source_location::current())
        {
            MO_UINT32 const Sentinel = static_cast<MO_UINT32>(0xA5A5A5A5u);
            MO_UINT32 Result = Sentinel;

            MO_BOOL Actual = ::MoMileFixedIntegerCheckedSubtraction32(
                &Result,
                Signed,
                Left,
                Right);

            ::Check(
                Expected == Actual,
                Message,
                Location);

            if (Expected)
            {
                ::Check(
                    ExpectedResult == Result,
                    Message,
                    Location);
            }
            else
            {
                ::Check(
                    Sentinel == Result,
                    Message,
                    Location);
            }
        };

        auto Negative = [](
            MO_UINT32 Magnitude) -> MO_UINT32
        {
            return static_cast<MO_UINT32>(0) - Magnitude;
        };

        MO_UINT32 const U32Maximum = static_cast<MO_UINT32>(
            static_cast<MO_UINT32>(0) - static_cast<MO_UINT32>(1));

        MO_UINT32 const S32Maximum =
            (static_cast<MO_UINT32>(1) << 31) - 1;

        MO_UINT32 const S32Minimum =
            static_cast<MO_UINT32>(1) << 31;

        ::Check(
            MO_FALSE == ::MoMileFixedIntegerCheckedSubtraction32(
                nullptr,
                MO_FALSE,
                0,
                0),
            "null Result is invalid");

        Test(
            MO_FALSE,
            0,
            0,
            MO_TRUE,
            0,
            "unsigned 32-bit accepts 0 - 0");

        Test(
            MO_FALSE,
            3,
            2,
            MO_TRUE,
            1,
            "unsigned 32-bit accepts 3 - 2");

        Test(
            MO_FALSE,
            U32Maximum,
            0,
            MO_TRUE,
            U32Maximum,
            "unsigned 32-bit accepts maximum - 0");

        Test(
            MO_FALSE,
            U32Maximum,
            U32Maximum,
            MO_TRUE,
            0,
            "unsigned 32-bit accepts maximum - maximum");

        Test(
            MO_FALSE,
            0,
            1,
            MO_FALSE,
            0,
            "unsigned 32-bit rejects 0 - 1");

        Test(
            MO_FALSE,
            1000000000u,
            1000000001u,
            MO_FALSE,
            0,
            "unsigned 32-bit rejects 1000000000 - 1000000001");

        Test(
            MO_TRUE,
            0,
            0,
            MO_TRUE,
            0,
            "signed 32-bit accepts 0 - 0");

        Test(
            MO_TRUE,
            1,
            0,
            MO_TRUE,
            1,
            "signed 32-bit accepts 1 - 0");

        Test(
            MO_TRUE,
            1,
            1,
            MO_TRUE,
            0,
            "signed 32-bit accepts 1 - 1");

        Test(
            MO_TRUE,
            0,
            1,
            MO_TRUE,
            Negative(1),
            "signed 32-bit accepts 0 - 1");

        Test(
            MO_TRUE,
            S32Maximum,
            0,
            MO_TRUE,
            S32Maximum,
            "signed 32-bit accepts maximum - 0");

        Test(
            MO_TRUE,
            S32Maximum,
            1,
            MO_TRUE,
            S32Maximum - 1,
            "signed 32-bit accepts maximum - 1");

        Test(
            MO_TRUE,
            S32Maximum,
            Negative(1),
            MO_FALSE,
            0,
            "signed 32-bit rejects maximum - -1");

        Test(
            MO_TRUE,
            0,
            Negative(1),
            MO_TRUE,
            1,
            "signed 32-bit accepts 0 - -1");

        Test(
            MO_TRUE,
            2000000000u,
            Negative(147483647u),
            MO_TRUE,
            S32Maximum,
            "signed 32-bit accepts 2000000000 - -147483647");

        Test(
            MO_TRUE,
            2000000000u,
            Negative(147483648u),
            MO_FALSE,
            0,
            "signed 32-bit rejects 2000000000 - -147483648");

        Test(
            MO_TRUE,
            S32Minimum,
            0,
            MO_TRUE,
            S32Minimum,
            "signed 32-bit accepts minimum - 0");

        Test(
            MO_TRUE,
            S32Minimum,
            Negative(1),
            MO_TRUE,
            Negative(2147483647u),
            "signed 32-bit accepts minimum - -1");

        Test(
            MO_TRUE,
            S32Minimum,
            1,
            MO_FALSE,
            0,
            "signed 32-bit rejects minimum - 1");

        Test(
            MO_TRUE,
            Negative(2147483647u),
            1,
            MO_TRUE,
            S32Minimum,
            "signed 32-bit accepts -2147483647 - 1");

        Test(
            MO_TRUE,
            Negative(2147483647u),
            2,
            MO_FALSE,
            0,
            "signed 32-bit rejects -2147483647 - 2");

        Test(
            MO_TRUE,
            Negative(1),
            Negative(1),
            MO_TRUE,
            0,
            "signed 32-bit accepts -1 - -1");

        Test(
            MO_TRUE,
            S32Maximum,
            S32Minimum,
            MO_FALSE,
            0,
            "signed 32-bit rejects maximum - minimum");

        Test(
            MO_TRUE,
            S32Minimum,
            S32Maximum,
            MO_FALSE,
            0,
            "signed 32-bit rejects minimum - maximum");

        std::printf("MoMileFixedIntegerCheckedSubtraction32Test passed.\n");
    }

    void MoMileFixedIntegerCheckedMultiplication32Test()
    {
        auto Test = [](
            MO_BOOL Signed,
            MO_UINT32 Left,
            MO_UINT32 Right,
            MO_BOOL Expected,
            MO_UINT32 ExpectedResult,
            std::string_view Message = {},
            std::source_location const& Location = std::source_location::current())
        {
            MO_UINT32 const Sentinel = static_cast<MO_UINT32>(0xA5A5A5A5u);
            MO_UINT32 Result = Sentinel;

            MO_BOOL Actual = ::MoMileFixedIntegerCheckedMultiplication32(
                &Result,
                Signed,
                Left,
                Right);

            ::Check(
                Expected == Actual,
                Message,
                Location);

            if (Expected)
            {
                ::Check(
                    ExpectedResult == Result,
                    Message,
                    Location);
            }
            else
            {
                ::Check(
                    Sentinel == Result,
                    Message,
                    Location);
            }
        };

        auto Negative = [](
            MO_UINT32 Magnitude) -> MO_UINT32
        {
            return static_cast<MO_UINT32>(0) - Magnitude;
        };

        MO_UINT32 const U32Maximum = static_cast<MO_UINT32>(
            static_cast<MO_UINT32>(0) - static_cast<MO_UINT32>(1));

        MO_UINT32 const S32Maximum =
            (static_cast<MO_UINT32>(1) << 31) - 1;

        MO_UINT32 const S32Minimum =
            static_cast<MO_UINT32>(1) << 31;

        ::Check(
            MO_FALSE == ::MoMileFixedIntegerCheckedMultiplication32(
                nullptr,
                MO_FALSE,
                0,
                0),
            "null Result is invalid");

        Test(
            MO_FALSE,
            0,
            0,
            MO_TRUE,
            0,
            "unsigned 32-bit accepts 0 * 0");

        Test(
            MO_FALSE,
            0,
            U32Maximum,
            MO_TRUE,
            0,
            "unsigned 32-bit accepts 0 * maximum");

        Test(
            MO_FALSE,
            1,
            U32Maximum,
            MO_TRUE,
            U32Maximum,
            "unsigned 32-bit accepts 1 * maximum");

        Test(
            MO_FALSE,
            65535u,
            65537u,
            MO_TRUE,
            U32Maximum,
            "unsigned 32-bit accepts 65535 * 65537");

        Test(
            MO_FALSE,
            65536u,
            65536u,
            MO_FALSE,
            0,
            "unsigned 32-bit rejects 65536 * 65536");

        Test(
            MO_FALSE,
            U32Maximum,
            1,
            MO_TRUE,
            U32Maximum,
            "unsigned 32-bit accepts maximum * 1");

        Test(
            MO_FALSE,
            U32Maximum,
            2,
            MO_FALSE,
            0,
            "unsigned 32-bit rejects maximum * 2");

        Test(
            MO_FALSE,
            static_cast<MO_UINT32>(1) << 31,
            2,
            MO_FALSE,
            0,
            "unsigned 32-bit rejects high-bit * 2");

        Test(
            MO_TRUE,
            0,
            0,
            MO_TRUE,
            0,
            "signed 32-bit accepts 0 * 0");

        Test(
            MO_TRUE,
            0,
            S32Minimum,
            MO_TRUE,
            0,
            "signed 32-bit accepts 0 * minimum");

        Test(
            MO_TRUE,
            1,
            S32Maximum,
            MO_TRUE,
            S32Maximum,
            "signed 32-bit accepts 1 * maximum");

        Test(
            MO_TRUE,
            S32Maximum,
            1,
            MO_TRUE,
            S32Maximum,
            "signed 32-bit accepts maximum * 1");

        Test(
            MO_TRUE,
            S32Maximum,
            2,
            MO_FALSE,
            0,
            "signed 32-bit rejects maximum * 2");

        Test(
            MO_TRUE,
            46340u,
            46340u,
            MO_TRUE,
            2147395600u,
            "signed 32-bit accepts 46340 * 46340");

        Test(
            MO_TRUE,
            46341u,
            46341u,
            MO_FALSE,
            0,
            "signed 32-bit rejects 46341 * 46341");

        Test(
            MO_TRUE,
            Negative(1),
            1,
            MO_TRUE,
            Negative(1),
            "signed 32-bit accepts -1 * 1");

        Test(
            MO_TRUE,
            Negative(1),
            Negative(1),
            MO_TRUE,
            1,
            "signed 32-bit accepts -1 * -1");

        Test(
            MO_TRUE,
            S32Minimum,
            1,
            MO_TRUE,
            S32Minimum,
            "signed 32-bit accepts minimum * 1");

        Test(
            MO_TRUE,
            S32Minimum,
            0,
            MO_TRUE,
            0,
            "signed 32-bit accepts minimum * 0");

        Test(
            MO_TRUE,
            S32Minimum,
            Negative(1),
            MO_FALSE,
            0,
            "signed 32-bit rejects minimum * -1");

        Test(
            MO_TRUE,
            Negative(static_cast<MO_UINT32>(1) << 30),
            2,
            MO_TRUE,
            S32Minimum,
            "signed 32-bit accepts -2^30 * 2");

        Test(
            MO_TRUE,
            Negative((static_cast<MO_UINT32>(1) << 30) + 1),
            2,
            MO_FALSE,
            0,
            "signed 32-bit rejects -(2^30 + 1) * 2");

        Test(
            MO_TRUE,
            Negative(65536u),
            Negative(32768u),
            MO_FALSE,
            0,
            "signed 32-bit rejects -65536 * -32768");

        Test(
            MO_TRUE,
            Negative(65535u),
            Negative(32768u),
            MO_TRUE,
            2147450880u,
            "signed 32-bit accepts -65535 * -32768");

        Test(
            MO_TRUE,
            Negative(2147483647u),
            1,
            MO_TRUE,
            Negative(2147483647u),
            "signed 32-bit accepts -2147483647 * 1");

        Test(
            MO_TRUE,
            Negative(2147483647u),
            2,
            MO_FALSE,
            0,
            "signed 32-bit rejects -2147483647 * 2");

        Test(
            MO_TRUE,
            S32Minimum,
            S32Minimum,
            MO_FALSE,
            0,
            "signed 32-bit rejects minimum * minimum");

        std::printf("MoMileFixedIntegerCheckedMultiplication32Test passed.\n");
    }
}

MO_EXTERN_C MO_VOID MoMileFixedIntegerTests()
{
    std::printf("Mile.Mobility.Utilities.FixedInteger Tests\n\n");

    ::MoMileFixedIntegerCheckedAddition8Test();
    ::MoMileFixedIntegerCheckedSubtraction8Test();
    ::MoMileFixedIntegerCheckedSubtraction8Test();

    ::MoMileFixedIntegerCheckedAddition16Test();
    ::MoMileFixedIntegerCheckedSubtraction16Test();
    ::MoMileFixedIntegerCheckedSubtraction16Test();

    ::MoMileFixedIntegerCheckedAddition32Test();
    ::MoMileFixedIntegerCheckedSubtraction32Test();
    ::MoMileFixedIntegerCheckedSubtraction32Test();
}
