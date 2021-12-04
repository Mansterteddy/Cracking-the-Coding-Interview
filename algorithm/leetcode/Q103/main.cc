#include <vector>
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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>> res;
            if (root == nullptr) return res;
            vector<TreeNode*> cur;
            cur.push_back(root);
            int level = 0;
            while (!cur.empty()) {
                vector<int> tmp;
                vector<TreeNode*> next;
                for (auto node : cur) {
                    tmp.push_back(node->val);
                    if (node->left) next.push_back(node->left);
                    if (node->right) next.push_back(node->right);
                }
                if (level % 2 == 0) res.push_back(tmp);
                else {
                    vector<int> tmp2;
                    for (int i = tmp.size() - 1; i >= 0; i--) 
                        tmp2.push_back(tmp[i]);
                    res.push_back(tmp2);
                }
                cur = next;
                level++;
            }
            return res;
        }
};

int main(){

    Solution s = Solution();

    TreeNode* root = new TreeNode(3);
    TreeNode* left = new TreeNode(9);
    TreeNode* right = new TreeNode(20);
    TreeNode* left_left = new TreeNode(15);
    TreeNode* left_right = new TreeNode(7);

    root->left = left;
    root->right = right;
    left->left = left_left;
    left->right = left_right;

    vector<vector<int>> res = s.zigzagLevelOrder(root);
    for (auto v : res) {
        for (auto i : v) 
            cout << i << " ";
        cout << endl;
    }

    return 0;
}