//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// test numeric_limits

// traps

#include <limits>

template <class T, bool expected>
void
test()
{
    static_assert(std::numeric_limits<T>::traps == expected, "traps test 1");
    static_assert(std::numeric_limits<const T>::traps == expected, "traps test 2");
    static_assert(std::numeric_limits<volatile T>::traps == expected, "traps test 3");
    static_assert(std::numeric_limits<const volatile T>::traps == expected, "traps test 4");
}

int main()
{
    test<bool, false>();
    test<char, true>();
    test<signed char, true>();
    test<unsigned char, true>();
    test<wchar_t, true>();
#ifndef _LIBCPP_HAS_NO_UNICODE_CHARS
    test<char16_t, true>();
    test<char32_t, true>();
#endif  // _LIBCPP_HAS_NO_UNICODE_CHARS
    test<short, true>();
    test<unsigned short, true>();
    test<int, true>();
    test<unsigned int, true>();
    test<long, true>();
    test<unsigned long, true>();
    test<long long, true>();
    test<unsigned long long, true>();
    test<float, false>();
    test<double, false>();
    test<long double, false>();
}
