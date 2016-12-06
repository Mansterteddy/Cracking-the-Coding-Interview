#include "Clock.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setfill;
using std::setw;

bool verify(const Clock&, int, int, int);

int main()
{
    Clock a_clock;

    a_clock.set_clock(12, 34, 56);

    if(verify(a_clock, 12, 34, 56))
    cout << "PASS:    set_clock passed\n";
  
    // Increment clock
    a_clock.tick();
    if (verify(a_clock, 12, 34, 57))
        cout << "PASS:    tick one second\n";
    // Increment to advance to next minute;
    a_clock.tick();
    a_clock.tick();
    a_clock.tick();
    if (verify(a_clock, 12, 35, 00))
        cout << "PASS:    tick to next minute\n";
    
    a_clock.set_clock(12, 59, 59);
    a_clock.tick();
    if (verify(a_clock, 1, 00, 00))
        cout << "PASS:    tick to next hour\n";
    return 0;
}

bool verify(const Clock& clock, int hh, int mm, int ss)
{
  cout << "Clock should read " << setfill('0')
       << setw(2) << hh << ":"
       << setw(2) << mm << ":"
       << setw(2) << ss << '\n';
  if (clock.get_hours() != hh) {
    cout << "FAIL: Hours is " << clock.get_hours()
	 << " expected " << hh << endl;
    return false;
  }
  if (clock.get_minutes() != mm) {
    cout << "FAIL: Minutes is " << clock.get_minutes()
	 << " expected " << mm << endl;
    return false;
  }
  if (clock.get_seconds() != ss) {
    cout << "FAIL: Seconds is " << clock.get_seconds()
	 << " expected " << ss << endl;
    return false;
  }
  return true;
}
