#include <iostream>
#include <fstream>
#include "Huffman_Tree.h"
using namespace std;

/** Program to test the Huffman_Tree class 
    @param argc Number of command line arguments
    @param argv Command Line arguments
    argv[1] Input file containing pairs of characters and their frequency
    argv[2] Input file containing a message to be decoded
*/
int main(int argc, char* argv[]) {
  if (argc < 3) {
    cerr << "Usage: Test_Huffman_Tree <weights><coded file><text file>\n";
    cerr << "<weights> is the file containing pairs of chars and their frequency\n";
    cerr << "<coded file> contains a coded message to be decoded\n";
    return 1;
  }
  ifstream data(argv[1]);
  if (!data) {
    cerr << "Unable to open " << argv[1] << " for input\n";
    return 1;
  }
  ifstream message(argv[2]);
  if (!message) {
    cerr << "Unable to open " << argv[2] << " for input\n";
  }
  vector<Huff_Data> symbols;
  double weight;
  string s;
  while (data >> s >> weight) {
    if (s != "space")
      symbols.push_back(Huff_Data(weight, s[0]));
    else
      symbols.push_back(Huff_Data(weight, ' '));
  }
  Huffman_Tree huff_tree;
  huff_tree.build_tree(symbols);
  huff_tree.print_code(cout);
  string the_message;
  message >> the_message;
  string decoded_message = huff_tree.decode(the_message);
  cout << decoded_message << endl;
  return 0;
}
