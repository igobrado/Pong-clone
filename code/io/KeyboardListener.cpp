#include "KeyboardListener.hpp"

namespace event
{

KeyboardListener::KeyboardListener(Event const eventToListen)  //
    : mListeningEvents{ eventToListen }
{
}

KeyboardListener::KeyboardListener(std::vector<Event> const& eventsToListen)  //
    : mListeningEvents{ eventsToListen }
{
}

void KeyboardListener::onEvent(Event const e)
{
    if (e.getEventType() == EventType::kKeyboardKeyPressed)
    {
        onKeyPressed(e.getKeyCode());
    }
    else if (e.getEventType() == EventType::kKeyboardKeyReleased)
    {
        onKeyReleased(e.getKeyCode());
    }
    else if (e.getEventType() == EventType::kIoClosed)
    {
        onCleanup();
    }
}

std::vector<Event> const& KeyboardListener::getListeningEvents() const
{
    return mListeningEvents;
}

}  // namespace event