/** Program to demonstrate some features of the STL list */

#ifdef USEKW
#include "list.h"
using KW::list;
#else
#include <list>
using std::list;
#endif

#include <iostream>
#include <iterator>
#include <string>

#ifndef USEKW
#include <algorithm>
#else
namespace KW 
{
  template <typename iter, typename T>
  iter find(iter begin, iter end, const T& t) 
  {
    while (begin != end) 
    {
      if (*begin == t) return begin;
      else ++begin;
    }
    return begin;
  }
}
#endif

using std::cout;
using std::endl;
using std::string;

/** Remove items divisible by a given value.
    pre: a_list contains int values.
    post: Elements divisible by div have been removed.
*/
void remove_divisible_by(list<int>& a_list, int div) 
{
  list<int>::iterator iter = a_list.begin();
  while (iter != a_list.end()) 
  {
    if (*iter % div == 0) 
    {
      iter = a_list.erase(iter);
    } 
    else 
    {
      ++iter;
    }
  }
}

#ifndef USEKW
template <typename T>
void print_list(const list<T>& a_list) 
{
  std::ostream_iterator<T> osi(cout, ", ");
  std::copy(a_list.begin(), a_list.end(), osi);
  cout << "\n";
}
#else
template <typename T>
void print_list(const list<T>& a_list) 
{
  typename list<T>::const_iterator iter = a_list.begin();
  while (iter != a_list.end()) 
  {
    cout << *iter;
    if (++iter != a_list.end())
      cout << ", ";
  }
  cout << endl;
}
#endif



/** Replace the first occurrence of target with new_value.
    pre:  a_list contains string values.
    post: The first occurrence of target is replaced by new_value.
*/
void find_and_replace(list<string>& a_list, 
                      const string& target, 
                      const string& new_value) 
{
  list<string>::iterator iter = a_list.begin();
  while (iter != a_list.end()) 
  {
    if (*iter == target) 
    {
      *iter = new_value;
      break;
    }
    else 
    {
      ++iter;
    }
  }
}


int main()
{
  list<int> a_list;
  for (int i = 0; i < 10; i++)
    a_list.push_back(i);
  print_list(a_list);
  remove_divisible_by(a_list, 2);
  print_list(a_list);
  remove_divisible_by(a_list, 3);
  print_list(a_list);
  
  const char* names[] = {"Tom", "Dick", "Harry", "Sharon", "Sam"};
  list<string> my_list(names, names+5);
  print_list(my_list);
  find_and_replace(my_list, "Harry", "Bill");
  print_list(my_list);

  #ifndef USEKW
  list<string>::iterator to_sam = find(my_list.begin(), 
				       my_list.end(), "Sam");
  --to_sam;
  my_list.erase(to_sam);
  print_list(my_list);
  #else
  list<string>::iterator to_sam = KW::find(my_list.begin(), 
					   my_list.end(), "Sam");
  --to_sam;
  my_list.erase(to_sam);
  print_list(my_list);
  #endif

  return 0;
}

