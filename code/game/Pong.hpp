#ifndef PONG_HPP
#define PONG_HPP
#include <memory>

#include <display/impl/Window.hpp>
#include <game/Player.hpp>
#include <game/StateMachine.hpp>
#include <io/EventObserver.hpp>

class Pong
{
public:
    Pong();
    ~Pong();

    bool run();

private:
    void setupObservers();

    display::Window            mWindow;
    statemachine::StateMachine mStateMachine;
    Player                     mPlayerOne;
    Player                     mPlayerTwo;
    event::EventObserver       mObserver;
};

#endif  // !PONG_HPP
