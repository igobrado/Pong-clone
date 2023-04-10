#ifndef PONG_HPP
#define PONG_HPP
#include <memory>

#include <display/impl/Window.hpp>
#include <game/Player.hpp>
#include <game/StateMachine.hpp>
#include <io/EventObserver.hpp>
#include <utility/Clock.hpp>

class Pong
{
public:
    Pong();
    ~Pong();

    bool run();

private:
    void setupObservers();

    display::Window            mWindow;
    Player                     mPlayerOne;
    Player                     mPlayerTwo;
    event::EventObserver       mObserver;
    statemachine::StateMachine mStateMachine;
    utils::Clock               mClock;
};

#endif  // !PONG_HPP
