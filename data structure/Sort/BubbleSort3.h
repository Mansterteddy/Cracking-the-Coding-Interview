#ifndef BUBBLE_SORT3_H
#define BUBBLE_SORT3_H
#include <algorithm>
namespace KW {
/** Sort first, middle, and last elements of sequence.
    @param RI An Iterator that meets the
           random-access iterator requirements
    @param first An iterator that references
           the first element in the sequence to be sorted
    @param last An iterator that references
           1 past the end of the sequence
*/
template<typename RI>
  RI bubble_sort3(RI first, RI last) {
  RI middle = first + (last - first) / 2;
  /* Perform bubble sort on table[first], table[middle],
     table[last - 1]. 
  */
  if (*middle < *first) {
    std::iter_swap(first, middle);
  }
  // Assert: table[first] <= table[middle].
  if (*(last - 1) < *middle) {
    std::iter_swap(middle, last - 1);
  }
  // Assert: table[last] is the largest value of the three.
  if (*middle < *first) {
    std::iter_swap(first, middle);
  }
  // Assert: table[first] <= table[middle] <= table[last - 1].
  return middle;
}
}

#endif

