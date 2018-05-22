#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

namespace KW
{
    template <typename Item_Type>
    class DLL
    {
        public:
            #include "DNode.h"
    };
}

typedef KW::DLL<string>::DNode DNode;

void print_list(DNode* node)
{
  if (node) 
  {
    if (node->prev && node->prev->next != node) 
    {
      cout << node->prev->data << " <== ";
    }

    cout << node->data;
    
    if (node->next) 
    {
      if (node->next->prev == node) 
      {
	       cout << " <=> ";
      } 
      else 
      {
	       cout << " ==> ";
      }
      print_list(node->next);
    }
   } 
   else 
   {
      cout << "NULL";
   }
      cout << endl;
}

int main()
{
    DNode* tom = new DNode("Tom");
    DNode* dick = new DNode("Dick");
    DNode* harry = new DNode("Harry");
    DNode* sam = new DNode("Sam");
  
    tom->next = dick;
    dick->prev = tom;
    dick->next = harry;
    harry->prev = dick;
    harry->next = sam;
    sam->prev = harry;
  
    print_list(tom);
  
    DNode* sharon = new DNode("Sharon");
    // Link new DNode to its neighbors.
    sharon->next = sam;       // Step 1
    sharon->prev = sam->prev; // Step 2
    // Link old predecessor of sam to new predecessor.
    sam->prev->next = sharon; // Step 3
    // Link to new predecessor.
    sam->prev = sharon;       // Step 4
  
    print_list(tom);
  
    //Remove harry
    harry->prev->next = harry->next; // Step 1
    harry->next->prev = harry->prev; // Step 2
    delete harry;
  
    print_list(tom);

    return 0;
}