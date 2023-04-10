#ifndef STATE_HPP
#define STATE_HPP

#include <traits/TypeTraits.hpp>

namespace statemachine
{

enum class State : uint8_t
{
    kIntro = 0,
    kGame  = 1,
    kEnd   = 2
};

template <typename T, State S>
class IState
{
public:
    static constexpr auto Type = static_cast<uint8_t>(S);

    void update(float const deltaTime)
    {
        static_assert(HasUpdate<T>::value, "T class has to have method with signature:  void updateImpl(float const)");
        static_cast<T*>(this)->updateImpl(deltaTime);
    }

protected:
    void updateImpl(float const deltaTime) = delete;
};

}  // namespace statemachine
#endif  // !STATE_HPP
