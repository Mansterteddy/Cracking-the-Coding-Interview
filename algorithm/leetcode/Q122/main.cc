#include <vector>
#include <iostream>

using namespace std;

class Solution{
    public:
        int maxProfit(vector<int>& prices){
            
            if(prices.size() == 0)
                return 0;

            int ans = 0;

            for(int i = 1; i < prices.size(); ++i){
                if(prices[i] > prices[i-1])
                    ans += prices[i] - prices[i-1];
            }

            return ans;
        }
};

int main(){

    Solution s = Solution();

    vector<int> prices_1{7,1,5,3,6,4};
    cout << s.maxProfit(prices_1) << endl;

    vector<int> prices_2{1,2,3,4,5};
    cout << s.maxProfit(prices_2) << endl;

    vector<int> prices_3{7,6,4,3,1};
    cout << s.maxProfit(prices_3) << endl;

    return 0;
}
