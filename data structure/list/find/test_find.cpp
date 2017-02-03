#include "find.h"
#include <list>
using std::list;
#include <string>
using std::string;
#include <iostream>
#include <ostream>
using std::cout;
using std::endl;

class Divisible_By
{
    private:
        int divisor;
    public:
        Divisible_By(int d) : divisor(d) {}
    bool operator()(int x) 
    {
        return x % divisor == 0;
    }
};

bool is_even(int i)
{
  return i % 2 == 0;
}

int main() 
{
  int list_1_data[] = {1, 3, 4, 5, 6, 9, 10};
  string list_2_data[] = {"abc", "def", "ghi", " ab", "def", "abc"};
  
  list<int> list_1(list_1_data, list_1_data + 7);
  list<string> list_2(list_2_data, list_2_data + 6);

  if (KW::find(list_1, 10) != list_1.end())
    cout << "list 1 contains 10\n";
  else
    cout << "list 2 does not contain 10\n";
  
  if (KW::find(list_2, "abc") != list_2.end())
    cout << "list 2 contains \"abc\"\n";
  else
    cout << "list 2 does not contain \"abc\"\n";
  
  if (KW::find(list_1.begin(), list_1.end(), 10) != list_1.end())
    cout << "list 1 contains 10\n";
  else
    cout << "list 1 does not contain 10\n";
  
  if (KW::find(list_2.begin(), list_2.end(), "abc") != list_2.end())
    cout << "list 2 contains \"abc\"\n";
  else
    cout << "list 2 does not contain \"abc\"\n";

  list<int>::iterator iter = KW::find_if(list_1.begin(), list_1.end(), is_even);
  cout << "The first even number is " << *iter << '\n';

  iter = KW::find_if(list_1.begin(), list_1.end(), Divisible_By(3));
  if (iter != list_1.end())
    cout << "The first number divisible by 3 is " << *iter << '\n';
  else
    cout << "There are no numbers divisible by 3\n";

  iter = KW::find_if(list_1.begin(), list_1.end(), Divisible_By(5));
  if (iter != list_1.end())
    cout << "The first number divisible by 5 is " << *iter << '\n';
  else
    cout << "There are no numbers divisible by 5\n";

  return 0;
}



  
