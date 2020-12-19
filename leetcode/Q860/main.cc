#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills.size() == 0){
            return true;
        }
        else if(bills.size() == 1){
            if(bills[0] == 5){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            map<int, int> money_map;

            bool res = false;

            money_map[5] = 0;
            money_map[10] = 0;

            for(int i = 0; i < bills.size(); ++i){
                if(bills[i] == 5){
                    money_map[5] += 1;
                }
                else if(bills[i] == 10){
                    if(money_map[5] == 0){
                        return res;
                    }
                    else{
                        money_map[5] -= 1;
                        money_map[10] += 1;
                    }
                }
                else{
                    if(money_map[10] == 0){
                        if(money_map[5] < 3){
                            return res;
                        }
                        else{
                            money_map[5] -= 3;
                        }
                    }
                    else{
                        if(money_map[5] < 1){
                            return res;
                        }
                        else{
                            money_map[5] -= 1;
                            money_map[10] -= 1;
                        }
                    }
                }

            }
            return true;
        }

    }
};

int main(){

    Solution s = Solution();

    vector<int> a{5, 5, 5, 10, 20};
    bool res_a = s.lemonadeChange(a);
    cout << res_a << endl;

    vector<int> b{5, 5, 10};
    bool res_b = s.lemonadeChange(b);
    cout << res_b << endl;

    vector<int> c{10, 10};
    bool res_c = s.lemonadeChange(c);
    cout << res_c << endl;

    vector<int> d{5, 5, 10, 10, 20};
    bool res_d = s.lemonadeChange(d);
    cout << res_d << endl;

    return 0;
}