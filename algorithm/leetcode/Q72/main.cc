#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution{
    public:
        int minDistance(string word1, string word2){
            if(word1.length() == 0) return word2.length();
            if(word2.length() == 0) return word1.length();

            vector<vector<int>> mat;

            for(int i = 0; i <= word1.length(); ++i){
                vector<int> cur_vec;
                if(i == 0){
                    for(int j = 0; j <= word2.length(); ++j){
                        cur_vec.push_back(j);
                    }
                }
                else{
                    for(int j = 0; j <= word2.length(); ++j){
                        if(j == 0)
                            cur_vec.push_back(i);
                        else
                            cur_vec.push_back(0);
                    }
                }
                mat.push_back(cur_vec);
            }
        
            for(int i = 1; i <= word1.length(); ++i){
                for(int j = 1; j <= word2.length(); ++j){
                    if(word1[i-1] == word2[j-1]){
                        mat[i][j] = min(mat[i-1][j-1], min(mat[i-1][j], mat[i][j-1]) + 1);
                    }
                    else{
                        mat[i][j] =  min(mat[i-1][j-1], min(mat[i-1][j], mat[i][j-1])) + 1;
                    }
                    
                }
            }

            // for(int i = 0; i <= word1.length(); ++i){
            //     for(int j = 0; j <= word2.length(); ++j){
            //         cout << mat[i][j] << " ";
            //     }
            //     cout << endl;
            // }

            return mat[word1.length()][word2.length()];
        
        }
};

int main(){

    Solution s = Solution();
    
    string word1 = "ros";
    string word2 = "horse";

    int res = s.minDistance(word1, word2);
    cout << res << endl;

    return 0;
}

//  start  h o r s e
// start 0 1 2 3 4 5
// r     1 1 2 2 3 4 
// o     2 2 1 2 3 4 
// s     3 3 2 2 2 3