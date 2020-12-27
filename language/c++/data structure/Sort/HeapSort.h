#ifndef HEAPSORT_H_
#define HEAPSORT_H_

#include <algorithm>

namespace KW {

  
  /** Sort data in the specified range using heapsort.
      @param RI An iterator that meets the
      random-access iterator requirements
      @param first A random access iterator that references
      the first element in the sequence to be sorted
      @param last A random-access iterator that references
      1 past the end of the sequence
  */
  template<typename RI>
    void heap_sort(RI first, RI last) {
    build_heap(first, last);
    shrink_heap(first, last);
  }
  
  /** build_heap transforms the sequence into a heap.
      @param RI An iterator that meets the
      random-access iterator requirements
      @param first A random-access iterator that references
      the first element in the sequence to be sorted
      @param last A random-access iterator that references
      1 past the end of the sequence
  */
  template<typename RI>
    void build_heap(RI first, RI last) {
    int n = 1;
    // Invariant: table[first] through table[first + n - 1] is a heap.
    while (n < (last - first)) {
      ++n;  // Add a new item to the heap and reheap.
      RI child = first + n - 1;
      RI parent = first + (child - first - 1) / 2;  // Find parent.
      while (parent >= first
	     && *parent < *child) {
	std::iter_swap(parent, child); // Exchange elements.
	child = parent;
	parent = first + (child - first - 1) / 2;
      }
    }
  }

  /** shrink_heap transforms a heap into a sorted sequence.
      @param RI An iterator that meets the
      random-access iterator requirements
      @param first A random-access iterator that references
      the first element in the sequence to be sorted
      @param last A random-access iterator that references
      1 past the end of the sequence
  */
  template<typename RI>
    void shrink_heap(RI first, RI last) {
    RI n = last;
    /* Invariant: table[first] through table[first + n - 1] forms a heap.
       table[first + n] through table[last - 1] is sorted.
    */
    while (n != first) {
      --n;
      std::iter_swap(first, n);
      RI parent = first;
      while (true) {
	RI left_child = first + 2 * (parent - first) + 1;
	if (left_child >= n) {
	  break;       // No more children.
	}
	RI right_child = left_child + 1;
	// Find the larger of the two children.
	RI max_child = left_child;
	if (right_child < n   // There is a right child.
	    && *left_child < *right_child) {
	  max_child = right_child;
	}
	// If the parent is smaller than the larger child,
	if (*parent < *max_child) {
	  // Swap the parent and child.
	  std::iter_swap(parent, max_child);
	  // Continue at the child level.
	  parent = max_child;
	} else {   // Heap property is restored.
	  break;  // Exit the loop.
	}
      }
    }
  }

  /** Sort data in the specified range using heapsort.
      @param the_array The array of data to be sorted
      @param size The size of the array
  */
  template<typename Item_Type>
    void heap_sort(Item_Type* the_array, size_t size) {
    build_heap(the_array, size);
    shrink_heap(the_array, size);
  }
  
  /** build_heap transforms the array into a heap
      @param the_array The array of data to be sorted
      @param size The size of the array
  */
  template<typename Item_Type>
    void build_heap(Item_Type* the_array, size_t size) {
    size_t n = 1;
    // Invariant: table[0] through table[n - 1] is a heap.
    while (n < size) {
      ++n;  // Add a new item to the heap and reheap.
      int child = n-1;
      int parent = (child - 1) / 2; // Find parent
      while (parent >= 0
	     && the_array[parent] < the_array[child]) {
	std::swap(the_array[parent], the_array[child]); // Exchange elements.
	child = parent;
	parent = (child - 1) / 2;
      }
    }
  }

  /** shrink_heap transforms a heap into a sorted sequence.
      @param the_array The array that is currently a heap
      @param size The size of the array
  */
  template<typename Item_Type>
    void shrink_heap(Item_Type* the_array, size_t size) {
    size_t n = size;
    /* Invariant: table[0] through table[n - 1] forms a heap.
       table[n] through table[size-1] is sorted.
    */
    while (n > 0) {
      --n;
      std::swap(the_array[0], the_array[n]);
      size_t parent = 0;
      while (true) {
	size_t left_child = 2 * parent + 1;
	if (left_child >= n) {
	  break;       // No more children.
	}
	size_t right_child = left_child + 1;
	// Find the larger of the two children.
	size_t max_child = left_child;
	if (right_child < n   // There is a right child.
	    && the_array[left_child] < the_array[right_child]) {
	  max_child = right_child;
	}
	// If the parent is smaller than the larger child,
	if (the_array[parent] < the_array[max_child]) {
	  // Swap the parent and child.
	  std::swap(the_array[parent], the_array[max_child]);
	  // Continue at the child level.
	  parent = max_child;
	} else {   // Heap property is restored.
	  break;  // Exit the loop.
	}
      }
    }
  }

} // End namespace KW

#endif
