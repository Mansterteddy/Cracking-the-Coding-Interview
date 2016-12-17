#include <iostream>
#include <string>

using namespace std;

struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    char elem;
};

void BinaryTreeFromOrderings(char* inorder, char* preorder, int length)
{
    if(length == 0)
    {
        return;
    }
    TreeNode* node = new TreeNode;
    node->elem = *preorder;
    int rootIndex = 0;
    for(; rootIndex < length; rootIndex++)
    {
        if(inorder[rootIndex] == *preorder)
        break;
    }
    //left
    BinaryTreeFromOrderings(inorder, preorder + 1, rootIndex);
    //right
    BinaryTreeFromOrderings(inorder + rootIndex + 1, preorder + rootIndex + 1, length - (rootIndex + 1));
    cout<<node->elem<<endl;
    return;
}

int main()
{
    cout<<"Hello World!"<<endl;
    char* pr = "GDAFEMHZ";
    char* in = "ADEFGHMZ";

    BinaryTreeFromOrderings(in, pr, 8);

    cout<<"\n";
    return 0;
}