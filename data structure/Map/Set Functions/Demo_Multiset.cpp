/** Program to demonstrate the multiset */

#include <set>
#include <string>
#include <iostream>
#include "Set_Functions.h"

using namespace std;

int count_occurences(const multiset<string>&, const string&);

int main()
{
  // Create a multiset of strings
  multiset<string> words_set;
  // Add some words, including duplicates
  words_set.insert("the");
  words_set.insert("cat");
  words_set.insert("in");
  words_set.insert("the");
  words_set.insert("hat");

  cout << "\"the\" is in the words_set " 
       << count_occurences(words_set, "the") 
       << " times\n";
  cout << "\"cat\" is in the words_set "
       << count_occurences(words_set, "cat")
       << " times\n";
  cout << "\"dog\" is in the words_set "
       << count_occurences(words_set, "dog")
       << " times\n";
  set<string> fruits;

  fruits.insert("Apples");
  fruits.insert("Grapes");
  fruits.insert("Oranges");
  fruits.insert("Peaches");
  fruits.insert("Pears");
  fruits.insert("Pinapples");
  fruits.insert("Tomatos");

  set<string>::const_iterator first = fruits.lower_bound("Peaches");
  set<string>::const_iterator last = fruits.upper_bound("Pinapples");

  cout << "The subset of fruits between Peaches and Pinapples is "
       << set<string>(first, last) << endl;

  first = fruits.lower_bound("P");
  last = fruits.upper_bound("Q");

  cout << "The subset of fruits between P and Q is "
       << set<string>(first, last) << endl;

  return 0;
}

int count_occurences(const multiset<string>& words_set,
		     const string& target) {
  multiset<string>::const_iterator first_itr = words_set.lower_bound(target);
  cout << "*first_itr == " 
       << (first_itr != words_set.end() ? *first_itr : "end()") << endl;
  multiset<string>::const_iterator last_itr = words_set.upper_bound(target);
  cout << "*last_itr == " 
       << (last_itr != words_set.end() ? *last_itr : "end()") << endl;
  int count = 0;
  for (multiset<string>::const_iterator itr = first_itr;
       itr != last_itr; ++itr)
    ++count;
  return count;
}
