#ifndef TIMETRACKER_HPP
#define TIMETRACKER_HPP
#include <chrono>
#include <iostream>
#include <string>


class TimeTracker
{
public:
    TimeTracker(const std::string& func);
    ~TimeTracker();

private:
    std::string name_func;
    std::chrono::high_resolution_clock::time_point start;
};

#endif // TIMETRACKER_HPP
