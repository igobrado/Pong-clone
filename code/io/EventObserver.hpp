#ifndef KEYBOARDINPUT_HPP
#define KEYBOARDINPUT_HPP

#include <atomic>
#include <mutex>
#include <thread>
#include <unordered_map>

#include "IObserver.hpp"

namespace event
{

class EventObserver : public IObserver
{
public:
    EventObserver();
    ~EventObserver() override;

    void pollEvent() override;

    void shutdown() override;
    void onEvent(Event const& e) override;

    void attachListener(std::reference_wrapper<IListener> const& listener) override;
    void detachListener(std::reference_wrapper<IListener> const& listener) override;

protected:
private:
    std::unordered_map<std::size_t, std::vector<std::reference_wrapper<IListener>>> mListeners;
};

}  // namespace event
#endif  // KEYBOARDINPUT_HPP
