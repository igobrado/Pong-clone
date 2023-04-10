#ifndef ENDSTATE_HPP
#define ENDSTATE_HPP
#include <array>
#include <memory>

#include <display/interface/IGameObject.hpp>
#include <game/IState.hpp>

namespace statemachine
{
namespace detail
{

class EndState : public IState<EndState, State::kEnd>
{
    // will be only 3 objects - texts .. in ideal world this can be configured via json / xml
    static constexpr uint32_t ObjectQuantity = 3;

public:
    EndState() = default;

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
#endif  // ENDSTATE_HPP