#ifndef SET_FUNCTIONS_ALT_H
#define SET_FUNCTIONS_ALT_H

#include <set>
#include <ostream>
#include <algorithm>
#include <iterator>

/** Template definitions of common mathematical set operations
    using the C++ set class */



// Overloading the ostream insertion operator
template<typename Item_Type>
  std::ostream& operator<<(std::ostream& out, 
                           const std::set<Item_Type>& a_set) {
  out << "{";
  bool first = true;
  for (typename std::set<Item_Type>::const_iterator itr = a_set.begin();
       itr != a_set.end(); ++itr) {
    if (first)
      out << *itr;
    else
      out << ", " << *itr;
    first = false;
  }
  return out << "}";
}

template<typename Key_Type, typename Compare>
  bool contains(const std::set<Key_Type, Compare>& s, 
                const Key_Type& k) {
  return s.find(k) != s.end();
}

#endif
