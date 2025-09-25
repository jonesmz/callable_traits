/*
Copyright Barrett Adair 2016-2017
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http ://boost.org/LICENSE_1_0.txt)
*/

#include <type_traits>
#include <functional>
#include <tuple>
#include <utility>
#include <boost/callable_traits.hpp>

using namespace boost::callable_traits;

#ifdef BOOST_CLBL_TRTS_DISABLE_REFERENCE_QUALIFIERS
#define LREF
#define RREF
#else
#define LREF &
#define RREF &&
#endif

#define TX_SAFE BOOST_CLBL_TRTS_TRANSACTION_SAFE_SPECIFIER
#define VA_CC BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC

#ifndef PP_CAT
#define PP_CAT_(x, y) x ## y
#define PP_CAT(x, y) PP_CAT_(x, y)
#endif

#ifdef USE_LAZY_TYPES
#define TRAIT(trait, ...) typename trait<__VA_ARGS__>::type
#else
#define TRAIT(trait, ...) PP_CAT(trait, _t)<__VA_ARGS__>
#endif

#ifdef BOOST_CLBL_TRTS_DISABLE_ABOMINABLE_FUNCTIONS
#define TEST_ABOM_V
#else
#define TEST_ABOM_V volatile
#endif

template<typename T1, typename T2>
void assert_same() {
    static_assert(std::is_same_v<T1, T2>);
}
