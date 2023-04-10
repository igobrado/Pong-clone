#ifndef IINPUTLISTENER_HPP
#define IINPUTLISTENER_HPP
#include <vector>

#include "Event.hpp"

namespace event
{

class IListener
{
public:
    virtual ~IListener() = default;

    virtual void                      onEvent(Event const e)     = 0;
    virtual std::vector<Event> const& getListeningEvents() const = 0;
};

}  // namespace event

#endif  // IINPUTLISTENER_HPP
