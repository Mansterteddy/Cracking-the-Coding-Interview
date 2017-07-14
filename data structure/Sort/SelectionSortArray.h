#ifndef SELECTIONSORTARRAY_H_
#define SELECTIONSORTARRAY_H_

#include <algorithm>

namespace KW {

/** Sort data in an int[] array using selection sort.
    @param the_array The array to be sorted
    @param size The number of elements in the_array
*/
void selection_sort_array(int the_array[], size_t size) {
  for (size_t fill = 0; fill != size - 1; ++fill) {
    // Invariant: Elements at positions first through fill - 1 are sorted.
    size_t pos_min = fill;
    for (size_t next = fill + 1; next != size; ++next) {
      // Invariant: pos_min references the smallest item in 
      //            positions fill through next - 1.
      if (the_array[next] < the_array[pos_min]) {
        pos_min = next;
      }
    }
    // Assert: pos_min references the smallest item in positions fill 
    // through last - 1.
    // If the next smallest item is not at fill, exchange *fill and 
    // *pos_min.
    if (fill != pos_min)
      std::swap(the_array[pos_min], the_array[fill]);
  }
}

} // End namespace KW

#endif
