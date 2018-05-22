/** Program to Test the Huffman Tree */

#include "Huffman_Tree.h"
#include <fstream>
#include <iostream>
#include <vector>
using std::cerr;
using std::ifstream;
using std::ofstream;
using std::ios_base;
using std::vector;

int main(int argc, char* argv[]) {

  if (argc < 4) {
    cerr << "Usage: Test_Huffman_Tree <input file> <coded file> "
	 << "<decoded file>\n";
    return 1;
  }

  ifstream input_file(argv[1], ios_base::binary);
  if (!input_file) {
    cerr << "Unable to open " << argv[1] << " for input\n";
    return 1;
  }

  Huffman_Tree huffman_tree;
  vector<Huff_Data> weights = 
    Huffman_Tree::build_frequency_table(input_file);
  huffman_tree.build_tree(weights);
  huffman_tree.print_code(std::cout);
  huffman_tree.build_code();
  
  ofstream coded_file(argv[2], ios_base::binary);
  if (!coded_file) {
    cerr << "Unable to open " << argv[1] << " for output\n";
    return 1;
  }

  // Rewind the input
  input_file.close();
  ifstream input_file2(argv[1], ios_base::binary);
  
  huffman_tree.encode(input_file2, coded_file);

  input_file.close();
  coded_file.close();

  ifstream coded_input(argv[2], ios_base::binary);
  if (!coded_input) {
    cerr << "Unable to open " << argv[2] << " for input\n";
    return 1;
  }

  ofstream decoded_output(argv[3], ios_base::binary);
  if (!decoded_output) {
    cerr << "Unable to opern " << argv[3] << " for output\n";
    return 1;
  }

  huffman_tree.decode(coded_input, decoded_output);

  decoded_output.close();

  return 0;

}
