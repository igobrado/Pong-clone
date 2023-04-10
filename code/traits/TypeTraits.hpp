#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

#include <type_traits>

using yes = std::true_type;
using no  = std::false_type;

template <typename T>
struct HasUpdate
{
    template <typename U, void (U::*)(float const)>
    struct SfinaeHelper;

    template <typename U>
    static auto Test(HasUpdate::SfinaeHelper<U, &U::updateImpl>*) -> decltype(yes{});

    template <typename>
    static auto Test(...) -> decltype(no{});

    static constexpr auto const value = std::is_same<decltype(Test<T>(0)), yes>::value;
};

#endif  // !TYPE_TRAITS_HPP
