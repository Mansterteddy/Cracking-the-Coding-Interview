#ifndef INSERTIONSORT_H_
#define INSERTIONSORT_H_

#include <algorithm>

namespace KW {

/** Sort data in the specified range using insertion sort.
    @param RI An iterator that meets the
           random-access iterator requirements
    @param first An iterator that references
           the first element in the sequence to be sorted
    @param last An iterator iterator that references
           1 past the end of the sequence
*/      
template<typename RI>
  void insertion_sort(RI first, RI last) {
  for (RI next_pos = first + 1; next_pos != last; ++next_pos) {
    // Invariant: elements at position first through 
    //            next_pos - 1 are sorted.
    // Insert element at position next_pos in the sorted subarray.
    insert(first, next_pos);
  }
}

/** Insert the element at position next_pos in the sorted subarray 
    using swap.
    pre:  elements at position 0 through next_pos � 1 are sorted.
    post: elements at position 0 through next_pos are sorted.
    @param RI An iterator that meets the
           random-access iterator requirements
    @param first An iterator that references
           the first element in the sequence to be sorted
    @param next_pos An iterator that references
           the element to insert
*/
template<typename RI>
  void insert(RI first, RI next_pos) {
  while (next_pos != first && *next_pos < *(next_pos - 1)) {
    std::iter_swap(next_pos, next_pos - 1); //  Exchange pair of values
    --next_pos;  // Check next smaller element
  } 
}

} // End namespace KW

#endif
