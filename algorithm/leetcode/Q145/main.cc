#include <vector>
#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    public:

        void recursive(TreeNode *root, vector<int> &res) {
            if (root == nullptr) {
                return;
            }
            recursive(root->left, res);
            recursive(root->right, res);
            res.push_back(root->val);
        }

        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> res;
            if (root == nullptr) return res;

            recursive(root, res);
            return res;
        }
};

int main(){

    Solution s = Solution();

    TreeNode *root = new TreeNode(1);
    TreeNode *right_1 = new TreeNode(2);
    TreeNode *left_2 = new TreeNode(3);
    root->right = right_1;
    right_1->left = left_2;

    vector<int> res = s.postorderTraversal(root);
    for(auto item: res){
        cout << item << " ";
    }
    cout << endl;
    
    return 0;
}