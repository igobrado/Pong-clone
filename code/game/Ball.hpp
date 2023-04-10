#ifndef BALL_HPP
#define BALL_HPP
#include <display/impl/Rectangle.hpp>

namespace game
{

class Ball
{
public:
    Ball();

    void updateMovement(float const deltaTime);

private:
    ::objects::Rectangle        mBall;
    float                       mSpeed;
    std::pair<int32_t, int32_t> mMoveRegion;
    std::pair<float, float>     mDirection;
};

}  // namespace game
#endif  // !BALL_HPP
