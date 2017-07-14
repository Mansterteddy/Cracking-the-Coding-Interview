#ifndef BINARYSEARCH_H_
#define BINARYSEARCH_H_

#include <vector>

/** Recursive binary search function (in binary_search.h).
    @param items The vector being searched
    @param first The subscript of the first element
    @param last The subscript of the last element
    @param target The item being searched for
    @return The subscript of target if found; otherwise -1
*/
template<typename Item_Type>
  int binary_search(const std::vector<Item_Type>& items, 
                    int first, int last, 
                    const Item_Type& target) {
  if (first > last)
    return -1;     // Base case for unsuccessful search.
  else {
    int middle = (first + last) / 2;  // Next probe index.
    if (target == items[middle])
      return middle;   // Base case for successful search.
    else if (target < items[middle])
      return binary_search(items, first, middle - 1, target);
    else
      return binary_search(items, middle + 1, last, target);
  }
}

/** Wrapper for recursive binary search function (in binary_search.h).
    @param items The vector being searched
    @param target The item being searched for
    @return The subscript of target if found; otherwise -1
*/
template<typename Item_Type>
  int binary_search(const std::vector<Item_Type>& items, 
                    const Item_Type& target) {
  return binary_search(items, 0, items.size() - 1, target);
}
#endif
