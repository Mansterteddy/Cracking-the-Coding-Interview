#include <cmath>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int res = max(maxDepth(root->left), maxDepth(root->right)) + 1;
        return res;
    }
};

int main(){

    Solution s = Solution();

    TreeNode* root = new TreeNode(1);
    TreeNode* left = new TreeNode(2);
    TreeNode* right = new TreeNode(3);
    TreeNode* left_left = new TreeNode(4);

    root->left = left;
    root->right = right;
    left->left = left_left;

    int res = s.maxDepth(root);
    cout << res << endl;

    return 0;
}