#include "Ball.hpp"

namespace game
{

Ball::Ball()  //
    : ::objects::Rectangle{ display::core::Red, { 100, 100 }, { 30, 30 } }
    , mSpeed{ 0.0f }
    , mMoveRegion{ 1000, 1000 }  // TODO: Set globally
    , mDirection{ 7., 7. }
{
}

void Ball::updateMovement(float const deltaTime)
{
    auto currentPosition                    = getPosition();
    auto const& [screenWidth, screenHeight] = mMoveRegion;
    auto& [directionX, directionY]          = mDirection;

    if (currentPosition.x < 0 || currentPosition.x > screenWidth)
    {
        directionX = -directionX;
    }
    else if (currentPosition.y < 0 || currentPosition.y > screenHeight)
    {
        directionY = -directionY;
    }

    setPosition({ currentPosition.x + directionX, currentPosition.y + directionY });
}

}  // namespace game