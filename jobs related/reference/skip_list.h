#ifndef SKIP_LIST_H
#define SKIP_LIST_H 
//============================================================================== 
struct Skip_Node {
    int key;
    std::string value;

    // pointers to successor nodes
    std::vector<Skip_Node*> forward;

    Skip_Node (int k, const std::string& v, int level); 
};

//============================================================================== 
class Skip_list {
public:
    Skip_list ();
    ~Skip_list ();

    // non-modifying member functions
    void print ();
    Skip_Node* find (int searchKey);

    // modifying member functions
    void insert (int searchKey, std::string newValue);
    void erase (int searchKey); 
private:
    // pointer to first node
    Skip_Node* head;
    // last node
    Skip_Node* NIL;

    // implicitly used member functions
    int randomLevel (); 
    int nodeLevel(const std::vector<Skip_Node*>& v);
    Skip_Node* makeNode (int key, std::string val, int level);

    // data members  
    float probability;
    int maxLevel;
};

#include "Skip_list.cpp"
#endif