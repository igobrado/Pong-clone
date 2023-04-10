#include "Rectangle.hpp"

#include <SDL.h>

namespace objects
{
Rectangle::Rectangle(Color const& color, Pos const& position, ObjectDimensions const& dimensions)  //
    : mColor{ color }
    , mPosition{ position }
    , mDimensions{ dimensions }
{
}

void Rectangle::setPosition(Pos const& position)
{
    mPosition = position;
}

void Rectangle::setColor(Color const& color)
{
    mColor = color;
}

void Rectangle::setDimensions(ObjectDimensions const& dimensions)
{
    mDimensions = dimensions;
}

ObjectDimensions const& Rectangle::getDimension() const
{
    return mDimensions;
}

Color const& Rectangle::getColor() const
{
    return mColor;
}

Pos const& Rectangle::getPosition() const
{
    return mPosition;
}

ObjectType Rectangle::getObjectType() const
{
    return ObjectType::kRectangle;
}

bool Rectangle::isCollided(IGameObject const& other) const
{
    SDL_Rect rectOne{ .x = static_cast<int>(mPosition.x),
                      .y = static_cast<int>(mPosition.y),
                      .w = static_cast<int>(mDimensions.width),
                      .h = static_cast<int>(mDimensions.height) };

    auto const& position   = other.getPosition();
    auto const& dimensions = other.getDimension();
    SDL_Rect    rectTwo{ .x = static_cast<int>(position.x),
                         .y = static_cast<int>(position.y),
                         .w = static_cast<int>(dimensions.width),
                         .h = static_cast<int>(dimensions.height) };

    return SDL_HasIntersection(&rectOne, &rectTwo);
}

}  // namespace objects