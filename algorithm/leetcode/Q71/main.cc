#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

class Solution{
    public:
        string simplifyPath(string path){
            
            stringstream is(path);
            vector<string> strs;

            string res = "";
            string temp = "";

            while(getline(is, temp, '/')){
                if(temp == "" || temp == ".")
                    continue;
                else if(temp == ".." && !strs.empty())
                    strs.pop_back();
                else if (temp != "..")
                    strs.push_back(temp);
            }

            for(auto str:strs)
                res += "/" + str;
            
            if(res.empty())
                return "/";

            return res;

        }
};

int main(){

    Solution s = Solution();

    string path = "/home/";
    string res = s.simplifyPath(path);
    cout << res << endl;

    path = "/../";
    res = s.simplifyPath(path);
    cout << res << endl;

    path = "/home//foo/";
    res = s.simplifyPath(path);
    cout << res << endl;

    path = "/a/./b/../../c/";
    res = s.simplifyPath(path);
    cout << res << endl;

    return 0;
}