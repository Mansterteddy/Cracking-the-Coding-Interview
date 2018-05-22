#include <vector>
#include <iostream>
#include "Random.h"
#include "priority_queue.h"

using std::cout;
using std::endl;
using KW::priority_queue;
using std::vector;

int main()
{
  Random random;
  priority_queue<int> pq;
  for (int i = 0; i < 100; i++)
    pq.push(random.next_int(1000));
  vector<int> v;
  while(!pq.empty()) {
    v.push_back(pq.top());
    pq.pop();
  }
  bool passed = true;
  for (size_t i = 1; i < v.size(); i++) {
    if(v[i - 1] < v[i]) {
      passed = false;
      cout << "Data out of order " << v[i -1]
	   << " " << v[i] << endl;
    }
  }
  if (passed) 
    cout << "PASSED\n";
  else
    cout << "******FAILED\n";
}
