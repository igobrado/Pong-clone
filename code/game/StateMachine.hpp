#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

#include <memory>
#include <tuple>
#include <unordered_map>

#include <display/interface/IWindow.hpp>
#include <game/detail/EndState.hpp>
#include <game/detail/GameState.hpp>
#include <game/detail/IntroState.hpp>

namespace statemachine
{

enum class State : uint8_t
{
    kIntro = 0,
    kGame,
    kEnd
};

class StateMachine
{
    using StateMachineTransitionOrder = std::tuple<  //
            statemachine::detail::IntroState,
            statemachine::detail::GameState,
            statemachine::detail::EndState>;

public:
    StateMachine();

    void processChanges();

    void exchangeState(State state);
    void updateCurrentState(float const deltaTime);
    void drawObjects(display::IWindow& window);

protected:
    void initCurrentState(State state);

private:
    StateMachineTransitionOrder mStates;
    State                       mCurrentState;
};

}  // namespace statemachine

#endif  // STATEMACHINE_HPP