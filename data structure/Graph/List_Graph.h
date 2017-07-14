#ifndef LIST_GRAPH_H_
#define LIST_GRAPH_H_

#include "Graph.h"
#include <list>
#include <vector>
using std::list;
using std::vector;

/** A List_Graph is an implementation of the Graph
    abstract class that uses a vector of lists 
    to contain the edges adjacent to a given vertex.
*/
class List_Graph : public Graph {

  public:

    // Constructors
    /** Constructs a graph with the specified number of
        vertices and directionality.
        @param n The number of vertices
        @param d The directionality flag
    */
    List_Graph(int n, bool d);

    // Declaration of abstract functions.
    /** Insert a new edge into the graph.
        @param edge The new edge
    */
    void insert(const Edge& edge);

    /** Determines whether an edge exists.
        @param source The source vertex
        @param dest The destination vertex
        @return true if there is an edge from source to dest
    */
    bool is_edge(int source, int dest) const;

    /** Get the edge between two vertices. If an
        edge does not exist, an Edge with a weight
        of numeric_limits<double>::infinity() is returned.
        @param source The source vertex
        @param dest The destination vertex
        @return The edge between these two vertices
     */
    Edge get_edge(int source, int dest) const;

    /** Return an iterator to the edges adjacent
        to a given vertex.
        @param source The source vertex
        @return An iterator positioned at the beginning
                of the vertices adjacent to source
    */
    iterator begin(int source) const;

    /** Return an iterator that is one past the
        edges adjacent to a given vertex.
        @param source The source vertex
        @return An iterator positioned one past the
                edges adjacent to source
    */
    iterator end(int source) const;

  private:

    // Data field
    /** The vector of lists of edges */
    std::vector<std::list<Edge> > edges;
    
  public:

    // iter_impl class
/** Implementation class for an iterator to the edges. 
*/
class iter_impl : public Graph::iter_impl {

  private:
  // Constructor
  /** Construct an iter_impl for a given vertex.
      @param start An iterator to the list of edges adjacent
                   to the desired vertex
  */
  iter_impl(std::list<Edge>::const_iterator start) : current(start) {}

  public:
  /** Return the current edge */
  Edge operator*() {
    return *current;
  }

  /** Advance to the next edge */
  Graph::iter_impl& operator++() {
    ++current;
    return *this;
  }

  /** Determine whether two iter_impl objects are equal */
  bool operator==(const Graph::iter_impl& other) const {
    const iter_impl* ptr_other = 
     dynamic_cast<const iter_impl*>(&other);
    if (ptr_other == NULL) return false;
    return current == ptr_other->current;
  }
 
  /** Make a deep copy of this iter_impl */
  Graph::iter_impl* clone() {
    return new iter_impl(current);
  }

  private:
  // Data fields
  
  /** Iterator to the list of edges */
  std::list<Edge>::const_iterator current;
  friend class List_Graph;

}; // End iter_impl

}; // end List_Graph

#endif
