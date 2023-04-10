#ifndef CLOCK_HPP
#define CLOCK_HPP
#include <chrono>

namespace utils
{

using TimeInSeconds = std::chrono::seconds;

class Clock
{
public:
    Clock();
    ~Clock() = default;

    TimeInSeconds getElapsedTime() noexcept;

private:
    std::chrono::time_point<std::chrono::steady_clock> mStart;
};

}  // namespace utils
#endif  // !CLOCK_HPP
