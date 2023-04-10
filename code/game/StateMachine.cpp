#include "StateMachine.hpp"

namespace statemachine
{

static const std::unordered_map<State, State> kStateMapping{ { State::kIntro, State::kGame },
                                                             { State::kGame, State::kEnd },
                                                             { State::kEnd, State::kIntro } };

StateMachine::StateMachine()  //
    : mStates{}
    , mCurrentState{ State::kIntro }
{
}

void StateMachine::exchangeState(State state)
{
    if (state != mCurrentState)
    {
        auto toTransit = kStateMapping.at(state);

        if (static_cast<uint8_t>(toTransit) == detail::IntroState::Type)
        {
            mCurrentState = toTransit;
        }
        else if (static_cast<uint8_t>(toTransit) == detail::GameState::Type)
        {
            mCurrentState = toTransit;
        }
        else if (static_cast<uint8_t>(toTransit) == detail::EndState::Type)
        {
            mCurrentState = toTransit;
        }

        initCurrentState(mCurrentState);
    }
}

void StateMachine::updateCurrentState(float const deltaTime)
{
    switch (mCurrentState)
    {
        case statemachine::State::kIntro:
            std::get<detail::IntroState::Type>(mStates).update(deltaTime);
            break;
        case statemachine::State::kGame:
            std::get<detail::GameState::Type>(mStates).update(deltaTime);
            break;
        case statemachine::State::kEnd:
            std::get<detail::EndState::Type>(mStates).update(deltaTime);
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
            std::get<detail::IntroState::Type>(mStates).forEachDrawable([&window](auto& obj) { window.draw(*obj); });
            break;
        case statemachine::State::kGame:
            std::get<detail::GameState::Type>(mStates).forEachDrawable([&window](auto& obj) { window.draw(*obj); });
            break;
        case statemachine::State::kEnd:
            std::get<detail::EndState::Type>(mStates).forEachDrawable([&window](auto& obj) { window.draw(*obj); });
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
            std::get<detail::IntroState::Type>(mStates).init();
            break;
        case statemachine::State::kGame:
            std::get<detail::GameState::Type>(mStates).init();
            break;
        case statemachine::State::kEnd:
            std::get<detail::EndState::Type>(mStates).init();
            break;
        default:
            break;
    }
}

}  // namespace statemachine
