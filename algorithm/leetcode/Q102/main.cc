#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;

        vector<int> first_res;
        first_res.push_back(root->val);
        res.push_back(first_res);
        
        vector<TreeNode*> first_vec;
        vector<TreeNode*> second_vec;

        if(root->left != nullptr)
            first_vec.push_back(root->left);
        
        if(root->right != nullptr)
            first_vec.push_back(root->right);

        while(first_vec.size() != 0){
            vector<int> temp_res;
            for(auto node: first_vec){
                temp_res.push_back(node->val);
                if(node->left != nullptr)
                    second_vec.push_back(node->left);
                if(node->right != nullptr)
                    second_vec.push_back(node->right);
            }
            res.push_back(temp_res);
            first_vec = second_vec;
            second_vec = vector<TreeNode*>();
        }

        return res;
    }
};

int main(){

    Solution s = Solution();

    TreeNode* root = new TreeNode(3);
    TreeNode* left_1 = new TreeNode(9);
    TreeNode* right_1 = new TreeNode(20);
    TreeNode* left_2 = new TreeNode(15);
    TreeNode* right_2 = new TreeNode(7);

    root->left = left_1;
    root->right = right_1;
    left_1->left = left_2;
    left_1->right = right_2;

    vector<vector<int>> res = s.levelOrder(root);
    for(auto vec: res){
        for(auto val: vec){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}