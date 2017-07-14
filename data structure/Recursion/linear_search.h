#ifndef LINEARSEARCH_H_
#define LINEARSEARCH_H_

#include <vector>
/** Recursive linear search function (in linear_search.h).
    @param items The vector being searched
    @param target The item being searched for
    @param pos_first The position of the current first element
    @return The subscript of target if found; otherwise -1
*/
template<typename Item_Type>
  int linear_search(const std::vector<Item_Type>& items, 
                    const Item_Type& target, size_t pos_first) {
  if (pos_first == items.size())
    return -1;
  else if (target == items[pos_first])
    return pos_first;
  else
return linear_search(items, target, pos_first + 1); 
}

/** Wrapper for recursive linear search function (in linear_search.h).
    @param items The vector being searched
    @param target The object being searched for
    @return The subscript of target if found; otherwise -1
*/
template<typename Item_Type>
  int linear_search(const std::vector<Item_Type>& items, 
                    const Item_Type& target) {
  return linear_search(items, target, 0);
}

#endif


