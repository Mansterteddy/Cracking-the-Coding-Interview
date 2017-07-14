#include <vector>
#include <queue>
#include "Graph.h"
using namespace std;

/** Perform a breadth-first search of a graph.
    The vector p will contain the predecessor of each
    vertex in the breadth-first search tree.
    @param graph The graph to be searched
    @param start The start vertex
    @return The vector of parents
*/
vector<int> breadth_first_search(const Graph& graph, int start) {
  int num_v = graph.get_num_v();
  queue<int> the_queue;
  vector<int> parent(num_v, -1);
  vector<bool> identified(num_v, false);
  identified[start] = true;
  the_queue.push(start);
  /* While the queue is not empty */
  while (!the_queue.empty()) {
    /* Take a vertex, current, out of the queue 
       (Begin visiting current).*/
    int current = the_queue.front();
    the_queue.pop();
    /* For all vertices, neighbor, adjacent to current */
    Graph::iterator itr = graph.begin(current);
    while (itr != graph.end(current)) {
      Edge edge = *itr;
      int neighbor = edge.get_dest();
      /* If neighbor has not been identified */
      if (!identified[neighbor]) {
        /* Mark it identified */ 
        identified[neighbor] = true;
        /* Place it into the queue */
        the_queue.push(neighbor);
        /* Insert the edge (current, neighbor) 
           into the tree */
        parent[neighbor] = current;
      }
      ++itr;
    }
    // Finished visiting current.
  }
  return parent;
}

