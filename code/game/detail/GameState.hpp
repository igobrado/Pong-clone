#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
#include <array>
#include <memory>

#include <display/interface/IGameObject.hpp>

namespace statemachine
{
namespace detail
{

class GameState
{
    // will be only 3 objects - texts .. in ideal world this can be configured via json / xml
    static constexpr uint32_t ObjectQuantity = 3;

public:
    GameState() = default;

    void init()
    {
    }

    bool shouldExchangeState()
    {
        return mShouldExchange;
    }

    void update(float const deltaTime)
    {
    }

    void forEachDrawable(std::function<void(std::unique_ptr<objects::IGameObject>&)> callback)
    {
        // std::for_each(mGameObjects.begin(), mGameObjects.end(), callback);
    }

private:
    bool mShouldExchange = false;  // game is over?
};

}  // namespace detail
}  // namespace statemachine
#endif  // GAMESTATE_HPP