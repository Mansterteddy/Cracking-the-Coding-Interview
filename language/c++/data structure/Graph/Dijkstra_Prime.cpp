#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <stdexcept>
#include "Graph.h"
#include "Set_Functions.h"

using namespace std;

/** Dijkstra's Sortest Path algorithm
    @param graph The weighted graph to be searched
    @param start The start vertes
    @param pred Output array to contain the predicessors
    in the shortest path
    @param dist Output array to contain the distance
    in the shortest path
*/
void dijkstras_algorithm(const Graph& graph,
			int start,
			vector<int>& pred,
			vector<double>& dist) {
  int numV = graph.get_num_v();
  // Use a set to represent V-S
  set<int> v_minus_s;
  // Initialize V-S.
  for (int i = 0; i < numV; i++) {
    if (i != start) {
      v_minus_s.insert(i);
    }
  }
  // Initialize pred and dist
  for (set<int>::iterator itr = v_minus_s.begin();
       itr != v_minus_s.end(); ++itr) {
    pred[*itr] = start;
    dist[*itr] = graph.get_edge(start, *itr).get_weight();
  }  
  // Main loop
  while (!v_minus_s.empty()) {
    // Find the value u in V-S with the smallest dist[u]
    double minDist = numeric_limits<double>::infinity();
    int u = -1;
    for (set<int>::iterator itr = v_minus_s.begin();
	 itr != v_minus_s.end(); ++itr) {
      int v = *itr;
      if (dist[v] < minDist) {
	minDist = dist[v];
	u = v;
      }
    }
    // Remove u from v_minus_s
    v_minus_s.erase(u);
// Update the distances
for (Graph::iterator itr = graph.begin(u);
     itr != graph.end(u); ++itr) {
  Edge edge = *itr;
  int v = edge.get_dest();
  if (contains(v_minus_s, v)) {
    double weight = edge.get_weight();
    if (dist[u] + weight < dist[v]) {
      dist[v] = dist[u] + weight;
      pred[v] = u;
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
