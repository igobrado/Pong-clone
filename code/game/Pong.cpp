#include "game/Pong.hpp"

#include <display/impl/Window.hpp>
static constexpr float const sDeltaTime = 1.0f / 80.0f;
Pong::Pong()  //
    : mWindow{ 500, 500 }
    , mPlayerOne{ "Mujo", 1 }
    , mPlayerTwo{ "Haso", 2 }
    , mObserver{}
    , mStateMachine{ mObserver }
    , mClock{}
{
    SDL_Init(SDL_INIT_EVERYTHING);
}

Pong::~Pong()
{
    mObserver.detachListener(mPlayerOne);
    mObserver.detachListener(mPlayerTwo);
    mObserver.detachListener(mWindow);
    SDL_Quit();
}

bool Pong::run()
{
    // register IO
    if (!mWindow.initialize())
    {
        return false;
    }

    setupObservers();

    float newTime, frameTime;
    float currentTime = mClock.getElapsedTime().count();
    float accumulator = 0.0f;

    while (!mWindow.shouldClose())
    {
        mObserver.pollEvent();

        // TODO: Calculate delta time

        while (accumulator > sDeltaTime)
        {
            newTime   = mClock.getElapsedTime().count();
            frameTime = newTime - currentTime;
            if (frameTime > 0.25f)
            {
                frameTime = 0.025f;
            }
            currentTime = newTime;
            accumulator += frameTime;

            mStateMachine.processChanges();
            mStateMachine.updateCurrentState(sDeltaTime);
            accumulator -= sDeltaTime;
        }

        mWindow.clear(display::core::White);
        mStateMachine.drawObjects(mWindow);
        mWindow.commit();
    }

    return true;
}

void Pong::setupObservers()
{
    mObserver.attachListener(mPlayerOne);
    mObserver.attachListener(mPlayerTwo);
    mObserver.attachListener(mWindow);
}
