#ifndef ENDSTATE_HPP
#define ENDSTATE_HPP
#include <algorithm>
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

    void forEachDrawable(std::function<void(std::unique_ptr<objects::IGameObject>&)> callback)
    {
        std::for_each(mGameObjects.begin(), mGameObjects.end(), callback);
    }

private:
    std::array<std::unique_ptr<objects::IGameObject>, ObjectQuantity> mGameObjects;
};

}  // namespace detail
}  // namespace statemachine
#endif  // ENDSTATE_HPP