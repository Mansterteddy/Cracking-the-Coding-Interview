#include "Ordered_List.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ostream>
using std::cout;
using std::rand;
using std::srand;
using std::time;

/** Traverses the ordered list and displays each element.
    Displays an error message if an element is out of order.
    pre: The list elements are all positive and the list is 
         not empty.
    @param test_list An ordered list
*/
void traverse_and_show(const Ordered_List<int>& test_list) 
{
  Ordered_List<int>::const_iterator iter = test_list.begin();
  int prev_item = *iter;
  // Traverse ordered list and display any value that
  // is out of order.
  ++iter;
  while (iter != test_list.end()) 
  {
    int this_item = *iter++;
    cout << prev_item << '\n';
    if (prev_item > this_item) 
    {
      cout << "*** FAILED, value is "
           << this_item << '\n';
    }
    prev_item = this_item;
  }
  cout << prev_item << '\n';
}

int main() 
{
  Ordered_List<int> test_list;
  const int MAX_INT = 500;
  const int START_SIZE = 100;
  // Initialize random number generator
  srand(time(0));
  // Create a random number generator.
  for (int i = 0; i < START_SIZE; i++) 
  {
    int an_integer = rand() % MAX_INT;
    test_list.insert(an_integer);
}

  // Add to beginning and end of list.
  test_list.insert(-1);
  test_list.insert(MAX_INT + 1);
  cout << "Original list\n";
  traverse_and_show(test_list);  // Traverse and display.

  // Remove first, last, and middle elements.
  int first = *(test_list.begin());
  test_list.remove(first);
  cout << "After removing first item\n";
  traverse_and_show(test_list);  // Traverse and display.

  int last = *(--test_list.end());
  test_list.remove(last);
  cout << "After removing last item\n";
  traverse_and_show(test_list);
  
  return 0;
}

