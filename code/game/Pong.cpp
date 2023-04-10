#include "game/Pong.hpp"

#include <display/impl/Window.hpp>

Pong::Pong()  //
    : mWindow{ 500, 500 }
    , mPlayerOne{ "Mujo", 1 }
    , mPlayerTwo{ "Haso", 2 }
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

    while (!mWindow.shouldClose())
    {
        mObserver.pollEvent();

        mWindow.clear(display::core::White);
        // sdlWindow.draw(rect);
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
