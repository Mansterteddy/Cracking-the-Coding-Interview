#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <vector>
#include <string>
#include <ostream>
#include "Binary_Tree.h"

/** A dataum in the Huffman_Tree */
struct Huff_Data
{
  //Data Fields
  /** The weight or probability assigned to this HuffData*/
  double weight;
  /** The alphabet symbol if this is a leaf */
  char symbol;
  // Constructor
  Huff_Data(double w, char c) : weight(w), symbol(c) {}
};

// Ostream operator for Huff_Data
std::ostream& operator<<(std::ostream&, const Huff_Data&);

/** The comparator for Huff_Data */
struct Compare_Huffman_Trees
{
  bool operator()(const Binary_Tree<Huff_Data>& left_tree,
		  const Binary_Tree<Huff_Data>& right_tree) {
    double wLeft = left_tree.get_data().weight;
    double wRight = right_tree.get_data().weight;
    return wLeft > wRight;
  }
};


/** Class to represent and build a Huffman Tree */
class Huffman_Tree
{
 public:

  /** Builds the Huffman Tree using the given alphabet
      and weights.
      post:  huff_tree contains the Huffman Tree
  */
  void build_tree(const std::vector<Huff_Data>& symbols);

  /** Output the resulting code 
      @param out An ostream to write the output
  */
  void print_code(std::ostream& out) {
    print_code(out, "", huff_tree);
  }

  /** Function to decode a message that is input as a string of
      '1' and '0' characters
      @param coded_message The input message as a string of
      zeros and ones.
      @return The decoded message as a string
  */
  std::string decode(const std::string& coded_message) const;



 private:

  /** Outputs the resulting code 
      @param ostream An ostream to write the output
      @param code The code up to this node
      @param tree The current node in the tree
  */
  void print_code(std::ostream& out, std::string code,
		  const Binary_Tree<Huff_Data>& tree);
  // Data fields
  Binary_Tree<Huff_Data> huff_tree;
};

#endif
