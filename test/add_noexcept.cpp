/*<-
Copyright (c) 2016 Barrett Adair

Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
->*/

#include <boost/callable_traits/detail/config.hpp>
#include <boost/callable_traits/add_noexcept.hpp>
#include "test.hpp"

template<typename Noexcept, typename NotNoexcept>
void test() {

    static_assert(std::is_same_v<Noexcept,  TRAIT(add_noexcept, NotNoexcept)>);

    //sanity check
    static_assert(!std::is_same_v<Noexcept, NotNoexcept>);
}

#define TEST_NOEXCEPT(not_noexcept) test<not_noexcept noexcept, not_noexcept>()

int main() {

    TEST_NOEXCEPT(int(int) &);
    TEST_NOEXCEPT(int(*)(int));
    TEST_NOEXCEPT(int(int, ...) &&);
    TEST_NOEXCEPT(int(*)(int, ...));

    struct foo;

    TEST_NOEXCEPT(int(foo::*)(int));
    TEST_NOEXCEPT(int(foo::*)(int) const);
    TEST_NOEXCEPT(int(foo::*)(int, ...));
    TEST_NOEXCEPT(int(foo::*)(int, ...) volatile);
}
