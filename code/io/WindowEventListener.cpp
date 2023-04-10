#include "WindowEventListener.hpp"

namespace event
{

WindowEventListener::WindowEventListener(Event const eventToListen)  //
    : mListeningEvents{ eventToListen }
{
}

void WindowEventListener::WindowEventListener::onEvent(Event const e)
{
    if (e.getEventType() == EventType::kWindowClose)
    {
        onCloseEvent();
    }
}

std::vector<Event> const& WindowEventListener::WindowEventListener::getListeningEvents() const
{
    return mListeningEvents;
}

}  // namespace event