#ifndef SHELLSORT2_H_
#define SHELLSORT2_H_

namespace KW {


/** Sort data in the specified range using Shell sort.
    @param RI An iterator that meets the
           random-access iterator requirements
    @param first An iterator that references
           the first element in the sequence to be sorted
    @param last An iterator that references
           1 past the end of the sequence
*/
template<typename RI>
  void shell_sort2(RI first, RI last) {
  // Set initial gap between adjacent elements.
  size_t gap = (last - first) / 2;
  while (gap > 0) {
    for (RI next_pos = first + gap;
         next_pos != last; ++next_pos) {
      RI next_insert = next_pos;
      // Insert element at next_pos in its subarray.
      typename std::iterator_traits<RI>::value_type next_val = *next_insert;
      // Shift all values > next_val in subarray down by gap.
      while ((next_insert > first + gap - 1)  // First element not shifted.
	     && (next_val < *(next_insert - gap))) {
	*next_insert = *(next_insert - gap);   // Shift down.
	next_insert -= gap;     // Check next position in subarray.
      }
      *next_insert = next_val;
    }  // End for.
    // Reset gap for next pass.
    if (gap == 2) {
      gap = 1;
    } else {
      gap = size_t(gap / 2.2);
    }
  } 
}

/** Sort data in the specified range using Shell sort.
    @param RI An iterator that meets the
           random-access iterator requirements
    @param first An iterator that references
           the first element in the sequence to be sorted
    @param last An iterator that references
           1 past the end of the sequence
    @param comp An object that implements a comparison function
*/
template<typename RI, typename Compare>
  void shell_sort2(RI first, RI last, Compare comp) {
  // Set initial gap between adjacent elements.
  size_t gap = (last - first) / 2;
  while (gap > 0) {
    for (RI next_pos = first + gap;
         next_pos != last; ++next_pos) {
      RI next_insert = next_pos;
      // Insert element at next_pos in its subarray.
      typename std::iterator_traits<RI>::value_type next_val = *next_insert;
      // Shift all values > next_val in subarray down by gap.
      while ((next_insert > first + gap - 1)  // First element not shifted.
	     && comp(next_val, *(next_insert - gap))) {
	*next_insert = *(next_insert - gap);   // Shift down.
	next_insert -= gap;     // Check next position in subarray.
      }
      *next_insert = next_val;
    }  // End for.
    // Reset gap for next pass.
    if (gap == 2) {
      gap = 1;
    } else {
      gap = size_t(gap / 2.2);
    }
  } 
}

/** Sort data in an Item_Type[] array using Shell sort.
    @param the_array The array to be sorted
    @param size The number of elements in the_array
*/
template<typename Item_Type>
  void shell_sort2(Item_Type* the_array, size_t size) {
  // Set initial gap between adjacent elements.
  size_t gap = size / 2;
  while (gap > 0) {
    for (size_t next_pos = gap; next_pos < size; next_pos++) {
      size_t next_insert = next_pos;
      // Insert element at next_pos in its subarray.
      Item_Type next_val = the_array[next_pos];
      // Shift all values > next_val in subarray down by gap.
      while ((next_insert > gap - 1)  // First element not shifted.
	     && (next_val < the_array[next_insert - gap])) {
	the_array[next_insert] = the_array[next_insert - gap];
	next_insert -= gap;     // Check next position in subarray.
      }
      the_array[next_insert] = next_val;
    }  // End for.
    // Reset gap for next pass.
    if (gap == 2) {
      gap = 1;
    } else {
      gap = int(gap / 2.2);
    }
  } 
}


} // End namespace KW

#endif
