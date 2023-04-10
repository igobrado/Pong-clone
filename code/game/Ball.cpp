#include "Ball.hpp"

namespace game
{

Ball::Ball()  //
    : mBall{ display::core::Red, { 100, 100 }, { 20, 20 } }
    , mSpeed{ 0.0f }
    , mMoveRegion{ 1000, 1000 }  // TODO: Set globally
    , mDirection{ 7., 7. }
{
}

void Ball::updateMovement(float const deltaTime)
{
    auto currentPosition                    = mBall.getPosition();
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

    auto const& pos = mBall.getPosition();
    mBall.setPosition({ pos.x + directionX, pos.y + directionY });
}

}  // namespace game