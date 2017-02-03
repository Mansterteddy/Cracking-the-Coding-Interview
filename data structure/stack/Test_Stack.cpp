#include <iostream>
#include "stack.h"
using std::cout;
using std::endl;
using KW::stack;

int main()
{
  stack<int> the_stack;
  for (int i = 0; i < 10; i++)
    the_stack.push(i);
  if (the_stack.size() == 10) 
  {
    cout << "Size test PASSED" << endl;
  } 
  else 
  {
    cout << "Size test ******FAILED\n"
	 << "expected 10 got " << the_stack.size() << endl;
  }
  

  bool passed = true;
  for (int i = 9; i >= 0; i--) 
  {
    if (i != the_stack.top()) 
    {
      cout << "Expected " << i << " got " << the_stack.top() << endl;
      passed = false;
    }
    the_stack.pop();
  }
  if (passed) 
  {
    cout << "Push and pop test PASSED\n";
  }
  else 
  {
    cout << "Push and pop test ******FAILED\n";
  }
  if (the_stack.empty()) 
  {
    cout << "Empty test PASSED\n";
  } 
  else 
  {
    cout << "Empty test ******FAILED\n";
  }

  return 0;
}
