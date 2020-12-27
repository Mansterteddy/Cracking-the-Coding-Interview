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

        virtual bool erase(const Item_Type& item)
        {
            return erase_1(this->root, item);
        }

    private:

        virtual bool erase(BTNode<Item_Type>*&, const Item_Type&);

        virtual bool insert(BTNode<Item_Type>*&, const Item_Type&);

        void rebalance_left(BTNode<Item_Type>*& local_root);

        void rebalance_right(BTNode<Item_Type>*& local_root);

        bool increase;

        virtual void replace_parent(BTNode<Item_Type>*& old_root, 
                              BTNode<Item_Type>*& local_root);
};

/*
AVL树的删除是一个很有趣的问题，首先我们要确认一件事，AVL树是一棵平衡树。
虽然每个节点的高度，等于两个子节点的更高者，但是这两个子节点的差距不会超过2，每个节点都如是，因此最后的树也会比较平衡，但不会是BST。
节点高度的定义方式也为删除顶点带来了一定的方便。
当删除某个节点时，首先和合适的叶子节点进行交换，交换后，就可以删除该叶子节点了
但是在删除叶子节点时，考虑此时叶子结点的父亲节点，此时可能会发生高度的变化，因此要对父亲节点进行合适的处理。
当然父亲节点处理后，父亲节点的父亲节点也可能会发生高度的变化，因此对父亲节点的父亲节点也要进行处理。
*/

template<typename Item_Type>
bool AVL_Tree<Item_Type>::erase(BTNode<Item_Type>*& local_root, const Item_Type& item)
{
    cout<<"item: "<<item<<endl;
  if (local_root == NULL) 
  {
    return false;
  } 
  else 
  {
    if (item < local_root->data)
      return erase(local_root->left, item);
    else if (local_root->data < item)
      return erase(local_root->right, item);
    else 
    { // Found item
      BTNode<Item_Type>* old_root = local_root;
      if (local_root->left == NULL) 
      {
        local_root = local_root->right;
      } 
      else if (local_root->right == NULL) 
      {
        local_root = local_root->left;
      } 
      else 
      {
        replace_parent(old_root, old_root->left);
      }
      delete old_root;
      return true;
    }
  }
}

template<typename Item_Type>
void 
AVL_Tree<Item_Type>::replace_parent(BTNode<Item_Type>*& old_root,
					      BTNode<Item_Type>*& local_root) 
{
  if (local_root->right != NULL) 
  {
    replace_parent(old_root, local_root->right);
  } 
  else 
  {
    old_root->data = local_root->data;
    old_root = local_root;
    local_root = local_root->left;
  }
}

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
                AVLNode<Item_Type>* AVL_local_root = dynamic_cast<AVLNode<Item_Type>*>(local_root);
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

    AVLNode<Item_Type>* right_child = dynamic_cast<AVLNode<Item_Type>*>(local_root->right);

    if(right_child->balance == AVLNode<Item_Type>::LEFT_HEAVY)
    {
        AVLNode<Item_Type>* right_left_child = dynamic_cast<AVLNode<Item_Type>*>(right_child->left);
        if(right_left_child->balance == AVLNode<Item_Type>::RIGHT_HEAVY)
        {
            right_child->balance = AVLNode<Item_Type>::BALANCED;
            right_left_child->balance = AVLNode<Item_Type>::BALANCED;
            AVL_local_root->balance = AVLNode<Item_Type>::LEFT_HEAVY;
        }
        else if(right_left_child->balance == AVLNode<Item_Type>::BALANCED)
        {
            right_child->balance = AVLNode<Item_Type>::BALANCED;
            right_left_child->balance = AVLNode<Item_Type>::BALANCED;
            AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
        }
        else
        {
            right_child->balance = AVLNode<Item_Type>::RIGHT_HEAVY;
            right_left_child->balance = AVLNode<Item_Type>::BALANCED;
            AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
        }

        rotate_right(local_root->right);
    }
    else
    {
        right_child->balance = AVLNode<Item_Type>::BALANCED;
        AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
    }
    rotate_left(local_root);
}

#endif