#include <vector>
#include <iostream>

using namespace std;

class Solution{
    public:
        int maxArea(vector<int>& height){

            int start = 0;
            int end = height.size() - 1;
            int max_area = min(height[start], height[end]) * (end - start);

            while(start != end){
                int cur_area = min(height[start], height[end]) * (end - start);
                if(cur_area > max_area)
                    max_area = cur_area;
                if(height[start] < height[end])
                    start += 1;
                else
                    end -= 1;
            }

            return max_area;

        }
};

int main(){

    Solution s = Solution();

    vector<int> arr{1, 8, 6, 2, 5, 4, 8, 3, 7};
    int res = s.maxArea(arr);
    cout << res << endl;

    return 0;
}