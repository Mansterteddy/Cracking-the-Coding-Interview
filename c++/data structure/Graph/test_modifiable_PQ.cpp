#include <iostream>
#include "Modifiable_Priority_Queue.h"
#include <vector>

using namespace std;

/** Method to test modifiable_priority_queue */
int main() {

  vector<int> loc(10);
  KW::Modifiable_Priority_Queue<int> the_queue;
  
  // Add some values
  for (size_t i = 0; i < loc.size(); i++) {
    int k = 20 - 2 * i;
    loc[i] = the_queue.insert(k);
  }
  // See where things are
  the_queue.print_tables(loc);
  // Change the value of the largest item
  the_queue.replace_item(loc[0], 0);
  // See where things are now
  the_queue.print_tables(loc);
  // Change the value of the smallest item
  the_queue.replace_item(loc[9], 22);
  // See where things are now
  the_queue.print_tables(loc);
  // Make a middle value smaller
  the_queue.replace_item(loc[5], 5);
  the_queue.print_tables(loc);
  //Make a middle value larger
  the_queue.replace_item(loc[6], 9); 
  the_queue.print_tables(loc);
}



