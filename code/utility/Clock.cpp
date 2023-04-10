#include "Clock.hpp"

namespace utils
{

Clock::Clock()  //
    : mStart{ std::chrono::steady_clock::now() }
{
}

TimeInSeconds Clock::getElapsedTime() noexcept
{
    auto newNow = std::chrono::steady_clock::now();
    auto rv     = std::chrono::duration_cast<std::chrono::seconds>(newNow - mStart);

    mStart = newNow;

    return rv;
}

}  // namespace utils