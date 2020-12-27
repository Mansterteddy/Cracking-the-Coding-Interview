#ifndef MATRIX_GRAPH_H_
#define MATRIX_GRAPH_H_

#include "Graph.h"

/** A Matrix_Graph is an implementation of the Graph
    abstract class that uses an array to represent the
    edges.
    @author Koffman and Wolfgang
*/
class Matrix_Graph : public Graph {

 public:

    // Consructors
    /** Construct a graph with the specified number of
        vertices and directionality
        @param n - The number of vertices
        @param d - The directionality flag
    */
    Matrix_Graph(int n, bool d);

    /** Destroy a Matrix_Graph */
    ~Matrix_Graph();

    // Implementation of abstract methods
    /** Insert a new edge into the graph
        @param edge - The new edge
    */
    void insert(const Edge& edge);

    /** Determine if an edge exists
        @param source - The source vertix
        @param dest - The destination vertix
        @return true if there is an edge from u to v
    */
    bool is_edge(int source, int dest) const;

    /** Get the edge between two vertices. If an
        edge does not exist, an Edge with a weight
        of POSITIVE_INFINITY is returned.
        @param source - The source
        @param dest - The destination
        @return the edge between these two vertices
     */
    Edge get_edge(int source, int dest) const;

    /** Return an iterator to the edges connected
        to a given vertix.
        @param source - The source vertix
        @return an EdgeIterator to the vertices
        contcted to source
    */
    iterator begin(int source) const;

    /** Return an iterator that is one past the
	edges connected to a given vertix.
    */
    iterator end(int source) const;

 private:

    /** Method to set the value of an edge
        @param source - The source vertix
        @param dest - The destination vertix
        @param wt - The weight
    */
    void setEdgeValue(int source, int dest, double wt);

    /** Method to get the value of an edge
     *  @param source - The source vertix
     *  @param dest - The destination vertix
     *  @return The weight of this edge or
     *  POSITIVE_INFINITY if no edge exists
     */
    double getEdgeValue(int source, int dest) const; 

    // Data field
    /** The two dimensional array to represen an edge */
    double** edges;

 public:

    // Iter class
    /** An iterator to the edges.  
     */
    class iter_impl : public Graph::iter_impl {
    private:
      // Constructor
      /** Construct an EdgeIterator for a given vertix
	  @param p The pointer to the graph that owns this iterator
	  @param s The source vertix
	  @param i The initial index value
       */
      iter_impl(const Matrix_Graph* p, int s, int i) : parent(p), 
	source(s), index(i) {
            advanceIndex();
      }

    public:

      /** Return the current edge */
      Edge operator*();

      /** Advance to the next edge */
      Graph::iter_impl& operator++();

      /** Determine if two iter_impl are equal */
      bool operator==(const Graph::iter_impl&) const;
     
      /** Make a deep copy of this iter_impl */
      Graph::iter_impl* clone();

    private:
      /** Advance the index to the next edge */
      void advanceIndex();

      // Data fields
      
      /** A pointer to the graph */
      const Matrix_Graph* parent;
      /** The source vertix for this iterator */
      int source;
      /** The current index for this iterator */
      int index;

      friend class Matrix_Graph;

    }; // end iter_impl

}; // end Matrix_Graph

#endif
