/** Program to test BinarySearch */

#include "binary_search.h"
#include "linear_search.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() {
  
  char* c_names[] = {"Caryn", "Debbie", "Dustin", "Elliot", 
		     "Jacquie", "Jonathan", "Rich"};
  
  vector<string> names(c_names, c_names + 7);
  
  cout << "Dustin is at " << binary_search(names, string("Dustin")) << endl;
  
  cout << "Dustin is at " << linear_search(names, string("Dustin")) << endl;
  
  cout << "Paul is at " << binary_search(names, string("Paul")) << endl;
  
  cout << "Paul is at " << linear_search(names, string("Paul")) << endl;
  
  int primes[] = {3, 5, 11, 7, 13, 23};
  
  vector<int> my_primes(primes, primes + 6);
  
  cout << "5 is located at " << linear_search(my_primes, 5) << endl;

  char* c_greetings[] = {"Hi", "Hello", "Shalom"};

  vector<string> greetings(c_greetings, c_greetings + 3);

int pos_hello = linear_search(greetings, string("Hello"));
  cout << "Hello is located at " << pos_hello << endl;
  
}
