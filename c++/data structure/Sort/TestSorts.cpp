/** Driver function to test sorts. */

#include <iostream>
#include <iterator>
#include <vector>
#include "Random.h"
#include "QuickSort.h"
#include <ctime>

using namespace std;

template<typename RI>
  bool verify(RI first, RI last);

template<typename RI>
  void dump_table(RI first, RI last);

int main() {
  vector<int> a_vec;
  int num_items;
  Random rand;

  // Fill vector a_vec with random numbers.
  cout << "Enter vector size: ";
  cin >> num_items;
  for (int i = 0; i < num_items; i++) {
    a_vec.push_back(rand.next_int(2 * num_items));
  }
  vector<int> copya_vec = a_vec;   // A copy of a_vec.

  // Sort and verify using standard sorting algorithm.
  long int start = clock();
  std::sort(a_vec.begin(), a_vec.end());
  cout << "time for standard sort: " << (clock() - start) << endl;
  if (verify(a_vec.begin(), a_vec.end()))
    cout << "standard sort successful\n";
  else
    cout << "standard sort failed\n";
  dump_table(a_vec.begin(), a_vec.end());

  // Sort and verify using KW sorting function.
  start = clock();
  KW::quick_sort(copya_vec.begin(), copya_vec.end());
  cout << "time for KW sort: " << (clock() - start) << endl;
  if (verify(copya_vec.begin(), copya_vec.end()))
    cout << "KW sort successful\n";
  else
    cout << "KW sort failed\n";
  dump_table(copya_vec.begin(), copya_vec.end());

  return 0;
}

template<typename RI>
  bool verify(RI first, RI last) {
  while (first != last - 2) {
    if (*(first + 1) < *first)
      return false;
    ++first;
  }
  return true;
}

template<typename RI>
  void dump_table(RI first, RI last) {
  // Exercise
}
