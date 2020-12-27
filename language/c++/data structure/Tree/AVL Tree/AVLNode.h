#ifndef AVLNODE_H_
#define AVLNODE_H_
#include <sstream>
#include "BTNode.h"

template<typename Item_Type>
struct AVLNode : public BTNode<Item_Type>
{
    enum balance_type {LEFT_HEAVY = -1, BALANCED = 0, RIGHT_HEAVY = +1};

    balance_type balance;

    AVLNode(const Item_Type& the_data, BTNode<Item_Type>* left_val = NULL, BTNode<Item_Type>* right_val = NULL) :
    BTNode<Item_Type>(the_data, left_val, right_val), balance(BALANCED) {}

    virtual ~AVLNode() {}

    virtual std::string to_string() const 
    {
        std::ostringstream os;
        os<<balance<<" : "<<this->data;
        return os.str();
    }
};

#endif