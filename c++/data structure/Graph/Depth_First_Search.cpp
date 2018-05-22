#include <vector>
#include "Graph.h"
using namespace std;

/** Perform a depth first search of a graph (recursive function).
    @param graph The graph to be searched
    @param current The current vertex being visited
    @param parent The parents in the depth-first search tree
    @param discovery_order The discovery order for each vertex
    @param finish_order The finish order for each vertex
    @param visited The vector that records whether a vertex has been 
                   visited
    @param discovery_index The index into the discovery_order vector
    @param finish_index The index into the finish_order vector
*/
void depth_first_search(const Graph& graph, int current,
                        vector<int>& parent,
                        vector<int>& discovery_order,
                        vector<int>& finish_order,
                        vector<bool>& visited,
                        int& discovery_index,
                        int& finish_index) {
  visited[current] = true;
  discovery_order[discovery_index++] = current;
  /* For each vertex adjacent to the current vertex. */
  for (Graph::iterator itr = graph.begin(current);
       itr != graph.end(current); ++itr) {
    int neighbor = (*itr).get_dest();
    // if neighbor has not been visited
    if (!visited[neighbor]) {
      /* Insert (current, neighbor) into the depth- 
         first search tree */
      parent[neighbor] = current;
      // Recursively apply the algorithm starting at neighbor.
      depth_first_search(graph, neighbor,
                         parent, discovery_order,
                         finish_order, visited,
                         discovery_index, finish_index);
    }
  }
  // Mark current finished 
  finish_order[finish_index++] = current;
}

/** Perform a depth-first search of a graph (starter function).
    @param graph The graph to be searched
    @param parent The parents in the depth-first search tree
    @param discovery_order The discovery order for each vertex
    @param finish_order The finish order for each vertex
*/
void depth_first_search(const Graph& graph,
                        vector<int>& parent,
                        vector<int>& discovery_order,
                        vector<int>& finish_order) {
  int num_v = graph.get_num_v();
  parent.clear();
  parent.resize(num_v, -1);
  discovery_order.clear();
  discovery_order.resize(num_v, -1);
  finish_order.clear();
  finish_order.resize(num_v, -1);
  vector<bool> visited(num_v, false);
  int discovery_index = 0;
  int finish_index = 0;
  for (int i = 0; i < num_v; i++) {
    if (!visited[i]) {
      depth_first_search(graph, i, parent,
                         discovery_order,
                         finish_order,
                         visited,
                         discovery_index,
                         finish_index);
    }
  }
}

