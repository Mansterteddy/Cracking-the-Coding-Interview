#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    bool check(TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr)
            return true;
        
        if(left == nullptr || right == nullptr)
            return false;

        return (left->val == right->val) && check(left->left, right->right) && check(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        bool res = check(root->left, root->right);
        return res;
    }
};

int main(){
    
    Solution s = Solution();

    TreeNode* root = new TreeNode(1);
    TreeNode* left_1 = new TreeNode(2);
    TreeNode* right_1 = new TreeNode(2);
    TreeNode* left_2 = new TreeNode(3);
    TreeNode* right_2 = new TreeNode(3);

    root->left = left_1;
    root->right = right_1;
    left_1->left = left_2;
    right_1->right = right_2;

    bool res = s.isSymmetric(root);
    cout << res << endl;

    return 0;
}

