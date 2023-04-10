#ifndef INTROSTATE_HPP
#define INTROSTATE_HPP
#include <array>
#include <memory>

#include <display/interface/IGameObject.hpp>
#include <game/Ball.hpp>
#include <io/KeyboardListener.hpp>

namespace statemachine
{
namespace detail
{

class IntroState : public event::KeyboardListener
{
    // will be only 3 objects - texts .. in ideal world this can be configured via json / xml
    static constexpr uint32_t ObjectQuantity = 3;

public:
    IntroState()
        : KeyboardListener{ event::Event{ event::EventType::kKeyboardKeyPressed, event::KeyCodes::SPACE } }
        , mShouldExchange{ false }
    {
    }

    void init()
    {
        mBall = std::make_unique<::game::Ball>();
    }

    void update(float const deltaTime)
    {
        mBall->updateMovement(deltaTime);
    }

    bool shouldExchangeState()
    {
        return mShouldExchange;
    }

    void forEachDrawable(std::function<void(std::unique_ptr<objects::IGameObject>&)> callback)
    {
        callback(mBall);
    }

    void onKeyPressed(event::KeyCodes const eventKeyCode) override
    {
        mShouldExchange = true;
    }

    void onKeyReleased(event::KeyCodes const eventKeyCode) override
    {
    }

    void onCleanup() override
    {
    }

private:
    std::unique_ptr<objects::IGameObject> mBall;
    bool                                  mShouldExchange;
};

}  // namespace detail
}  // namespace statemachine
#endif  // INTROSTATE_HPP