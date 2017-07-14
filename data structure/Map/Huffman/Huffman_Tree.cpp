/** Implementation of Huffman_Tree class */

#include "Huffman_Tree.h"
#ifdef USEKW
#include "Priority_Queue.h"
using KW::priority_queue;
#else
#include <queue>
using std::priority_queue;
#endif
#include <istream>
#include <ostream>
using std::map;
using std::vector;
using std::istream;
using std::ostream;
using std::string;

void Huffman_Tree::build_tree(const vector<Huff_Data>& symbols) {
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

string Huffman_Tree::decode(const string& coded_message) {
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

vector<Huff_Data> Huffman_Tree::build_frequency_table(istream& in) {
  map<char, int> frequencies;
  char c;
  while (in.get(c)) {
    frequencies[c]++;
  }
  vector<Huff_Data> result;
  for (map<char, int>::iterator itr = frequencies.begin();
       itr != frequencies.end(); ++itr) {
    result.push_back(Huff_Data(itr->second, itr->first));
  }
  return result;
}
/** Recursive function to perform breadth-first traversal
    of the Huffman tree and build the code table.
    @param tree The current tree root
    @param code The code string so far
*/
void Huffman_Tree::build_code(const Binary_Tree<Huff_Data>& tree, 
                              const Bit_String& code) {
  if (tree.is_leaf()) {
    Huff_Data datum = tree.get_data();
    code_map[datum.symbol] = code;
  } else {
    // Append 0 to code so far and traverse left
    Bit_String left_code(code);
    left_code.append(false);
    build_code(tree.get_left_subtree(), left_code);
    // Append 1 to code so far and traverse right
    Bit_String right_code(code);
    right_code.append(true);
    build_code(tree.get_right_subtree(), right_code);
  }
}
/** Encodes a data file by writing it in compressed bit string form.
    @param in The input stream
    @param out The output stream
*/
void Huffman_Tree::encode(std::istream& in, std::ostream& out) {
  Bit_String result;
  char next_char;
  while (in.get(next_char)) {
    result += code_map[next_char];
  }
  result.write(out);
}
/** Decodes a data file by reading the Bit_Stream and writing the
    decoded file.
    @param in The input stream containing the Bit_Stream
    @param out The decoded file result
*/
void Huffman_Tree::decode(istream& in, ostream& out) {
  Bit_String message = Bit_String::read(in);
  Binary_Tree<Huff_Data> current_tree = huff_tree;
  for (size_t i = 0; i < message.size(); i++) {
    if (message[i]) {
      current_tree = current_tree.get_right_subtree();
    } else {
      current_tree = current_tree.get_left_subtree();
    }
    if (current_tree.is_leaf()) {
      Huff_Data the_data = current_tree.get_data();
      out << the_data.symbol;
      current_tree = huff_tree;
    }
  }
}
  

    
