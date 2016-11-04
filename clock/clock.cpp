#include "clock.h"

void Clock::set_clock(int hr, int min, int sec)
{
    hours = hr;
    minutes = min;
    seconds = sec;
}

int Clock::get_hours() const
{
    return hours;
}

int Clock::get_minutes() const
{
    return minutes;
}

int Clock::get_seconds() const
{
    return seconds;
}

void Clock::tick()
{
    seconds++;
    if (seconds >= 60)
    {
        minutes++;
        seconds -= 60;
    }
    if(minutes >= 60)
    {
        hours++;
        minutes -= 60;
    }
    if(hours > 12)
    {
        hours -= 12;
    }
}