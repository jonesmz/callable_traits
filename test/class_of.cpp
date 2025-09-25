#include <tuple>
#include <utility>
#include <type_traits>
#include <boost/callable_traits/class_of.hpp>
#include "test.hpp"

struct foo;

int main() {

    {
        using f = void(foo::*)();
        using test =  TRAIT(class_of, f);
        using expect = foo;
        CT_ASSERT(std::is_same_v<test, expect>);
    }

    {
        using f = void(foo::*)() const;
        using test =  TRAIT(class_of, f);
        using expect = foo;
        CT_ASSERT(std::is_same_v<test, expect>);
    }

    {
        using f = void(foo::*)() volatile;
        using test =  TRAIT(class_of, f);
        using expect = foo;
        CT_ASSERT(std::is_same_v<test, expect>);
    }

    {
        using f = void(BOOST_CLBL_TRTS_DEFAULT_VARARGS_CC foo::*)(int, ...) const volatile;
        using test =  TRAIT(class_of, f);
        using expect = foo;
        CT_ASSERT(std::is_same_v<test, expect>);
    }

    {
        using f = int foo::*;
        using test =  TRAIT(class_of, f);
        using expect = foo;
        CT_ASSERT(std::is_same_v<test, expect>);
    }

    {
        using f = const int foo::*;
        using test =  TRAIT(class_of, f);
        using expect = foo;
        CT_ASSERT(std::is_same_v<test, expect>);
    }
}
