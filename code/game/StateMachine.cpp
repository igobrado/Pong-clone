#include "StateMachine.hpp"

namespace statemachine
{

static constexpr uint8_t kIntroType        = static_cast<uint8_t>(State::kIntro);
static constexpr uint8_t kGameStateType    = static_cast<uint8_t>(State::kGame);
static constexpr uint8_t kEndGameStateType = static_cast<uint8_t>(State::kEnd);

StateMachine::StateMachine(event::IObserver& observer)  //
    : mStates{}
    , mCurrentState{ State::kIntro }
    , mObserver{ observer }
{
    initCurrentState(mCurrentState);
}

void StateMachine::processChanges()
{
    switch (mCurrentState)
    {
        case statemachine::State::kIntro:
            if (std::get<kIntroType>(mStates).shouldExchangeState())
            {
                exchangeState(State::kGame);
                mObserver.detachListener(std::get<kIntroType>(mStates));
            }
            break;
        case statemachine::State::kGame:
            if (std::get<kGameStateType>(mStates).shouldExchangeState())
            {
                exchangeState(State::kEnd);
            }
            break;
        case statemachine::State::kEnd:
            if (std::get<kEndGameStateType>(mStates).shouldExchangeState())
            {
                exchangeState(State::kGame);
            }
            break;
        default:
            break;
    }
}

void StateMachine::exchangeState(State state)
{
    if (state != mCurrentState)
    {
        mCurrentState = state;
        initCurrentState(mCurrentState);
    }
}

void StateMachine::updateCurrentState(float const deltaTime)
{
    switch (mCurrentState)
    {
        case statemachine::State::kIntro:
            std::get<kIntroType>(mStates).update(deltaTime);
            break;
        case statemachine::State::kGame:
            std::get<kGameStateType>(mStates).update(deltaTime);
            break;
        case statemachine::State::kEnd:
            std::get<kEndGameStateType>(mStates).update(deltaTime);
            break;
        default:
            break;
    }
}

void StateMachine::drawObjects(display::IWindow& window)
{
    switch (mCurrentState)
    {
        case statemachine::State::kIntro:
            std::get<kIntroType>(mStates).forEachDrawable([&window](auto& obj) { window.draw(*obj); });
            break;
        case statemachine::State::kGame:
            std::get<kGameStateType>(mStates).forEachDrawable([&window](auto& obj) { window.draw(*obj); });
            break;
        case statemachine::State::kEnd:
            std::get<kEndGameStateType>(mStates).forEachDrawable([&window](auto& obj) { window.draw(*obj); });
            break;
        default:
            break;
    }
}

void StateMachine::initCurrentState(State state)
{
    switch (mCurrentState)
    {
        case statemachine::State::kIntro:
            std::get<kIntroType>(mStates).init();
            mObserver.attachListener(std::get<kIntroType>(mStates));
            break;
        case statemachine::State::kGame:
            std::get<kGameStateType>(mStates).init();
            break;
        case statemachine::State::kEnd:
            std::get<kEndGameStateType>(mStates).init();
            break;
        default:
            break;
    }
}

}  // namespace statemachine
