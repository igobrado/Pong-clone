#ifndef EVENT_HPP
#define EVENT_HPP
#include <cinttypes>
#include <functional>

namespace event
{

enum class EventType : uint8_t
{
    kKeyboardKeyPressed = 1,
    kKeyboardKeyReleased,
    kMouseMoved,
    kTouchpad,
    kIoClosed,
    kWindowClose
};

enum class KeyCodes : uint8_t
{
    W = 0,
    A,
    S,
    D,
    UpArrow,
    LeftArrow,
    RightArrow,
    DownArrow,

    kInvalid
};

class Event
{
public:
    Event(EventType eType, KeyCodes code)  //
        : mEventType{ eType }
        , mEventKeyCode{ code }
    {
    }

    virtual EventType getEventType() const
    {
        return mEventType;
    }

    virtual KeyCodes getKeyCode() const
    {
        return mEventKeyCode;
    }

private:
    EventType mEventType;
    KeyCodes  mEventKeyCode;
};

class KeyboardEvent : public Event
{
public:
    using Event::Event;

private:
};

class WindowEvent : public Event
{
public:
    WindowEvent() : Event{ EventType::kWindowClose, KeyCodes::kInvalid }
    {
    }
};
// ... mouse, touchpad, derivatives etc ..

}  // namespace event

namespace std
{

namespace  // anonymus
{

template <class T>
inline void hash_combine(std::size_t& seed, const T& v)
{
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

}  // namespace

template <>
struct hash<event::Event>
{
    std::size_t operator()(event::Event const& e) noexcept
    {

        auto type = e.getEventType();
        auto code = e.getKeyCode();

        auto typeHash = std::hash<decltype(type)>{}(type);
        auto codeHash = std::hash<decltype(code)>{}(code);

        std::size_t temp = 0U;
        hash_combine(temp, typeHash);
        hash_combine(temp, codeHash);

        return temp;
    }
};

}  // namespace std
#endif  // EVENT_HPP
