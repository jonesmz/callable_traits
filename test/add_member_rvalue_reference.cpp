/*
Copyright Barrett Adair 2016-2017
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http ://boost.org/LICENSE_1_0.txt)
*/

#include <type_traits>
#include <functional>
#include <tuple>
#include <boost/callable_traits.hpp>
#include "test.hpp"

#ifdef BOOST_CLBL_TRTS_DISABLE_REFERENCE_QUALIFIERS
int main(){ return 0; }
#else


struct foo{};

int main() {
    {
        using f   = void(foo::*)();
        using l   = void(foo::*)() &;
        using r   = void(foo::*)() &&;
        using c   = void(foo::*)() const;
        using cl  = void(foo::*)() const &;
        using cr  = void(foo::*)() const &&;
        using v   = void(foo::*)() volatile;
        using vl  = void(foo::*)() volatile &;
        using vr  = void(foo::*)() volatile &&;
        using cv  = void(foo::*)() const volatile;
        using cvl = void(foo::*)() const volatile &;
        using cvr = void(foo::*)() const volatile &&;

        static_assert(std::is_same_v<r,    TRAIT(add_member_rvalue_reference, f)>);
        static_assert(std::is_same_v<cr,   TRAIT(add_member_rvalue_reference, c)>);
        static_assert(std::is_same_v<vr,   TRAIT(add_member_rvalue_reference, v)>);
        static_assert(std::is_same_v<cvr,  TRAIT(add_member_rvalue_reference, cv)>);
        static_assert(std::is_same_v<l,    TRAIT(add_member_rvalue_reference, l)>);
        static_assert(std::is_same_v<cl,   TRAIT(add_member_rvalue_reference, cl)>);
        static_assert(std::is_same_v<vl,   TRAIT(add_member_rvalue_reference, vl)>);
        static_assert(std::is_same_v<cvl,  TRAIT(add_member_rvalue_reference, cvl)>);
        static_assert(std::is_same_v<r,    TRAIT(add_member_rvalue_reference, r)>);
        static_assert(!std::is_same_v<r,   TRAIT(add_member_rvalue_reference, l)>);
        static_assert(std::is_same_v<cr,   TRAIT(add_member_rvalue_reference, cr)>);
        static_assert(std::is_same_v<vr,   TRAIT(add_member_rvalue_reference, vr)>);
        static_assert(std::is_same_v<cvr,  TRAIT(add_member_rvalue_reference, cvr)>);
    }

    {
        using f   = void(foo::*)();
        using l   = void(foo::*)() &;
        using r   = void(foo::*)() &&;
        using c   = void(foo::*)() const;
        using cl  = void(foo::*)() const &;
        using cr  = void(foo::*)() const &&;
        using v   = void(foo::*)() volatile;
        using vl  = void(foo::*)() volatile &;
        using vr  = void(foo::*)() volatile &&;
        using cv  = void(foo::*)() const volatile;
        using cvl = void(foo::*)() const volatile &;
        using cvr = void(foo::*)() const volatile &&;

        static_assert(std::is_same_v<r,    TRAIT(add_member_rvalue_reference, f)>);
        static_assert(std::is_same_v<cr,   TRAIT(add_member_rvalue_reference, c)>);
        static_assert(std::is_same_v<vr,   TRAIT(add_member_rvalue_reference, v)>);
        static_assert(std::is_same_v<cvr,  TRAIT(add_member_rvalue_reference, cv)>);
        static_assert(std::is_same_v<l,    TRAIT(add_member_rvalue_reference, l)>);
        static_assert(std::is_same_v<cl,   TRAIT(add_member_rvalue_reference, cl)>);
        static_assert(std::is_same_v<vl,   TRAIT(add_member_rvalue_reference, vl)>);
        static_assert(std::is_same_v<cvl,  TRAIT(add_member_rvalue_reference, cvl)>);
        static_assert(std::is_same_v<r,    TRAIT(add_member_rvalue_reference, r)>);
        static_assert(!std::is_same_v<r,   TRAIT(add_member_rvalue_reference, l)>);
        static_assert(std::is_same_v<cr,   TRAIT(add_member_rvalue_reference, cr)>);
        static_assert(std::is_same_v<vr,   TRAIT(add_member_rvalue_reference, vr)>);
        static_assert(std::is_same_v<cvr,  TRAIT(add_member_rvalue_reference, cvr)>);
    }

    {
        using f   = void(foo::*)(...);
        using l   = void(foo::*)(...) &;
        using r   = void(foo::*)(...) &&;
        using c   = void(foo::*)(...) const;
        using cl  = void(foo::*)(...) const &;
        using cr  = void(foo::*)(...) const &&;
        using v   = void(foo::*)(...) volatile;
        using vl  = void(foo::*)(...) volatile &;
        using vr  = void(foo::*)(...) volatile &&;
        using cv  = void(foo::*)(...) const volatile;
        using cvl = void(foo::*)(...) const volatile &;
        using cvr = void(foo::*)(...) const volatile &&;

        static_assert(std::is_same_v<r,    TRAIT(add_member_rvalue_reference, f)>);
        static_assert(std::is_same_v<cr,   TRAIT(add_member_rvalue_reference, c)>);
        static_assert(std::is_same_v<vr,   TRAIT(add_member_rvalue_reference, v)>);
        static_assert(std::is_same_v<cvr,  TRAIT(add_member_rvalue_reference, cv)>);
        static_assert(std::is_same_v<l,    TRAIT(add_member_rvalue_reference, l)>);
        static_assert(std::is_same_v<cl,   TRAIT(add_member_rvalue_reference, cl)>);
        static_assert(std::is_same_v<vl,   TRAIT(add_member_rvalue_reference, vl)>);
        static_assert(std::is_same_v<cvl,  TRAIT(add_member_rvalue_reference, cvl)>);
        static_assert(std::is_same_v<r,    TRAIT(add_member_rvalue_reference, r)>);
        static_assert(!std::is_same_v<r,   TRAIT(add_member_rvalue_reference, l)>);
        static_assert(std::is_same_v<cr,   TRAIT(add_member_rvalue_reference, cr)>);
        static_assert(std::is_same_v<vr,   TRAIT(add_member_rvalue_reference, vr)>);
        static_assert(std::is_same_v<cvr,  TRAIT(add_member_rvalue_reference, cvr)>);
    }
    
    {
        using f   = void(foo::*)();
        using l   = void(foo::*)() &;
        using r   = void(foo::*)() &&;
        using c   = void(foo::*)() const;
        using cl  = void(foo::*)() const &;
        using cr  = void(foo::*)() const &&;
        using v   = void(foo::*)() volatile;
        using vl  = void(foo::*)() volatile &;
        using vr  = void(foo::*)() volatile &&;
        using cv  = void(foo::*)() const volatile;
        using cvl = void(foo::*)() const volatile &;
        using cvr = void(foo::*)() const volatile &&;

        static_assert(std::is_same_v<r,    TRAIT(add_member_rvalue_reference, f)>);
        static_assert(std::is_same_v<cr,   TRAIT(add_member_rvalue_reference, c)>);
        static_assert(std::is_same_v<vr,   TRAIT(add_member_rvalue_reference, v)>);
        static_assert(std::is_same_v<cvr,  TRAIT(add_member_rvalue_reference, cv)>);
        static_assert(std::is_same_v<l,    TRAIT(add_member_rvalue_reference, l)>);
        static_assert(std::is_same_v<cl,   TRAIT(add_member_rvalue_reference, cl)>);
        static_assert(std::is_same_v<vl,   TRAIT(add_member_rvalue_reference, vl)>);
        static_assert(std::is_same_v<cvl,  TRAIT(add_member_rvalue_reference, cvl)>);
        static_assert(std::is_same_v<r,    TRAIT(add_member_rvalue_reference, r)>);
        static_assert(!std::is_same_v<r,   TRAIT(add_member_rvalue_reference, l)>);
        static_assert(std::is_same_v<cr,   TRAIT(add_member_rvalue_reference, cr)>);
        static_assert(std::is_same_v<vr,   TRAIT(add_member_rvalue_reference, vr)>);
        static_assert(std::is_same_v<cvr,  TRAIT(add_member_rvalue_reference, cvr)>);
    }
    
    {
        using f   = void();
        using l   = void() &;
        using r   = void() &&;
        using c   = void() const;
        using cl  = void() const &;
        using cr  = void() const &&;
        using v   = void() volatile;
        using vl  = void() volatile &;
        using vr  = void() volatile &&;
        using cv  = void() const volatile;
        using cvl = void() const volatile &;
        using cvr = void() const volatile &&;

        static_assert(std::is_same_v<r,    TRAIT(add_member_rvalue_reference, f)>);
        static_assert(std::is_same_v<cr,   TRAIT(add_member_rvalue_reference, c)>);
        static_assert(std::is_same_v<vr,   TRAIT(add_member_rvalue_reference, v)>);
        static_assert(std::is_same_v<cvr,  TRAIT(add_member_rvalue_reference, cv)>);
        static_assert(std::is_same_v<l,    TRAIT(add_member_rvalue_reference, l)>);
        static_assert(std::is_same_v<cl,   TRAIT(add_member_rvalue_reference, cl)>);
        static_assert(std::is_same_v<vl,   TRAIT(add_member_rvalue_reference, vl)>);
        static_assert(std::is_same_v<cvl,  TRAIT(add_member_rvalue_reference, cvl)>);
        static_assert(std::is_same_v<r,    TRAIT(add_member_rvalue_reference, r)>);
        static_assert(!std::is_same_v<r,   TRAIT(add_member_rvalue_reference, l)>);
        static_assert(std::is_same_v<cr,   TRAIT(add_member_rvalue_reference, cr)>);
        static_assert(std::is_same_v<vr,   TRAIT(add_member_rvalue_reference, vr)>);
        static_assert(std::is_same_v<cvr,  TRAIT(add_member_rvalue_reference, cvr)>);
    }
}

#endif //#ifdef BOOST_CLBL_TRTS_DISABLE_REFERENCE_QUALIFIERS
