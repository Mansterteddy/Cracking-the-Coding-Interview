#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "Set_Functions_alt.h"    // for operator<<

using namespace std;

int main()
{
  set<string> set1;
  set<string> set2;
  set<string> set_u;
  set<string> set_d;
  set<string> set_i;

  string data1[] = {"Apples", "Oranges", "Pineapples"};
  string data2[] = {"Peaches", "Apples", "Grapes"};

  set1.insert(data1, data1+3);
  set2.insert(data2, data2+3);
  cout << "set1 is " << set1 << endl;
  cout << "set2 is " << set2 << endl;

  set_union(set1.begin(), set1.end(), 
            set2.begin(), set2.end(),
            inserter(set_u, set_u.begin()));
  cout << "set1 + set2 is " << set_u << endl;

  set_difference(set1.begin(), set1.end(),
                 set2.begin(), set2.end(),
                 inserter(set_d, set_d. begin()));
  cout << "set1 - set2 is " << set_d << endl;

  set_intersection(set1.begin(), set1.end(),
                   set2.begin(), set2.end(),
                   inserter(set_i, set_i. begin()));
  cout << "set1 * set2 is " << set_i << endl;

  bool is_member = (set1.find(string("Apples")) != set1.end());
  cout << "\"Apples\" is an element of set1 is "
       << boolalpha << is_member << endl;

  return 0;
} 
