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
    }

    initCurrentState(mCurrentState);
}

void StateMachine::updateCurrentState(float const deltaTime)
{
    if (mCurrentState == State::kIntro)
    {
        std::get<detail::IntroState::Type>(mStates).update(deltaTime);
    }
    else if (mCurrentState == State::kGame)
    {
        std::get<detail::GameState::Type>(mStates).update(deltaTime);
    }
    else if (mCurrentState == State::kEnd)
    {
        std::get<detail::EndState::Type>(mStates).update(deltaTime);
    }
}

void StateMachine::initCurrentState(State state)
{
    if (mCurrentState == State::kIntro)
    {
        std::get<detail::IntroState::Type>(mStates).init();
    }
    else if (mCurrentState == State::kGame)
    {
        std::get<detail::GameState::Type>(mStates).init();
    }
    else if (mCurrentState == State::kEnd)
    {
        std::get<detail::EndState::Type>(mStates).init();
    }
}

}  // namespace statemachine
