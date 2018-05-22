/** Implementation of the List_Graph Class */

#include "List_Graph.h"
#include <algorithm>
#include <limits>
#include <cstddef>
using std::numeric_limits;


// Consructors
/** Constructs a graph with the specified number of
    vertices and directionality.
    @param n The number of vertices
    @param d The directionality flag
*/
List_Graph::List_Graph(int n, bool d) : Graph(n, d) {
  edges.resize(n);
}

// Implementation of abstract methods
/** Insert a new edge into the graph.
    @param edge The new edge
*/
void List_Graph::insert(const Edge& edge) {
  edges[edge.get_source()].push_back(edge);
  if (!is_directed()) {
    edges[edge.get_dest()].push_back(Edge(edge.get_dest(), 
                                          edge.get_source(), 
                                          edge.get_weight()));
  }
}

/** Determines whether an edge exists.
    @param source The source vertex
    @param dest The destination vertex
    @return true if there is an edge from source to dest
*/
bool List_Graph::is_edge(int source, int dest) const {
  list<Edge>::const_iterator itr = find(edges[source].begin(),
                                        edges[source].end(),
                                        Edge(source, dest));
  return itr != edges[source].end();
}

/** Get the edge between two vertices. If an
    edge does not exist, an Edge with a weight
    of numeric_limits<double>::infinity() is returned.
    @param source The source vertex
    @param dest The destination vertex
    @return The edge between these two vertices
*/
Edge List_Graph::get_edge(int source, int dest) const {
  list<Edge>::const_iterator itr = find(edges[source].begin(),
                                        edges[source].end(),
                                        Edge(source, dest));
  if (itr != edges[source].end()) 
    return *itr;
  else
    return Edge(source, dest, numeric_limits<double>::infinity());
}
/** Return an iterator to the edges adjacent
    to a given vertex.
    @param source The source vertex
    @return An iterator positioned at the beginning
            of the vertices adjacent to source
*/
Graph::iterator List_Graph::begin(int source) const {
  return Graph::iterator(new iter_impl(edges[source].begin()));
}

/** Return an iterator that is one past the edges
    adjacent to a given vertex.
    @param source The source vertex
    @return An iterator positioned one past the
            edges adjacent to source
*/
Graph::iterator List_Graph::end(int source) const {
  return Graph::iterator(new iter_impl(edges[source].end()));
}
