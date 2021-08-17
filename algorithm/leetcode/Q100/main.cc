#include <vector>
#include <string>
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

        void recursivePreOrderTraversal(TreeNode* root, string& res){
            if(root == nullptr) 
            {
                res += "null";
                return;
            }

            res += '0' + root->val;
            recursivePreOrderTraversal(root->left, res);
            recursivePreOrderTraversal(root->right, res);
        }

        void recursiveInOrderTraversal(TreeNode* root, string& res){
            
            if(root == nullptr) 
            {
                res += "null";
                return;
            }

            recursiveInOrderTraversal(root->left, res);
            res += '0' + root->val;
            recursiveInOrderTraversal(root->right, res);
        }

        bool isSameTree(TreeNode* p, TreeNode* q){
            string p_a = "";
            recursivePreOrderTraversal(p, p_a);
            string p_b = "";
            recursiveInOrderTraversal(p, p_b);

            string q_a = "";
            recursivePreOrderTraversal(q, q_a);
            string q_b = "";
            recursiveInOrderTraversal(q, q_b);

            //cout << p_a << " " << p_b << endl;
            //cout << q_a << " " << q_b << endl;

            if(p_a == q_a && p_b == q_b) return true;
            else return false;

        }

};


int main(){

    Solution s = Solution();

    TreeNode a = TreeNode(1);
    TreeNode b = TreeNode(2);
    TreeNode c = TreeNode(3);
    
    a.right = &b;
    b.left = &c;

    TreeNode d = TreeNode(1);
    TreeNode e = TreeNode(2);
    TreeNode f = TreeNode(3);
    
    d.right = &e;
    e.left = &f;

    auto res = s.isSameTree(&a, &d);
    cout << res << endl;

    return 0;
}