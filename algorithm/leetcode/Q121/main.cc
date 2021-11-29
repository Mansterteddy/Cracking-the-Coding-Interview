#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int max_profit = 0;
            int min_price = INT_MAX;
            for (int i = 0; i < prices.size(); i++) {
                if (prices[i] < min_price) {
                    min_price = prices[i];
                }
                if (prices[i] - min_price > max_profit) {
                    max_profit = prices[i] - min_price;
                }
            }
            return max_profit;
        }
};

int main(){

    Solution s = Solution();

    vector<int> vec_a{7, 1, 5, 3, 6, 4};
    int res_a = s.maxProfit(vec_a);
    cout << res_a << endl;

    vector<int> vec_b{7, 6, 4, 3, 1};
    int res_b = s.maxProfit(vec_b);
    cout << res_b << endl;

    return 0;
}