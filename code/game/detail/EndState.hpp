#ifndef ENDSTATE_HPP
#define ENDSTATE_HPP
#include <algorithm>
#include <array>
#include <memory>

#include <display/interface/IGameObject.hpp>

namespace statemachine
{
namespace detail
{

class EndState
{
    // will be only 3 objects - texts .. in ideal world this can be configured via json / xml
    static constexpr uint32_t ObjectQuantity = 3;

public:
    EndState() = default;

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
    bool mShouldExchange = false;
};

}  // namespace detail
}  // namespace statemachine
#endif  // ENDSTATE_HPP