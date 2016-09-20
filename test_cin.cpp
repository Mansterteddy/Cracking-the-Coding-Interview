#include <iostream>

using namespace std;

int main()
{
    int i;
    double j;
    char temp[20];
    cout<<"Enter a string: ";
    cin>>i;
    cin>>j;
    //To consume the whitespace or newline between the end of a token and the beginning of the next line:
    cin.get();
    cin.getline(temp, 20, '\n');
    cout<<"Answer is: "<<i<<" "<<j<<" "<<temp<<endl;

    double pi = 3.14159;
    cout<<fixed<<setprecision(2)<<pi<<endl;
    printf("%.2f", pi);

    return 0;
}