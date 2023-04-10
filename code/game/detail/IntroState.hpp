#ifndef INTROSTATE_HPP
#define INTROSTATE_HPP
#include <array>
#include <memory>

#include <display/interface/IGameObject.hpp>
#include <game/IState.hpp>

namespace statemachine
{
namespace detail
{

class IntroState : public IState<IntroState, State::kIntro>
{
    // will be only 3 objects - texts .. in ideal world this can be configured via json / xml
    static constexpr uint32_t ObjectQuantity = 3;

public:
    IntroState() = default;

    void init()
    {
    }

    void updateImpl(float const deltaTime)
    {
    }

private:
    std::array<std::unique_ptr<objects::IGameObject>, ObjectQuantity> mGameObjects;
};

}  // namespace detail
}  // namespace statemachine
#endif  // INTROSTATE_HPP