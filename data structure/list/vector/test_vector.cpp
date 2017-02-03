#include "vector.h"
#include <iostream>
#include <ostream>
using std::cout;
using std::endl;
#include <stdexcept>

int main()
{
    KW::vector<int> vect1;
    for(int i = 0; i < 20; ++i)
    {
        vect1.push_back(i);
    }

    bool pass = true;
    for (int i = 0; i < 20; i++) 
    {
        if (i != vect1[i]) 
        {
            cout << i << " != vect1[" << i << "] == "
	        << vect1[i] << '\n';
            pass = false;
        }
  }
  if (pass)
    cout << "Index test passed\n";
  
  KW::vector<int> vect2;
  for (int i = 0; i < 20; i += 2) 
  {
    vect2.push_back(i);
  }
  for (int i = 0; i < 20; i += 2) 
  {
    vect2.insert(i+1, i+1);
  }
  pass = true;
  for (int i = 0; i < 20; i++) 
  {
    if (i != vect2[i]) 
    {
      cout << i << " != vect2[" << i << "] == "
	   << vect2[i] << '\n';
      pass = false;
    }
  }
  if (pass)
    cout << "Insert test passed\n";
  
  bool passed = false;
  try 
  {
    vect1[-1] = 0;
  } catch (std::out_of_range& ex) {
    passed = true;
    cout << ex.what() << " " << "Out of range negative index test passed\n";
  }

  if (!passed)
    cout << "Out of range negative index test failed\n";
  
  passed = false;
  try 
  {
    vect1[vect1.size()] = 0;
  } catch (std::out_of_range& ex) {
    passed = true;
    cout << ex.what() << " " << "Out of range index too large test passed\n";
  }
  if (!passed)
    cout << "Out of range index too large test failed\n";

}