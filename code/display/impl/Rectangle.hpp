#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <display/interface/IGameObject.hpp>
#include <io/KeyboardListener.hpp>

namespace objects
{

class Rectangle : public IGameObject
{
public:
    Rectangle() = default;
    Rectangle(Color const& color, Pos const& position, ObjectDimensions const& dimensions);

    void setPosition(Pos const& position) override;
    void setColor(Color const& color) override;
    void setDimensions(ObjectDimensions const& dimensions) override;

    ObjectDimensions const& getDimension() const override;
    Color const&            getColor() const override;
    Pos const&              getPosition() const override;
    ObjectType              getObjectType() const override;

    bool isCollided(IGameObject const& other) const override;

private:
    Color            mColor;
    Pos              mPosition;
    ObjectDimensions mDimensions;
};

}  // namespace objects

#endif  // !RECTANGLE_HPP
