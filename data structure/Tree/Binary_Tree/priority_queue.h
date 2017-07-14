#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <functional>

namespace KW {

  /** Priority queue based on a heap stored in a vector */
  template <typename Item_Type, typename Container = std::vector<Item_Type>,
    typename Compare = std::less<Item_Type> >
    class priority_queue {
      
      public:
      
        /** Construct an empty priority queue */
        priority_queue() {}
      
        /** Insert an item into the priority queue */
        void push(const Item_Type& item);

        /** Remove the smallest item */
        void pop();

        /** Return true if the priority queue is empty */
        bool empty() const {return the_data.empty();}
      
        /** Return the number of items in the priority queue */
        int size() const {return the_data.size();}
      
        /** Return a reference to the smallest item */
        const Item_Type& top() const {return the_data.front();}

        /** Return a copy of the container 
            Function used for testing
        */
        Container get_container() const {return the_data;}
      
      private:
      
        /** The vector to hold the data */
        Container the_data;

        /** The comparator function object */
        Compare comp;
      
    };

  // Implemention of member functions

  template<typename Item_Type, typename Container, typename Compare>
    void priority_queue<Item_Type, Container, Compare>::push(const Item_Type& item) {
    the_data.push_back(item);
    int child = size() - 1;
    int parent = (child - 1) / 2;
    // Reheap
    while (parent >= 0 
	   && comp(the_data[parent], the_data[child])) {
      std::swap(the_data[child], the_data[parent]);
      child = parent;
      parent = (child - 1) / 2;
    }
  }

  template<typename Item_Type, typename Container, typename Compare>
    void priority_queue<Item_Type, Container, Compare>::pop() {
    if (size() == 1) {
      the_data.pop_back();
      return;
    }
    std::swap(the_data[0], the_data[size() - 1]);
    the_data.pop_back();
    int parent = 0;
    while (true) {
      int left_child = 2 * parent + 1;
      if (left_child >= size())
	     break; // out of heap
      int right_child = left_child + 1;
      int max_child = left_child;
      if (right_child < size()
	         && comp(the_data[left_child], the_data[right_child]))
	     max_child = right_child;
      // assert: max_child is the index of the larger child
      if (comp(the_data[parent], the_data[max_child])) {
	     std::swap(the_data[max_child], the_data[parent]); 
	     parent = max_child;
    }
      else
	     break;
    }
  }
} // End namespace KW

#endif
