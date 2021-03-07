#include <ctime>
#include <iostream>

using namespace std;

int main(){

    time_t now = time(0);
    char* dt = ctime(&now);

    cout << "Current Time: " << dt << endl;

    tm* gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout << "UTC Time: " << dt << endl;

    cout << "seconds from 1970: " << now << endl;

    tm* ltm = localtime(&now);

    cout << 1900 + ltm->tm_year << endl;
    cout << 1 + ltm->tm_mon << endl;
    cout << ltm->tm_mday << endl;
    cout << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;

    return 0;
}