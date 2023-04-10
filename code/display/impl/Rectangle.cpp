#include "Rectangle.hpp"

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

}  // namespace objects