#ifndef SELECTIONSORT_H_
#define SELECTIONSORT_H_

#include <algorithm>

namespace KW {

/** Sort data in the specified sequence using selection sort.
    @param RI An iterator that meets the
              random-access iterator requirements
    @param first An iterator that references the first element
                 of the sequence to be sorted
    @param last An iterator that references one past the
                end of the sequence to be sorted
*/
template<typename RI>
  void selection_sort(RI first, RI last) {
  for (RI fill = first; fill != last - 1; ++fill) {
    // Invariant: Elements at positions first through fill - 1 are sorted.
    RI pos_min = fill;
    for (RI next = fill + 1; next != last; ++next) {
      // Invariant: pos_min references the smallest item in
      //            positions fill through next - 1.
       if (*next < *pos_min) {
        pos_min = next;
      }
    }
    // Assert: pos_min references the smallest item in positions fill 
    // through last - 1.
    // If the next smallest item is not at fill, exchange *fill and     
    // *pos_min.
    if (fill != pos_min) {
      std::iter_swap(pos_min, fill);
    }
  }
}
 
/** Sort data in the specified range using selection sort.
    @param RI An iterator that meets the
              random-access iterator requirements
    @param first An iterator that references the beginning
                 of the sequence to be sorted
    @param last An iterator that references 1 past the
                end of the sequence to be sorted
    @param comp An object that implements a comparison function
*/
template<typename RI, typename Compare>
  void selection_sort(RI first, RI last,
                      Compare comp) {
  for (RI fill = first; fill != last - 1; ++fill) {
    // Invariant: Elements at positions first through fill - 1 are sorted.
    RI pos_min = fill;
    for (RI next = fill + 1; next != last; ++next) {
      // Invariant: pos_min references the smallest item in
      //            positions fill through next - 1.
      if (comp(*next, *pos_min)) {
        pos_min = next;
      }
    }
    // Assert: pos_min references the smallest item in positions fill 
    // through last - 1.
    // If the next smallest item is not at fill, exchange *fill and 
    // *pos_min.
    if (fill != pos_min)
      std::iter_swap(pos_min, fill);
  }
}

} // End namespace KW

#endif
