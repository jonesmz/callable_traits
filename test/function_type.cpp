
#include <boost/callable_traits/function_type.hpp>
#include "test.hpp"

int main() {

    struct foo;

    {
        auto g = [](int, char){};
        using G = decltype(g);
        using F = void(int, char);
        static_assert(std::is_same_v<TRAIT(function_type, G), F>);
        static_assert(std::is_same_v<function_type_t<G const &>, F>);
        static_assert(std::is_same_v<function_type_t<G const &&>, F>);
        static_assert(std::is_same_v<function_type_t<G volatile &>, F>);
        static_assert(std::is_same_v<function_type_t<G &>, F>);
        static_assert(std::is_same_v<function_type_t<G &&>, F>);
        static_assert(std::is_same_v<function_type_t<
            decltype(&G::operator())>, void(G const &, int, char)>);
    }

#ifndef BOOST_CLBL_TRTS_DISABLE_ABOMINABLE_FUNCTIONS
    {
        using G = void (int, char, ...) const LREF;
        using F = void (int, char, ...);
        static_assert(std::is_same_v<TRAIT(function_type, G), F>);
    }
#endif

    {
        using G = void (*)(int, char) BOOST_CLBL_TRTS_TRANSACTION_SAFE_SPECIFIER;
        using F = void (int, char);
        static_assert(std::is_same_v<TRAIT(function_type, G), F>);
    }{
        using G = void (* const &)(int, char);
        using F = void (int, char);
        static_assert(std::is_same_v<TRAIT(function_type, G), F>);
    }{
        using G = int (* &&)();
        using F = int ();
        static_assert(std::is_same_v<TRAIT(function_type, G), F>);
    }{
        using G = int (* &&)();
        using F = int ();
        static_assert(std::is_same_v<TRAIT(function_type, G), F>);
    }{
        using G = char const * const & (&)(...);
        using F = char const * const & (...);
        static_assert(std::is_same_v<TRAIT(function_type, G), F>);
    }{
        struct G { int operator() (...) volatile; };
        using F = int (...);
        static_assert(std::is_same_v<TRAIT(function_type, G), F>);
    }{
        struct G { int operator() (...) volatile noexcept; };
        using F = int (...);
        static_assert(std::is_same_v<TRAIT(function_type, G), F>);
    }{
        struct G { int operator() (...) const noexcept; };
        using F = int (...);
        static_assert(std::is_same_v<TRAIT(function_type, G), F>);
    }{
        using G = void (foo::* const &)(int, int, int) LREF BOOST_CLBL_TRTS_TRANSACTION_SAFE_SPECIFIER;
        using F = void (foo &, int, int, int);
        static_assert(std::is_same_v<TRAIT(function_type, G), F>);
    }
#ifndef BOOST_CLBL_TRTS_DISABLE_REFERENCE_QUALIFIERS
    {
        using G = void (foo::* const &)(int, int, int) RREF;
        using F = void (foo &&, int, int, int);
        static_assert(std::is_same_v<TRAIT(function_type, G), F>);
    }
#endif
    {
        using G = void (foo::*)(int, int, int) const BOOST_CLBL_TRTS_TRANSACTION_SAFE_SPECIFIER;
        using F = void (foo const &, int, int, int);
        static_assert(std::is_same_v<TRAIT(function_type, G), F>);
    }{
        using G = void (foo::*)(int, int, int);
        using F = void (foo &, int, int, int);
        static_assert(std::is_same_v<TRAIT(function_type, G), F>);
    }{
        using G = void (foo::*)() noexcept;
        using F = void (foo &);
        static_assert(std::is_same_v<TRAIT(function_type, G), F>);
    }{
        using G = void (foo::*)(int, int, int) const noexcept;
        using F = void (foo const &, int, int, int);
        static_assert(std::is_same_v<TRAIT(function_type, G), F>);
    }{
        using G = void (foo::*)(int, int, int, ...) const noexcept;
        using F = void (foo const &, int, int, int, ...);
        static_assert(std::is_same_v<TRAIT(function_type, G), F>);
    }
}
