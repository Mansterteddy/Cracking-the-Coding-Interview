#define MIN(x, y) ((x) < (y)) ? (x) : (y)
//#define ECHO(x) #x<<": "<<(x) 3<<2 输出32 (3<<2)输出12
#define ECHO(x) #x <<": "<<x
#define kw_assert(x)\
if(!(x)) {\
std::cerr<<"Assertion"<<#x<<" failed\n";\
std::cerr<<"Line"<<__LINE__<<" in file "<<__FILE__<<"\n";\
exit(1);\
}

#include <iostream>

using namespace std;

int main()
{
    int x= MIN(1, 2);
    float y = MIN(0.1, 0.2);
    cout<<"x: "<<x<<endl;
    cout<<"y: "<<y<<endl;
    cout<<ECHO(1)<<ECHO(2)<<ECHO(1 + 2)<<'\n';
    cout<<ECHO(3)<<ECHO(3 << 3)<<'\n';
    cout<<"3<<2: "<<(3<<3)<<'\n';
    kw_assert(5 < 3);
    return 0;
}