#include "TimeTracker.hpp"

TimeTracker::TimeTracker(const std::string& func)
    :
      name_func(func)
{
    start = std::chrono::high_resolution_clock::now();
}

TimeTracker::~TimeTracker()
{
    std::chrono::high_resolution_clock::time_point  finish = std::chrono::high_resolution_clock::now();
    auto diff = std::chrono::duration<double, std::milli>(finish - start);
    double t = diff.count();
    std::cout << name_func << " time:" << diff.count() << "ms\n";
}
