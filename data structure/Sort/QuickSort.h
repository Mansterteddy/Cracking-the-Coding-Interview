#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include <algorithm>



namespace KW {

/** Sort data in the specified range using quicksort.
    @param RI An iterator that meets the
           random-access iterator requirements
    @param first An iterator that references
           the first element in the sequence to be sorted
    @param last An iterator that references
           1 past the end of the sequence
*/
template<typename RI>
  void quick_sort(RI first, RI last) {
  if (last - first > 1) {  // There is data to be sorted.
    // Partition the table.
    RI pivot = partition(first, last);
    // Sort the left half.
    KW::quick_sort(first, pivot);

    // Sort the right half.
    KW::quick_sort(pivot + 1, last);
  }
}

// Insert partition function. See Listing 10.10
/** Partition the table so that values in the iterator range 
    first through pivot are less than or equal to the pivot value, 
    and values in the iterator range pivot + 1 through last 
    are greater than the pivot value.
    @param RI An iterator that meets the
           random-access iterator requirements
    @param first An iterator that references
           the first element in the sequence to be sorted
    @param last An iterator that references
           1 past the end of the sequence
    @return The position of the pivot value (originally at first)
*/
template<typename RI>
  RI partition(RI first, RI last) {
  // Start up and down at either end of the sequence.
  // The first table element is the pivot value.
  RI up = first + 1;
  RI down = last - 1;
  do {
    /* Invariant:
       All items in table[first] through table[up - 1] <= table[first]
       All items in table[down + 1] through table[last - 1] > table[first]
    */
    while ((up != last - 1) && !(*first < *up)) {
      ++up;
    }
    // Assert: up equals last-1 or table[up] > table[first].
    while (*first < *down) {
      --down;
    }
    // Assert: down equals first or table[down] <= table[first].
    if (up < down) {   // if up is to the left of down,
      // Exchange table[up] and table[down].
      std::iter_swap(up, down);
    }
  } while (up < down); // Repeat while up is left of down.
  
  // Exchange table[first] and table[down] thus putting the
  // pivot value where it belongs.
  // Return position of pivot.
  std::iter_swap(first, down);
  return down;
}


} // End namespace KW

#endif
