#ifndef RBNODE_H_
#define RBNODE_H_
#include <sstream>

/** A node for a Red-Black Tree. */
template<typename Item_Type>
  struct RBNode : public BTNode<Item_Type> {

  // Additional Data Field
  bool is_red;

  // Constructor
  RBNode(const Item_Type& the_data, BTNode<Item_Type>* left_val = NULL,
         BTNode<Item_Type>* right_val = NULL) : 
    BTNode<Item_Type>(the_data, left_val, right_val), is_red(true) {}

  // Destructor (to avoid warning message)
  virtual ~RBNode() {}

  // to_string
  virtual std::string to_string() const {
    std::ostringstream os;
    if (is_red)
      os << "   red: " << this->data;
    else
      os << " black: " << this->data;
    return os.str();
  }
}; // End RBNode

#endif
