#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string str = "If I were a boy~";
    istringstream is(str);

    string s;
    ostringstream os;

    while(is>>s)
    {
        cout<<s<<endl;
        os<<s<<" ";
    }

    string s1 = os.str();
    cout<<"os: "<<s1<<endl;

    return 0;
}