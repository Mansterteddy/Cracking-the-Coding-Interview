//Write a method to print the last K lines of an input file using C++

#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

//第一种方式是：先遍历一次文件，获取文件的行数，随后再遍历一次文件，输出从n-k到n行。
//第二种方法是：做一个k行的buffer，逐行读取，更新buffer，直到读到最后一行，此时buffer里就是所需内容了。
//第二种方法可以采用一种更加聪明的数据结构，list，这样每次删除掉头部，加一个底部，就完成了更新，不用搞重复操作。

void printLastKLines(ifstream *ins, int k)
{
    list<string> li;
    string line;
    int start = 0;
    //while((*ins)>>line)
    while(getline(*ins, line))
    {
        if(start <= k - 1)
        {
            li.push_back(line);
            start++;
        }
        else
        {
            li.pop_front();
            li.push_back(line);
        }
    }

    list<string>::iterator it;
    for(it = li.begin(); it != li.end(); it++)
    {
        cout<<*it<<endl;
    }

    return;
}

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        cerr<<"Without Input Filename!\n";
        return 1;
    }

    ifstream ins(argv[1]);
    if(!ins)
    {
        cerr<<"Failed to open "<< argv[1] <<"!\n";
        return 1;
    }

    printLastKLines(&ins, 4);

    ins.close();

    return 0;
}