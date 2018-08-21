#include <vector>
#include <iostream>

using namespace std;

template<typename Item_Type> int binary_search(const std::vector<Item_Type>& items, int first, int last, const Item_Type& target)
{
    if(first > last)
    {
        return -1;
    }
    else
    {
        int middle = (first + last) / 2;
        if(target==items[middle])
        {
            return middle;
        }
        else if(target < items[middle])
        {
            return binary_search(items, first, middle-1, target);
        }
        else
        {
            return binary_search(items, middle+1, last, target);
        }
    }
}

int main()
{
    vector<int> vec = {1, 3, 4, 6, 7, 8, 9, 13};
    int res = binary_search(vec, 0, vec.size()-1, 7);
    cout << "res: " << res << endl;

    return 0;
}