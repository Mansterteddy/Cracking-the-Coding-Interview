#include <iostream>
#include <string>
#include "count_occurences.cpp"

using namespace std;

int count_occurrences(char c, const string& s);

int main()
{
    string s = "Hello";
    int count;
    count = count_occurrences('H', s);
    cout << "count_occurrences('H', " << s << ") == " << count;
    cout << (count == 1 ? " PASSED" : " ******FAILED") << endl;
    count = count_occurrences('e', s);
    cout << "count_occurrences('e', " << s << ") == " << count;
    cout << (count == 1 ? " PASSED" : " ******FAILED") << endl;
    count = count_occurrences('l', s);
    cout << "count_occurrences('l', " << s << ") == " << count;
    cout << (count == 2 ? " PASSED" : " ******FAILED") << endl;
    count = count_occurrences('o', s);
    cout << "count_occurrences('o', " << s << ") == " << count;
    cout << (count == 1 ? " PASSED" : " ******FAILED") << endl;
    count = count_occurrences('x', s);
    cout << "count_occurrences('x', " << s << ") == " << count;
    cout << (count == 0 ? " PASSED" : " ******FAILED") << endl;
    return 0;
}