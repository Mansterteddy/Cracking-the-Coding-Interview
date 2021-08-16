#include <vector>
#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution{
    public:

        void recursiveTraversal(TreeNode* root, vector<int>& res_vec){

            if(root == nullptr) return;
            
            recursiveTraversal(root->left, res_vec);
            res_vec.push_back(root->val);
            recursiveTraversal(root->right, res_vec);
        }

        vector<int> inorderTraversal(TreeNode* root){

            vector<int> res;
            recursiveTraversal(root, res);
            return res;

        }
};


int main(){

    Solution s = Solution();

    TreeNode a = TreeNode(1);
    TreeNode b = TreeNode(2);
    TreeNode c = TreeNode(3);
    
    a.right = &b;
    b.left = &c;

    auto res = s.inorderTraversal(&a);
    for(auto item: res){
        cout << item << " ";
    }
    cout << endl;

    return 0;
}