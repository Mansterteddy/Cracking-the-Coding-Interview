#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include "Graph.h"
#include "Set_Functions.h"

using namespace std;

/** Comparator function class to compare Edge weights. */
struct Compare_Edges {
  typedef Edge value_type;
  bool operator()(const Edge& left, const Edge& right) {
    return left.get_weight() > right.get_weight();
  }
};

/** Prim's Minimum Spanning Tree algorithm.
    @param graph The weighted graph to be searched
    @param start The start vertex
    @return A vector of edges that forms the MST
*/
vector<Edge> prims_algorithm(const Graph& graph,
                             int start) {
  vector<Edge> result;
  int num_v = graph.get_num_v();
  // Use a set to represent V - S
  set<int> v_minus_s;
  // Declare the priority queue
  priority_queue<Edge, vector<Edge>, Compare_Edges> pQ;
  // Initialize V - S.
  for (int i = 0; i < num_v; i++) {
    if (i != start) {
      v_minus_s.insert(i);
    }
  }
  int current = start;
  // Main loop
  while (!v_minus_s.empty()) {
#ifdef TRACE
    cout << "V - S " << v_minus_s << endl;
#endif
    // Update priority queue
    Graph::iterator iter = graph.begin(current);
    while (iter != graph.end(current)) {
      Edge edge = *iter++;
      int dest = edge.get_dest();
      if (contains(v_minus_s, dest)) {
        pQ.push(edge);
#ifdef TRACE
	cout << "Edge added to priority queue " << edge << endl;
#endif
      }
    }
    // Find the shortest edge whose source is in S and 
    // destination is in V - S.
    int dest;
    Edge edge;
    do {
      edge = pQ.top();
      pQ.pop();
      dest = edge.get_dest();
    } while(!contains(v_minus_s, dest));
#ifdef TRACE
    cout << "Shortest edge from S to V - S " << edge << endl;
#endif
    // Take dest out of v_minus_s
    v_minus_s.erase(dest);
    // Add edge to result
    result.push_back(edge);
    // Make this the current vertex
    current = dest;
  }
  return result;
}
/** Main program.
    @param args Command line. 
    @pre arg[0] contains the name of the file that 
    defines the graph.
*/
int main(int argc, char* argv[]) {
    if (argc < 3) {
    cerr << "Usage Prim  <input file> <graph type>\n";
    return 1;
  }
  ifstream in(argv[1]);
  if (!in) {
    cerr << "Unable to open " << argv[1] << " for input\n";
    return 1;
  }
  Graph* graph;
  try {
    graph = Graph::create_graph(in, false, argv[2]);
  } catch (invalid_argument& ex) {
    cerr << ex.what() << endl;
    cerr << "Valid graph types are \"List\" and \"Matrix\"\n";
    return 1;
  }
  // Perform Prim's algorithm
  vector<Edge> mst = prims_algorithm(*graph, 0);
  // Output Results
  for (size_t i = 0; i < mst.size(); i++) {
    cout << mst[i] << endl;
  }
}
