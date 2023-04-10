#ifndef WINDOWEVENTLISTENER_HPP
#define WINDOWEVENTLISTENER_HPP

#include <iostream>
#include <vector>

#include "IListener.hpp"

namespace event
{

class WindowEventListener : public IListener
{
public:
    WindowEventListener(Event const eventToListen);

    void                      onEvent(Event const e) override;
    std::vector<Event> const& getListeningEvents() const override;

protected:
    virtual void onCloseEvent() = 0;

private:
    std::vector<Event> mListeningEvents;
};

}  // namespace event

#endif  // WINDOWEVENTLISTENER_HPP
