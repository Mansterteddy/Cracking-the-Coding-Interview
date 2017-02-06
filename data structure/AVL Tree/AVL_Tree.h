#ifndef AVL_TREE_H_
#define AVL_TREE_H_

#include "AVLNode.h"
#include "BST_With_Rotate.h"

template<typename Item_Type>
class AVL_Tree : public BST_With_Rotate<Item_Type>
{
    public:
        AVL_Tree(): BST_With_Rotate<Item_Type>() {}

        virtual bool insert(const Item_Type& item)
        {
            return insert(this->root, item);
        }

    private:
        virtual bool insert(BTNode<Item_Type>*&, const Item_Type&);

        void rebalance_left(BTNode<Item_Type>*& local_root);

        void rebalance_right(BTNode<Item_Type>*& local_root);

        bool increase;
};

template<typename Item_Type>
bool AVL_Tree<Item_Type>::insert(BTNode<Item_Type>*& local_root, const Item_Type& item)
{
    if(local_root == NULL)
    {
        local_root = new AVLNode<Item_Type>(item);
        increase = true;
        return true;
    }   
    else
    {
        if(item < local_root->data)
        {
            bool return_value = insert(local_root->left, item);
            if(increase)
            {
                //Height of the left subtree has increased
                AVLNode<Item_Type>* AVL_local_root = dynamic_cast<AVLNode<Item_Type>*>(local_root);
                switch(AVL_local_root->balance)
                {
                    case AVLNode<Item_Type>::BALANCED:
                        AVL_local_root->balance = AVLNode<Item_Type>::LEFT_HEAVY;
                        break;
                    case AVLNode<Item_Type>::RIGHT_HEAVY:
                        AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
                        increase = false;
                        break;
                    case AVLNode<Item_Type>::LEFT_HEAVY:
                        rebalance_left(local_root);
                        increase = false;
                        break;
                }
            }
            return return_value;
        }
        else if(local_root->data < item)
        {
            bool return_value = insert(local_root->right, item);
            if(increase)
            {
                AVLNode<Item_Type>* AVL_local_root = dynamic_cast<AVLNode<Item_TYpe>*>(local_root);
                switch(AVL_local_root->balance)
                {
                    case AVLNode<Item_Type>::BALANCED:
                        AVL_local_root->balance = AVLNode<Item_Type>::RIGHT_HEAVY;
                        break;
                    case AVLNode<Item_Type>::LEFT_HEAVY:
                        AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
                        increase = false;
                        break;
                    case AVLNode<Item_Type>::RIGHT_HEAVY:
                        rebalance_right(local_root);
                        increase = false;
                        break;
                }
            }
        }
        else
        {
            increase = false;
            return false;
        }
    }
}

template<typename Item_Type>
void AVL_Tree<Item_Type>::rebalance_left(BTNode<Item_Type>*& local_root)
{
    AVLNode<Item_Type>* AVL_local_root = dynamic_cast<AVLNode<Item_Type>*>(local_root);
    AVLNode<Item_Type>* left_child = dynamic_cast<AVLNode<Item_Type>*>(local_root->left);

    if(left_child->balance == AVLNode<Item_Type>::RIGHT_HEAVY)
    {
        AVLNode<Item_Type>* left_right_child = dynamic_cast<AVLNode<Item_Type>*>(left_child->right);
        if(left_right_child->balance == AVLNode<Item_Type>::LEFT_HEAVY)
        {
            left_child->balance = AVLNode<Item_Type>::BALANCED;
            left_right_child->balance = AVLNode<Item_Type>::BALANCED;
            AVL_local_root->balance = AVLNode<Item_Type>::RIGHT_HEAVY;
        }
        else if(left_right_child->balance == AVLNode<Item_Type>::BALANCED)
        {
            left_child->balance = AVLNode<Item_Type>::BALANCED;
            left_right_child->balance = AVLNode<Item_Type>::BALANCED;
            AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
        }
        else
        {
            left_child->balance = AVLNode<Item_Type>::LEFT_HEAVY;
            left_right_child->balance = AVLNode<Item_Type>::BALANCED;
            AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
        }
        rotate_left(local_root->left);
    }
    else
    {
        left_child->balance = AVLNode<Item_Type>::BALANCED;
        AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
    }

    rotate_right(local_root);
}

template<typename Item_Type>
void AVL_Tree<Item_Type>::rebalance_right(BTNode<Item_Type>*& local_root)
{
    AVLNode<Item_Type>* AVL_local_root = dynamic_cast<AVLNode<Item_Type>*>(local_root);

    AVLNode<Item_Type*> right_child = dynamic_cast<AVLNode<Item_Type>*>(local_root->right);

    if(right_child->balance == AVLNode<Item_Type>::LEFT_HEAVY)
    {
        AVLNOde<Item_Type>* right_left_child = dynamic_cast<AVLNode<Item_Type>*>(right_child->left);
        if(right_left_child->balance == AVLNode<Item_Type>::RIGHT_HEAVY)
        {

        }
        else if(right_left_child->balance == AVLNode<Item_Type>::BALANCED)
        {

        }
        else
        {

        }

        rotate_right(local_root);
    }
    else
    {
        right_child->balance = AVLNode<Item_Type>::BALANCED;
        AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
    }
    rotate_left(local_root);
}

#endif