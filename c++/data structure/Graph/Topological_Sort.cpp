#include <iostream>
#include <fstream>
#include <vector>
#include "Graph.h"
using namespace std;

void depth_first_search(const Graph&,
                        vector<int>&, vector<int>&,
                        vector<int>&);

/** This program outputs the topological sort of a directed graph
    that contains no cycles.
    pre: argv[1] will contain the file name that contains the graph.
    pre: argv[2] will contain the type of graph representation.
    @param argc The count of command line arguments
    @param argv The command line arguments
*/
int main(int argc, char* argv[]) {
  if (argc < 3) {
    cerr << "Usage Topological_Sort <input> <graph type>\n";
    return 1;
  }
  ifstream in(argv[1]);
  if (!in) {
    cerr << "Unable to open " << argv[1] << " for input\n";
    return 1;
  }
  Graph* the_graph = Graph::create_graph(in, true, argv[2]);
  // Perform the depth-first search
  vector<int> parent;
  vector<int> discovery_order;
  vector<int> finish_order;
  depth_first_search(*the_graph, parent, discovery_order, 
                     finish_order); 
  cout << "The Topological Sort is\n";
  for (int i = the_graph->get_num_v() - 1; i >= 0; i--)
    cout << finish_order[i] << endl;
  return 0;
}
