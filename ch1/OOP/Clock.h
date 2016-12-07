#ifndef __CLOCK__H__
#define __CLOCK__H__

class Clock
{
    public:
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