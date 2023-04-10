#ifndef COMMON_HPP
#define COMMON_HPP
#include <cinttypes>
#include <functional>

namespace display
{
namespace core
{

struct Pos
{
    constexpr Pos(int32_t const x, int32_t const y)  //
        : x{ x }
        , y{ y }
    {
    }

    int32_t x;
    int32_t y;
};

struct Color
{
    constexpr Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)  //
        : r{ r }
        , g{ g }
        , b{ b }
        , a{ a }
    {
    }

    uint8_t r, g, b, a;
};

static constexpr Color Black{ 0, 0, 0, 255 };
static constexpr Color Red{ 255, 0, 0, 255 };
static constexpr Color Blue{ 0, 0, 255, 255 };
static constexpr Color White{ 255, 255, 255, 255 };

}  // namespace core
}  // namespace display

namespace sdl_abstraction
{
template <typename T>
struct SdlObjectHolder
{
    SdlObjectHolder(T const& object, std::function<void(T)>&& destructor)
        : object{ object }
        , destructor{ std::move(destructor) }
    {
    }
    operator T()
    {
        return object;
    }

    ~SdlObjectHolder()
    {
        destructor(object);
    }

    T object;

private:
    std::function<void(T)> destructor;
};

}  // namespace sdl_abstraction
#endif  // COMMON_HPP
