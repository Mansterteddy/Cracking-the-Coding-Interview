#ifndef GRAPH_H_
#define GRAPH_H_

#include "Edge.h"
#include <iosfwd>

/** Abstract class to specify a Graph ADT. A graph is a set
    of vertices and a set of edges. Vertices are
    represented by integers from 0 to n - 1. Edges
    are ordered pairs of vertices.
*/
class Graph {

  public:

  // Forward declaration of iterator class
  class iterator;

  // Constructor
  /** Construct a graph.
      @param n The number of vertices
      @param d True if this is a directed graph
  */
  Graph(int n, bool d) : num_v(n), directed(d) {}

  // Virtual Destructor
  virtual ~Graph() {}
  
  // Accessors
  /** Return the number of vertices.
      @return The number of vertices
  */
  int get_num_v() const {return num_v;}
  
  /** Determine whether this is a directed graph.
      @return true if this is a directed graph
  */
  bool is_directed() const {return directed;}

  /** Insert a new edge into the graph.
      @param edge The new edge
  */
  virtual void insert(const Edge& edge) = 0;
  
  /** Determine whether an edge exists.
      @param source The source vertex
      @param dest The destination vertex
      @return true if there is an edge from source to dest
  */
  virtual bool is_edge(int source, int dest) const = 0;

  /** Get the edge between two vertices.
      @param source The source vertex
      @param dest The destination vertex
      @return The Edge between these two vertices or an Edge 
              with a weight of numeric_limits<double>::infinity()
              if there is no edge
  */
  virtual Edge get_edge(int source, int dest) const = 0;

  /** Return an iterator to the first edge adjacent
      to the specified vertex.
      @param source The source vertex
      @return An iterator to the edges
              adjacent to source
  */
  virtual iterator begin(int source) const = 0;

  /** Return an iterator one past the last edge adjacent
      to a specified vertex.
      @param source The source vertex
  */
  virtual iterator end(int source) const = 0;

  /** Load the edges of a graph from the data in an input file.
      The file should contain a series of lines, each line
      with two or three data values. The first is the source,
      the second is the destination, and the optional third
      is the weight.
      @param in The istream that is connected
                to the file that contains the data
  */
  void load_edges_from_file(std::istream& in);
  
  /** Factory function to create a graph and load the data from an input
      file. The first line of the input file should contain the number
      of vertices. The remaining lines should contain the edge data as
      described under load_edges_from_file.
      @param in The istream that is connected to the file that contains 
                the data
      @param is_directed true if this is a directed graph, false otherwise
      @param type The string "Matrix" if an adjacency matrix is to be
                  created, and the string "List" if an adjacency list
                  is to be created.
      @throws std::invalid_argument if type is neither "Matrix" nor "List"
   */
  static Graph* create_graph(std::istream& in, bool is_directed, 
                             const std::string& type);

  // Definition of nested classes iter_impl and iterator
/** The iter_impl class defines abstract functions
    to implement the iterator operations.
*/
class iter_impl {
  public:
  virtual Edge operator*() = 0;
  virtual iter_impl& operator++() = 0;
  virtual bool operator==(const iter_impl&) const = 0;
  virtual iter_impl* clone() = 0;
  virtual ~iter_impl() {}
};
/** An iterator provides sequential access to the edges
    adjacent to a given vertex.
*/ 
class iterator {
  
  public:
  Edge operator*() {
    return ptr_to_impl->operator*();
  }

  iterator& operator++() {
    ++(*ptr_to_impl);
    return *this;
  }

  iterator operator++(int) {
    iterator temp(*this);
    ++(*ptr_to_impl);
    return temp;
  }

  bool operator==(const iterator& other) const {
    return *ptr_to_impl == *other.ptr_to_impl;
  }

  bool operator!=(const iterator& other) const {
    return !((*this) == other);
  }

  ~iterator() {delete ptr_to_impl;}

  iterator(const iterator& other) : 
    ptr_to_impl(other.ptr_to_impl->clone()) {}

  /** Constructor.
      @param p_graph Pointer to the graph being iterated over
      @param p_impl Pointer to iterator implementation
  */
  iterator(iter_impl* p_impl) : ptr_to_impl(p_impl) {}

  private:
  /** Pointer to the implementation */
  iter_impl* ptr_to_impl;
}; // End iterator


  protected:

  // Data fields
  /** The number of vertices */
  int num_v;
  /** Flag to indicate whether this is a directed graph */
  bool directed;

}; // End class Graph

#endif
