#ifndef MODIFIABLE_PRIORITY_QUEUE_H
#define MODIFIABLE_PRIORITY_QUEUE_H

#include <iostream>
#include <vector>
#include <functional>
#include <utility>

namespace KW {
  
  /** A modifiable priority queue based on a heap stored in a vector.
      Like the priority_queue, items are inserted in any order and 
      removed in priority order, with the largest (as defined by the
      Compare function) removed first. The insert function will 
      return a value known as a locator. The locator may be used 
      to replace a value in the priority queue.
  */
  template<typename Item_Type, typename Compare = std::less<Item_Type> >
    class Modifiable_Priority_Queue {
      
      public:
      
      /** Construct an empty priority queue */
      Modifiable_Priority_Queue() {}
      
      /** Insert an item into the priority queue. 
          @param item The item to be inserted
          @return A locator to the item
      */
      int insert(const Item_Type& item);
      
      /** Return a reference to the largest item */
      const Item_Type& top() const {return the_data.front();}
      
      /** Remove the largest item */
      void pop();
      
      /** Replace the item at the specified location.
          @param loc The locator value of the current item
          @param new_value The new value
      */
      void replace_item(int loc, const Item_Type& new_value);
      
      /** Return true if the priority queue is empty */
      bool empty() const {return the_data.empty();}
      
      /** Return the number of items in the priority queue */
      size_t size() const {return the_data.size();}
      
      private:
      
      // Typedef to make life easier
      typedef std::pair<int, Item_Type> Entry_Type;
      
      /** Function to swap entries and their corresponding locators */
      void swap(int a, int b) {
        // Swap the entries
        std::swap(the_data[a], the_data[b]);
        // Update the locator values
        locators[the_data[a].first] = a;
        locators[the_data[b].first] = b;
      }
      
      // Comparator for Entry_Types
      struct Compare_Entries {
        Compare value_comp;
        bool operator()(const Entry_Type& left,
                        const Entry_Type& right) {
          return value_comp(left.second, right.second);
        }
      };
      
      /** The vector to hold the data */
      std::vector<Entry_Type> the_data;
      
      /** The vector to hold the locators */
      std::vector<int> locators;
      
      /** The comparator function object */
      Compare_Entries comp;
      
      // For debugging
      public:
      void print_tables(const std::vector<int>& loc) {
        std::cout << "i\tloc\tlocators\tthe_data\n";
        for (size_t i = 0; i < loc.size(); i++) {
          std::cout << i << "\t" << loc[i]
                    << "\t" << locators[i]
                    << "\t" << the_data[i].first
                    << "\t" << the_data[i].second << std::endl;
        }
      }
    };
  
  // Implementation of member functions
  
  template<typename Item_Type, typename Compare>
    int Modifiable_Priority_Queue<Item_Type, Compare>::insert
      (const Item_Type& item) {
    Entry_Type the_pair(locators.size(), item);
    the_data.push_back(the_pair);
    locators.push_back(the_data.size() - 1);
    int child = size() - 1;
    int parent = (child - 1) / 2;
    // Reheap
    while (parent >= 0 
           && comp(the_data[parent], the_data[child])) {
      swap(child, parent);
      child = parent;
      parent = (child - 1) / 2;
    }
    return locators.size() - 1;
  }
  
  template<typename Item_Type, typename Compare>
    void Modifiable_Priority_Queue<Item_Type, Compare>::pop() {
    if (size() == 1) {
      the_data.pop_back();
      return;
    }
    swap(0, size() - 1);
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
        swap(max_child, parent);
        parent = max_child;
      }
      else
        break;
    }
  }
  
  /** Replace the item at the specified location.
      @param loc The locator value of the current item
      @param new_value The new value
  */
  template<typename Item_Type, typename Compare>
    void Modifiable_Priority_Queue<Item_Type, Compare>::
      replace_item(int loc, const Item_Type& new_value) {
    the_data[locators[loc]].second = new_value;
    // The new value should have a smaller value . . .
    int child = locators[loc];
    int parent = (child - 1) / 2; // Find child's parent.
    // Reheap
    while (parent >= 0 
           && comp(the_data[parent], the_data[child])) {
      swap(parent, child);
      child = parent;
      parent = (child - 1) / 2;
    }
    // ... however, it is not required, so let's check that direction too
    parent = child;
    while (true) {
      int left_child = 2 * parent + 1;
      if (left_child >= the_data.size()) {
        break; // Out of heap.
      }
      int right_child = left_child + 1;
      int max_child = left_child; // Assume left_child is larger.
      // See whether right_child is smaller.
      if (right_child < the_data.size()
          && comp(the_data[left_child],
                  the_data[right_child]) > 0) {
        max_child = right_child;
      }
      // assert: min_child is the index of the smaller child.
      // Move smaller child up heap if necessary.
      if (comp(the_data[parent],
               the_data[max_child]) > 0) {
        swap(parent, max_child);
        parent = max_child;
      }
      else { // Heap property is restored.
        break;
      }
    }
    // Heap property is now restored either way
  }
} // End namespace KW

#endif
