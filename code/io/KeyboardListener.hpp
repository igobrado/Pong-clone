#ifndef KEYBOARDLISTENER_HPP
#define KEYBOARDLISTENER_HPP

#include <iostream>
#include <vector>

#include "IListener.hpp"

namespace event
{

class KeyboardListener : public IListener
{
public:
    KeyboardListener(Event const eventToListen);
    KeyboardListener(std::vector<Event> const& eventsToListen);

    void                      onEvent(Event const e) override;
    std::vector<Event> const& getListeningEvents() const override;

protected:
    virtual void onKeyPressed(KeyCodes const eventKeyCode)  = 0;
    virtual void onKeyReleased(KeyCodes const eventKeyCode) = 0;
    virtual void onCleanup()                                = 0;

private:
    std::vector<Event> mListeningEvents;
};

}  // namespace event

#endif  // KEYBOARDLISTENER_HPP
