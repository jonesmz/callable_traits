/*
Copyright Barrett Adair 2016-2017
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http ://boost.org/LICENSE_1_0.txt)
*/

#include <type_traits>
#include <functional>
#include <tuple>
#include <boost/callable_traits/add_member_volatile.hpp>
#include "test.hpp"

struct foo{};

int main() {
    
    {
        using f   = int(foo::*)(int);
        using l   = int(foo::*)(int) LREF;
        using r   = int(foo::*)(int) RREF;
        using c   = int(foo::*)(int) const;
        using cl  = int(foo::*)(int) const LREF;
        using cr  = int(foo::*)(int) const RREF;
        using v   = int(foo::*)(int) volatile;
        using vl  = int(foo::*)(int) volatile LREF;
        using vr  = int(foo::*)(int) volatile RREF;
        using cv  = int(foo::*)(int) const volatile;
        using cvl = int(foo::*)(int) const volatile LREF;
        using cvr = int(foo::*)(int) const volatile RREF;

        static_assert(std::is_same_v<v,    TRAIT(add_member_volatile, f)>);
        static_assert(std::is_same_v<v,    TRAIT(add_member_volatile, v)>);
        static_assert(std::is_same_v<vl,    TRAIT(add_member_volatile, l)>);
        static_assert(std::is_same_v<vl,    TRAIT(add_member_volatile, vl)>);
        static_assert(std::is_same_v<vr,   TRAIT(add_member_volatile, r)>);
        static_assert(std::is_same_v<vr,   TRAIT(add_member_volatile, vr)>);
        static_assert(std::is_same_v<cv,   TRAIT(add_member_volatile, c)>);
        static_assert(std::is_same_v<cv,   TRAIT(add_member_volatile, cv)>);
        static_assert(std::is_same_v<cvl,  TRAIT(add_member_volatile, cl)>);
        static_assert(std::is_same_v<cvl,  TRAIT(add_member_volatile, cvl)>);
        static_assert(std::is_same_v<cvr,  TRAIT(add_member_volatile, cr)>);
        static_assert(std::is_same_v<cvr,  TRAIT(add_member_volatile, cvr)>);
    }
    
#ifndef BOOST_CLBL_TRTS_DISABLE_ABOMINABLE_FUNCTIONS

    {
        using f   = foo();
        using l   = foo() LREF;
        using r   = foo() RREF;
        using c   = foo() const;
        using cl  = foo() const LREF;
        using cr  = foo() const RREF;
        using v   = foo() volatile;
        using vl  = foo() volatile LREF;
        using vr  = foo() volatile RREF;
        using cv  = foo() const volatile;
        using cvl = foo() const volatile LREF;
        using cvr = foo() const volatile RREF;

        static_assert(std::is_same_v<v,    TRAIT(add_member_volatile, f)>);
        static_assert(std::is_same_v<v,    TRAIT(add_member_volatile, v)>);
        static_assert(std::is_same_v<vl,    TRAIT(add_member_volatile, l)>);
        static_assert(std::is_same_v<vl,    TRAIT(add_member_volatile, vl)>);
        static_assert(std::is_same_v<vr,   TRAIT(add_member_volatile, r)>);
        static_assert(std::is_same_v<vr,   TRAIT(add_member_volatile, vr)>);
        static_assert(std::is_same_v<cv,   TRAIT(add_member_volatile, c)>);
        static_assert(std::is_same_v<cv,   TRAIT(add_member_volatile, cv)>);
        static_assert(std::is_same_v<cvl,  TRAIT(add_member_volatile, cl)>);
        static_assert(std::is_same_v<cvl,  TRAIT(add_member_volatile, cvl)>);
        static_assert(std::is_same_v<cvr,  TRAIT(add_member_volatile, cr)>);
        static_assert(std::is_same_v<cvr,  TRAIT(add_member_volatile, cvr)>);
    }

#endif
}
