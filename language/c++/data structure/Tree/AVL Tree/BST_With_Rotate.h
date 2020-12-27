#ifndef BST_WITH_ROTATE_H_
#define BST_WITH_ROTATE_H_
#include "Binary_Search_Tree.h"

template<typename Item_Type>
class BST_With_Rotate : public Binary_Search_Tree<Item_Type>
{
    protected:
        void rotate_right(BTNode<Item_Type>*& local_root)
        {
            BTNode<Item_Type>* temp = local_root->left;
            local_root->left = temp->right;
            temp->right = local_root;
            local_root = temp;
        }

        void rotate_left(BTNode<Item_Type>*& local_root)
        {
            BTNode<Item_Type>* temp = local_root->right;
            local_root->right = temp->left;
            temp->left = local_root;
            local_root = temp;
        }
};

#endif