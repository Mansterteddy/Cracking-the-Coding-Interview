/** Implementation of Huffman_Tree class */
#include <cctype>
#include "Huffman_Tree.h"
//#ifdef USEKW
//#include "priority_queue.h"
//using KW::priority_queue;
//#else
#include <queue>
using std::priority_queue;
//#endif
using std::ostream;
using std::string;
using std::toupper;
using std::tolower;

void Huffman_Tree::build_tree(const std::vector<Huff_Data>& symbols) {
   priority_queue<Binary_Tree<Huff_Data>, 
     std::vector<Binary_Tree<Huff_Data> >, Compare_Huffman_Trees> the_queue;
  for (size_t i = 0; i < symbols.size(); i++) {
    the_queue.push(Binary_Tree<Huff_Data>(symbols[i]));
  }
  // Build the tree
  while (the_queue.size() > 1) {
    Binary_Tree<Huff_Data> left = the_queue.top();
    the_queue.pop();
    Binary_Tree<Huff_Data> right = the_queue.top();
    the_queue.pop();
    double wl = left.get_data().weight;
    double wr = right.get_data().weight;
    Huff_Data sum(wl + wr, 0);
    Binary_Tree<Huff_Data> new_tree(sum, left, right);
    the_queue.push(new_tree);
  }
  huff_tree = the_queue.top();
  the_queue.pop();
}

void Huffman_Tree::print_code(ostream& out, string code,
			      const Binary_Tree<Huff_Data>& tree) {
  Huff_Data the_data = tree.get_data();
  if (the_data.symbol != 0) {
    if (the_data.symbol == ' ') {
      out << "space: " << code << '\n';
    } else {
      out << the_data.symbol << ": " << code << '\n';
    }
  } else {
    print_code(out, code + "0", tree.get_left_subtree());
    print_code(out, code + "1", tree.get_right_subtree());
  }
}

string Huffman_Tree::decode(const string& coded_message) const {
  string result;
  Binary_Tree<Huff_Data> current_tree = huff_tree;
  for (size_t i = 0; i < coded_message.length(); i++) {
    if (coded_message[i] == '1') {
      current_tree = current_tree.get_right_subtree();
    } else {
      current_tree = current_tree.get_left_subtree();
    }
    if (current_tree.is_leaf()) {
      Huff_Data the_data = current_tree.get_data();
      result += the_data.symbol;
      current_tree = huff_tree;
    }
  }
  return result;
}


ostream& operator<<(ostream& out, const Huff_Data& hd)
{
  out << "(" << hd.weight << ", ";
  if (hd.symbol == 0)
    out << "null";
  else
    out << hd.symbol;
  out << ")";
  return out;
}

