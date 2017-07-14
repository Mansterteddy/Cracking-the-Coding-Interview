/** Implementation of the Matrix_Graph Class */

#include "Matrix_Graph.h"
#include <limits>
#include <cstddef>
using std::numeric_limits;


// Consructors
/** Construct a graph with the specified number of
    vertices and directionality
    @param n - The number of vertices
    @param d - The directionality flag
*/
Matrix_Graph::Matrix_Graph(int n, bool d) : 
  Graph(n, d), edges (new double*[n]) {
  if (d) {
    for (int i = 0; i < n; i++) {
      edges[i] = new double[n];
      for (int j = 0; j < n; j++) {
	edges[i][j] = 
	  numeric_limits<double>::infinity();
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      edges[i] = new double[i + 1];
      for (int j = 0; j < i + 1; ++j) {
	edges[i][j] = 
	  numeric_limits<double>::infinity();
      }
    }
  }
}

/** Destructor */
Matrix_Graph::~Matrix_Graph()
{
  for (int i = 0; i < num_v; i++) {
    delete[] edges[i];
  }
  delete[] edges;
}

// Implementation of abstract methods
/** Insert a new edge into the graph
    @param edge - The new edge
*/
void Matrix_Graph::insert(const Edge& edge) {
  setEdgeValue(edge.get_source(), edge.get_dest(), 
	       edge.get_weight());
}

/** Determine if an edge exists
    @param source - The source vertix
    @param dest - The destination vertix
    @return true if there is an edge from u to v
*/
bool Matrix_Graph::is_edge(int source, int dest) const {
  return numeric_limits<double>::infinity() 
    != getEdgeValue(source, dest);
}

/** Get the edge between two vertices. If an
    edge does not exist, an Edge with a weight
    of POSITIVE_INFINITY is returned.
    @param source - The source
    @param dest - The destination
    @return the edge between these two vertices
*/
Edge Matrix_Graph::get_edge(int source, int dest) const {
  return Edge(source, dest, 
	      getEdgeValue(source, dest));
}

/** Return an iterator to the edges connected
    to a given vertix.
    @param source - The source vertix
    @return an iterator positioned at the beginning
    of to the vertices
    contcted to source
*/
Graph::iterator Matrix_Graph::begin(int source) const {
  return Graph::iterator(new iter_impl(this, source, -1));
}

/** Return an iterator to one past the edges
    connected to a given vertix.
    @param source - The cource vertix
    @return an iterator positioned one past the
    edges adjacent to the specified source
*/
Graph::iterator Matrix_Graph::end(int source) const {
  return Graph::iterator(new iter_impl(this, source, num_v - 1));
}

/** Method to set the value of an edge
    @param source - The source vertix
    @param dest - The destination vertix
    @param wt - The weight
*/
void Matrix_Graph::setEdgeValue(int source, int dest, double wt) {
  if (is_directed() || source >= dest) {
    edges[source][dest] = wt;
  } else {
    edges[dest][source] = wt;
  }
}

/** Method to get the value of an edge
 *  @param source - The source vertix
 *  @param dest - The destination vertix
 *  @return The weight of this edge or
 *  POSITIVE_INFINITY if no edge exists
 */
double Matrix_Graph::getEdgeValue(int source, int dest) const {
  if (is_directed() || source >= dest) {
    return edges[source][dest];
  } else {
    return edges[dest][source];
  }
}

/** Make a deep copy of a iter_impl */
Graph::iter_impl* Matrix_Graph::iter_impl::clone() {
  return new iter_impl(parent, source, index - 1);
}

/** Return a copy of the current edge */
Edge Matrix_Graph::iter_impl::operator*() {
  return parent->get_edge(source, index);
}

/** Advance this iterator to the next edge */
Graph::iter_impl& Matrix_Graph::iter_impl::operator++() {
  advanceIndex();
  return *this;
}

/** Advance the index to the next edge */
void Matrix_Graph::iter_impl::advanceIndex() {
  do {
    index++;
  } while (index < parent->num_v
	   && numeric_limits<double>::infinity() 
	   == parent->getEdgeValue(source, index));
}

/** Determine if two iter_impl are the same */
bool Matrix_Graph::iter_impl::operator==(const Graph::iter_impl& other) const {
  const iter_impl* ptr_other = dynamic_cast<const iter_impl*>(&other);
  if (ptr_other == NULL) return false;
  return parent == ptr_other->parent
    && source == ptr_other->source
    && index == ptr_other->index;
}

