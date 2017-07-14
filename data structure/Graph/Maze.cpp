#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include "Graph.h"

using namespace std;

vector<int> breadth_first_search(const Graph&, int);

/** Program to solve a maze represented as a graph.
    This program performs a breadth-first search of the graph
    to find the "shortest" path from the start vertex to the 
    end. It is assumed that the start vertex is 0, and the
    end vertex is num_v - 1.
    @param argc Count of command line arguments
    @param argv The command line arguments
    @pre argv[1] Contains the name of the input file
    @pre argv[2] Contains the type of graph
*/
int main(int argc, char* argv[]) {
  if (argc < 3) {
    cerr << "Usage Maze <input> <graph type>\n";
    return 1;
  }
  ifstream in(argv[1]);
  if (!in) {
    cerr << "Unable to open " << argv[1] << " for input\n";
    return 1;
  }
  Graph* the_maze = Graph::create_graph(in, false, "List");
  // Perform breadth-first search
  vector<int> parent = breadth_first_search(*the_maze, 0);
  // Construct the path
  stack<int> the_path;
  int v = the_maze->get_num_v() - 1;
  while (parent[v] != -1) {
    the_path.push(v);
    v = parent[v];
  }
  // Output the path
  cout << "The Shortest path is:\n";
  while (!the_path.empty()) {
    cout << the_path.top() << endl;
    the_path.pop();
  }
}
