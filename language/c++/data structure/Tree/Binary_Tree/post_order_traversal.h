#ifndef POST_ORDER_TRAVERSAL_H
#define POST_ORDER_TRAVERSAL_H

#include "Binary_Tree.h"
#include <ostream>

template<typename Item_Type>
void post_order_traversal(const Binary_Tree<Item_Type>& the_tree, 
			 std::ostream& out, int level)
{
  if (the_tree.is_null()) 
  { 
    for (int i = 0; i < level; i++)
      out << "  ";
    out << "null\n";
  }
  else 
  {
    post_order_traversal(the_tree.get_left_subtree(), out, level + 1);
    post_order_traversal(the_tree.get_right_subtree(), out, level + 1);
    for (int i = 0; i < level; i++)
      out << "  ";
    out << the_tree.get_data() << std::endl;
  }
}

#endif
