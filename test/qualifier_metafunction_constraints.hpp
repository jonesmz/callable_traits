/*
Copyright Barrett Adair 2016-2017

Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http ://boost.org/LICENSE_1_0.txt)

HEADER GUARDS INTENTIONALLY OMITTED
*/

#ifndef PP_CAT
#define PP_CAT_(x, y) x ## y
#define PP_CAT(x, y) PP_CAT_(x, y)
#endif

template<typename T>
struct PP_CAT(is_sub_failure_, CALLABLE_TRAIT_UNDER_TEST) {

    template<typename>
    static auto test(...) -> std::true_type;

    template<typename A,
        std::remove_reference_t<
            TRAIT(CALLABLE_TRAIT_UNDER_TEST, A)>* = nullptr>
    static auto test(int) -> std::false_type;

    static constexpr bool value = decltype(test<T>(0))::value;
};

bool PP_CAT(test_, CALLABLE_TRAIT_UNDER_TEST)() {
    static_assert(PP_CAT(is_sub_failure_, CALLABLE_TRAIT_UNDER_TEST)<int>::value);
    static_assert(PP_CAT(is_sub_failure_, CALLABLE_TRAIT_UNDER_TEST)<int &>::value);
    static_assert(PP_CAT(is_sub_failure_, CALLABLE_TRAIT_UNDER_TEST)<int(&)()>::value);
    static_assert(PP_CAT(is_sub_failure_, CALLABLE_TRAIT_UNDER_TEST)<int(*)()>::value);
    static_assert(PP_CAT(is_sub_failure_, CALLABLE_TRAIT_UNDER_TEST)<int(* const foo::*)()>::value);
    static_assert(PP_CAT(is_sub_failure_, CALLABLE_TRAIT_UNDER_TEST)<int foo::*>::value);
    static_assert(PP_CAT(is_sub_failure_, CALLABLE_TRAIT_UNDER_TEST)<int (foo::* &)()>::value);
    static_assert(PP_CAT(is_sub_failure_, CALLABLE_TRAIT_UNDER_TEST)<int (foo::* const)()>::value);
    static_assert(PP_CAT(is_sub_failure_, CALLABLE_TRAIT_UNDER_TEST)<int (foo::* const &)()>::value);
    static_assert(PP_CAT(is_sub_failure_, CALLABLE_TRAIT_UNDER_TEST)<int (foo::* volatile)()>::value);

    auto lambda = [](){};
    static_assert(PP_CAT(is_sub_failure_, CALLABLE_TRAIT_UNDER_TEST)<decltype(lambda)>::value);
    static_assert(PP_CAT(is_sub_failure_, CALLABLE_TRAIT_UNDER_TEST)<decltype(lambda)&>::value);
    static_assert(PP_CAT(is_sub_failure_, CALLABLE_TRAIT_UNDER_TEST)<void>::value);
    return true;
}

auto PP_CAT(var_, CALLABLE_TRAIT_UNDER_TEST) = PP_CAT(test_, CALLABLE_TRAIT_UNDER_TEST)();
