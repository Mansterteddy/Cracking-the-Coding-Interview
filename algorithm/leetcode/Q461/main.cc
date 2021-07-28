#include <iostream>

using namespace std;

class Solution{
    public:
        int hammingDistance(int x, int y){

            int res = 0;
            
            while(x!=0 || y!=0){
                if(x%2 != y%2){
                    res += 1;
                }
                x = x / 2;
                y = y / 2;
            }
            return res;
        }
};

int main(){

    Solution s = Solution();

    int res = s.hammingDistance(1, 4);
    cout << res << endl;

    res = s.hammingDistance(3, 1);
    cout << res << endl;

    return 0;
}