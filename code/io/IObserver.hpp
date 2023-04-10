#ifndef IINPUT_HPP
#define IINPUT_HPP

#include <memory>

#include "Event.hpp"
#include "IListener.hpp"

namespace event
{

class IObserver
{
public:
    virtual ~IObserver() = default;

    virtual void pollEvent()             = 0;
    virtual void shutdown()              = 0;
    virtual void onEvent(Event const& e) = 0;

    virtual void attachListener(std::reference_wrapper<IListener> const& listener) = 0;
    virtual void detachListener(std::reference_wrapper<IListener> const& listener) = 0;
};

}  // namespace event

#endif  // IINPUT_HPP
