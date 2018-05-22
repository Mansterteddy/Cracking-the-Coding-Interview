#include <map>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

typedef pair<string, int> mypair;

ostream& operator<<(ostream& out, const mypair& mp)
{
  out << "(" << mp.first << ", " << mp.second << ")";
  return out;
}

int main()
{
  map<string, int> amap;
  amap.insert(mypair("A", 1));
  amap.insert(mypair("A", 2));
  cout << *(amap.find("A")) << endl;
  return 0;
}

