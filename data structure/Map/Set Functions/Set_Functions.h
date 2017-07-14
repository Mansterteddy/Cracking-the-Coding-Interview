#ifndef SET_FUNCTIONS_H
#define SET_FUNCTIONS_H

#include <set>
#include <ostream>

/** Template definitions of common mathematical set operations
    using the C++ set class */

/** Construct the union of two sets. */
template<typename Key_Type, typename Compare>
  std::set<Key_Type, Compare> operator+(
      const std::set<Key_Type, Compare>& left,
      const std::set<Key_Type, Compare>& right) {
  typename std::set<Key_Type, Compare> result(left);
  result.insert(right.begin(), right.end());
  return result;
}

/** Construct the difference of two sets. */
template<typename Key_Type, typename Compare>
  std::set<Key_Type, Compare> operator-(
      const std::set<Key_Type, Compare>& left,
      const std::set<Key_Type, Compare>& right) {
  typename std::set<Key_Type, Compare> result(left);
  for (typename std::set<Key_Type, Compare>::const_iterator 
       itr = right.begin(); itr != right.end(); ++itr)
    result.erase(*itr);
  return result;
}


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
