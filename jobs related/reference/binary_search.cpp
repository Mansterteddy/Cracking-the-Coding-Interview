#include <iostream>

using namespace std;

int main()
{
    int a[] = {1, 2, 3, 4, 6, 8, 10};

    int len = sizeof(a) / sizeof(a[0]);

    int up = 0;
    int down = len - 1;
    int search = 13;

    while(up <= down)
    {
        int mid = (up + down) / 2;

        if(a[mid] == search)
        {
            up = mid;
            break;
        }
        else if(a[mid] > search)
        {
            down = mid - 1;
        }
        else
        {
            up = mid + 1;
        }
    }

    cout<<"pos: "<<up<<endl;

    return 0;
}