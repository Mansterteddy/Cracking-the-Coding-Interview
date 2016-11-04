#ifndef CLOCK_H_
#define CLOCK_H_

/** The class Clock represents the time of a day*/
class Clock
{
    public:
        //The interface is defined here
        void set_clock(int hr, int min, int sec);

        int get_hours() const;

        int get_minutes() const;

        int get_seconds() const;

        //Advance the clock by one second.
        void tick();

    private:
        int hours;
        int minutes;
        int seconds;
};

#endif