#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include "Bit_String.h"
#include "Binary_Tree.h"
#include <vector>
#include <string>
#include <iosfwd>
#include <map>

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
  std::string decode(const std::string& coded_message);

  /** Build the frequence table for the characters in the given
      input file.
  */
  static std::vector<Huff_Data> build_frequency_table(std::istream& in);

/** Starter function to build the code table.
    post: The table is built.
*/
void build_code() {
  code_map.clear();
  build_code(huff_tree, Bit_String());
}

  /** Encodes a data file by writing it in compressed bit string form.
      @param in The input stream
      @param out The output stream
  */
  void encode(std::istream& in, std::ostream& out);

  /** Decodes a data file by reading the Bit_Stream and writing the
      decoded file.
      @param in The input stream containing the Bit_Stream
      @param out The decoded file result
  */
  void decode(std::istream& in, std::ostream& out);

 private:

  /** Outputs the resulting code 
      @param ostream An ostream to write the output
      @param code The code up to this node
      @param tree The current node in the tree
  */
  void print_code(std::ostream& out, std::string code,
		  const Binary_Tree<Huff_Data>& tree);

  /** Recursive function to perform breadth-first traversal
      of the Huffman tree and build the code table
      @param tree The current tree root
      @param code The code string so far
  */
  void build_code(const Binary_Tree<Huff_Data>& tree, 
		  const Bit_String& code);

  // Data fields
  Binary_Tree<Huff_Data> huff_tree;

  std::map<char, Bit_String> code_map;

};

#endif
