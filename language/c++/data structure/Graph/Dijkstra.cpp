#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <stdexcept>
#include "Graph.h"

using namespace std;

/** Dijkstra's Shortest-Path algorithm.
    @param graph The weighted graph to be searched
    @param start The start vertex
    @param pred Output vector to contain the predecessors
           in the shortest path
    @param dist Output vector to contain the distance
           in the shortest path
*/
void dijkstras_algorithm(const Graph& graph,
                         int start,
                         vector<int>& pred,
                         vector<double>& dist) {
  int num_v = graph.get_num_v();
  // Use a set to represent V - S
  set<int> v_minus_s;
  // Initialize V - S.
  for (int i = 0; i < num_v; i++) {
    if (i != start) {
      v_minus_s.insert(i);
    }
  }
  // Initialize pred and dist
  for (set<int>::iterator itr = v_minus_s.begin();
       itr != v_minus_s.end(); ++itr) {
    pred[*itr] = start;
    dist[*itr] = graph.get_edge(start, *itr).get_weight();
#ifdef TRACE
    cout << *itr << "\t" << start << "\t" << dist[*itr] << endl;
#endif
  }  

  // Main loop
  while (!v_minus_s.empty()) {
    // Find the value u in V - S with the smallest dist[u].
    double min_dist = numeric_limits<double>::infinity();
    int u = -1;
    for (set<int>::iterator itr = v_minus_s.begin();
         itr != v_minus_s.end(); ++itr) {
      int v = *itr;
      if (dist[v] < min_dist) {
        min_dist = dist[v];
        u = v;
      }
    }
#ifdef TRACE
    cout << "u == " << u << endl;
#endif
    // Remove u from v_minus_s
    v_minus_s.erase(u);
    // Update the distances
    for (set<int>::iterator itr = v_minus_s.begin();
         itr != v_minus_s.end(); ++itr) {
      int v = *itr;
      if (graph.is_edge(u, v)) {
        double weight = graph.get_edge(u, v).get_weight();
        if (dist[u] + weight < dist[v]) {
          dist[v] = dist[u] + weight;
          pred[v] = u;
#ifdef TRACE
	  cout << "dist[" << v << "] = " << dist[v] << endl;
	  cout << "pred[" << v << "] = " << pred[v] << endl;
#endif
        }
      }
    }
  }
}
/** Main program to demonstrate algorithm.
    @param argc Number of command line arguments
    @param argv Command line arguments 
    @pre argv[1] contains the name of the file that 
        defines the graph.
    @pre argv[2] specifies the type of graph
*/
int main(int argc, char* argv[]) {
  if (argc < 3) {
    cerr << "Usage Dijkstra  <input file> <graph type>\n";
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
  int numV = graph->get_num_v();  // Get the number of vertices
  // Create the predicessor array
  vector<int> pred(numV);
  // Create distance array
  vector<double> dist(numV);
  // Perform Dijskstra's algorithm
  dijkstras_algorithm(*graph, 0, pred, dist);
  // Output Results
  for (int i = 0; i < numV; i++) {
    cout << "dist[" << i << "]: " << dist[i] << endl;
  }
  for (int i = 1; i < numV; i++) {
    cout << i << ": ";
    int j = i;
    while (pred[j] != 0) {
      cout << pred[j] << " <- ";
      j = pred[j];
    }
    cout << pred[j] << endl;
  }
}
