#ifndef INSERTIONSORT2_H_
#define INSERTIONSORT2_H_

#include <algorithm>

namespace KW {

/** Sort data in the specified range using insertion sort
    @param RandomAccessIterator An iterator that meets the
           random access iterator requirements
    @param first An interator that references
           the first element in the sequence to be sorted
    @param last An interator iterator that references
           one past the end of the sequence
*/	
template <typename RandomAccessIterator>
void insertion_sort2(RandomAccessIterator first, RandomAccessIterator last) {
    for (RandomAccessIterator next_pos = first+1; next_pos != last; ++next_pos) {
        // Invariant: elements at position first thru next_pos - 1 are sorted.
        // Insert element at position next_pos
        //    in the sorted subarray.
        insert2(first, next_pos);
    }
}

/** Insert the element at position next_pos in the sorted subarray using swap 
    @pre: elements at positon 0 thru next_pos - 1 are sorted.
    @post: elements at positon 0 thru next_pos are sorted.
    @param RandomAccessIterator An iterator that meets the
           random access iterator requirements
    @param first An interator that references
           the first element in the sequence to be sorted
    @param next_pos An interator that references
           the element to insert
*/
template<typename RI>
  void insert2(RI first, RI next_pos) {
  typename std::iterator_traits<RI>::value_type next_val 
      = *next_pos;  // next_val is element to insert.
  while (next_pos != first
         && next_val < *(next_pos - 1)) {
    *next_pos = *(next_pos - 1);
    --next_pos;  // Check next smaller element.
  }
  *next_pos = next_val;  // Store next_val where it belongs.
}
} // End namespace KW

#endif
