#include "EventObserver.hpp"

#include <SDL.h>

#include <functional>
#include <iostream>

namespace event
{

static const KeyCodes toKeyCode(uint32_t keycode)
{
    switch (keycode)
    {
        case SDL_SCANCODE_W:
            return KeyCodes::W;
        case SDL_SCANCODE_A:
            return KeyCodes::A;
        case SDL_SCANCODE_S:
            return KeyCodes::S;
        case SDL_SCANCODE_D:
            return KeyCodes::D;
        case SDL_SCANCODE_UP:
            return KeyCodes::UpArrow;
        case SDL_SCANCODE_DOWN:
            return KeyCodes::DownArrow;
        case SDL_SCANCODE_LEFT:
            return KeyCodes::LeftArrow;
        case SDL_SCANCODE_RIGHT:
            return KeyCodes::RightArrow;
        case SDLK_SPACE:
            return KeyCodes::SPACE;

        default:
            return KeyCodes::kInvalid;
    }
}

EventObserver::EventObserver()  //
    : mListeners{}
{
}

EventObserver ::~EventObserver()
{
    EventObserver::shutdown();
}

void EventObserver::shutdown()
{
    for (const auto& listenerHashPair : mListeners)
    {
        for (const auto& listener : listenerHashPair.second)
        {
            listener.get().onEvent({ EventType::kIoClosed, KeyCodes::kInvalid });
        }
    }
}

void EventObserver::onEvent(Event const& e)
{
    try
    {
        auto hsh = std::hash<Event>{}(e);
        for (auto const& listener : mListeners.at(hsh))
        {
            listener.get().onEvent(e);
        }
    }
    catch (std::exception const&)
    {  // just in case that someone is stupid ^^, as .at() is
       // O(1) access (hashmap) and find. is O(N)
    }
}

void EventObserver::attachListener(std::reference_wrapper<IListener> const& listener)
{
    for (const auto& evt : listener.get().getListeningEvents())
    {
        auto  listeningEventHash = std::hash<event::Event>{}(evt);
        auto& listeners          = mListeners[listeningEventHash];
        listeners.push_back(listener);
    }
}

void EventObserver::detachListener(std::reference_wrapper<IListener> const& listener)
{
    for (const auto& evt : listener.get().getListeningEvents())
    {
        auto  eventHash = std::hash<event::Event>{}(evt);
        auto& listeners = mListeners[eventHash];

        if (!listeners.empty())
        {
            listeners.erase(
                    std::remove_if(
                            listeners.begin(),
                            listeners.end(),
                            [&listener](auto registeredListener) {
                                return &registeredListener.get() == &listener.get();
                            }),
                    listeners.end());
        }
    }
    // don't hold memory if there is no need
    // mListeners.erase(mListeners.find(eventHash));
}

void EventObserver::pollEvent()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        auto type = event.type;

        if (type == SDL_KEYDOWN)
        {
            onEvent(Event{ EventType::kKeyboardKeyPressed, toKeyCode(event.key.keysym.scancode) });
        }

        if (type == SDL_KEYUP)
        {
            onEvent(Event{ EventType::kKeyboardKeyReleased, toKeyCode(event.key.keysym.scancode) });
        }

        if (type == SDL_QUIT)
        {
            onEvent(Event{ EventType::kWindowClose, KeyCodes::kInvalid });
        }
    }
}

}  // namespace event