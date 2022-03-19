#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(NULL), right(NULL){}
    TreeNode(int x): val(x), left(NULL), right(NULL){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution{
    public:
        bool recursivePathSum(TreeNode* root, int targetSum){

            if(root->left == NULL && root->right != NULL) return recursivePathSum(root->right, targetSum - root->val);
            if(root->left != NULL && root->right == NULL)  return recursivePathSum(root->left, targetSum - root->val);
            if(root->left == NULL && root->right == NULL)  return targetSum == root->val;

            return recursivePathSum(root->left, targetSum - root->val) || recursivePathSum(root->right, targetSum - root->val);
        }

        bool hasPathSum(TreeNode* root, int targetSum){
            if(root == NULL) return false;

            if(root->left == NULL && root->right != NULL) return recursivePathSum(root->right, targetSum - root->val);
            if(root->left != NULL && root->right == NULL)  return recursivePathSum(root->left, targetSum - root->val);
            if(root->left == NULL && root->right == NULL)  return targetSum == root->val;

            return recursivePathSum(root->left, targetSum-root->val) || recursivePathSum(root->right, targetSum-root->val);

        }
};

int main(){

    Solution s = Solution();

    TreeNode* root = new TreeNode(1);
    TreeNode* left = new TreeNode(2);
    TreeNode* right = new TreeNode(3);
    root->left = left;
    root->right = right;

    bool res_1 = s.hasPathSum(root, 4);
    cout << res_1 << endl;

    bool res_2 = s.hasPathSum(root, 5);
    cout << res_2 << endl;

    return 0;
}
