#ifndef TWO_THREE_FOUR_TREE_H_
#define TWO_THREE_FOUR_TREE_H_

#include <sstream>
#include <string>

/** An implementation of the 2-3-4 tree. A 2-3-4 tree is a
*   search tree in which each node contains either one, two,
*   or three data  items and (other than leaves) two, three
*   or four children.  The tree is always balanced in that all
*   leaves are on the same level, i.e., the length of the path
*   from the root to a leaf is constant.  This data structure
*   is a special case of the B-tree, and is the basis for the
*   Red-Black tree.
*   @author Koffman and Wolfgang
*/
template<typename Item_Type>
  class Two_Three_Four_Tree {

  // Inner Class
  /** A Node represents a node in a 2-3-4 tree. CAP represents
      the maxumum number of children. For a 2-3-4 tree CAP is 4.
      This class has no functions; it is merely a container of 
      private data.
  */
  template<size_t CAP>
    struct Node {
      
      /** The number of data items in this node */
      size_t size;

      /** The information */
      Item_Type data[CAP - 1];

      /** The links to the children. child[i] refers to
          the subtree of children < data[i] for i < size
          and to the subtree of children > data[size - 1]
          for i == size. */
      Node* child[CAP];

      Node() {
        for (size_t i = 0; i < CAP; i++) {
          if (i < CAP - 1)
            data[i] = Item_Type();
          child[i] = NULL;
        }
      }
  };

  // Data Fields
  /** The reference to the root. */
  Node<4>* root;

  public:
  /** Create an empty Two_Three_Four_Tree */
  Two_Three_Four_Tree() : root(NULL) {}
/** Insert an object into the tree.
    @param obj The object to be inserted
    @return true if the item was inserted
*/
bool insert(const Item_Type& item) {
  if (root == NULL) {
    root = new Node<4>;
    root->data[0] = item;
    root->size = 1;
    return true;
  }
if (root->size == 3) {
  Item_Type new_parent;
  Node<4>* new_child;
  split_node(root, new_parent, new_child);
  Node<4>* new_root = new Node<4>;
  new_root->data[0] = new_parent;
  new_root->child[0] = root;
  new_root->child[1] = new_child;
  new_root->size = 1;
}
  return insert(root, item);
}
/** Recursive function to insert an object into the tree.
    @param local_root The local root
    @param item The item to be inserted
    @return true if the item was inserted,
            false if the item is already in the tree
*/
bool insert(Node<4>* local_root, const Item_Type& item) {
  size_t index = 0;
  while (index < local_root->size 
         && local_root->data[index] < item) {
    index++;
  }
  // index == local_root->size or item <= local_root.data[index]
if (index != local_root->size 
    && !(item < local_root->data[index])) {
  // Item is already in the tree.
  return false;
}
if (local_root->child[index] == NULL) {
  insert_into_node(local_root, index, item, NULL);
  return true;
}
else if (local_root->child[index]->size < 3) {
  return insert(local_root->child[index], item);
}
else {
  Item_Type new_parent;
  Node<4>* new_child;
  split_node(local_root->child[index], new_parent, new_child);
  insert_into_node(local_root, index,
                   new_parent, new_child);
    if (item < local_root->data[index]) {
      return insert(local_root->child[index], item);
    } else if (local_root->data[index] < item) {
      return insert(local_root->child[index + 1], item);
    } else {
      return false;
    }
  }
}
  /** Function to split a 2-3-4 node
      @param node The node to be split
      @param new_parent The middle data item 
      @param new_child The new right child of the middle
   */
  void split_node(Node<4>* node, Item_Type& new_parent,
                          Node<4>*& new_child) {
    new_child = new Node<4>;
    new_parent = node->data[1];
    new_child->size = 1;
    new_child->data[0] = node->data[2];
    new_child->child[0] = node->child[2];
    new_child->child[1] = node->child[3];
    node->size = 1;
}

  /** Method to insert a new value into a node.
      Pre: node->data[index - 1] < item < node->data[index]
      and node->size < 3
      Post: node->data[index] = item and old values are
      moved right one.
      @param node The node to insert the value
      @param index the index where the inserted item
      is to be placed
      @param item The value to be inserted
      @param child The right child of the value
   */
void insert_into_node(Node<4>* node, size_t index,
                      const Item_Type& item, Node<4>* child) {
  for (size_t i = node->size; i > index; i--) {
    node->data[i] = node->data[i - 1];
    node->child[i + 1] = node->child[i];
  }
  node->data[index] = item;
  node->child[index + 1] = child;
  node->size++;
}

};

#endif
