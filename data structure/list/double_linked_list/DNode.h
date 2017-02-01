#ifndef DNODE__H__
#define DNODE__H__

struct DNode
{
    Item_Type data;
    DNode* next;
    DNode* prev;
    DNode(const Item_Type& the_data,DNode* prev_val = NULL, DNode* next_val = NULL):
    data(the_data), next(next_val), prev(prev_val){}
};

#endif