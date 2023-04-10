#ifndef IGAMEOBJECT_HPP
#define IGAMEOBJECT_HPP
#include <cinttypes>

#include <display/common/Common.hpp>

namespace objects
{

enum class ObjectType
{
    kRectangle,
    kCircle
    // ...
};

using Color = display::core::Color;
using Pos   = display::core::Pos;

struct ObjectDimensions
{
    constexpr ObjectDimensions(uint32_t const width, uint32_t const height)  //
        : width{ width }
        , height{ height }
    {
    }

    uint32_t width;
    uint32_t height;
};

class IGameObject
{
public:
    virtual ~IGameObject() = default;

    virtual void setPosition(Pos const& position)                  = 0;
    virtual void setColor(Color const& color)                      = 0;
    virtual void setDimensions(ObjectDimensions const& dimensions) = 0;

    virtual ObjectDimensions const& getDimensions()     = 0;
    virtual Color const&            getColor() const    = 0;
    virtual Pos const&              getPosition() const = 0;
    virtual ObjectType              getObjectType()     = 0;
};

}  // namespace objects
#endif  // !IGAMEOBJECT_HPP
