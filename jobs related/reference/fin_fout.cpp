#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    if(argc < 3)
    {
        cout<<"You should input a input filename and a output filename!\n"
            <<"For example, fin.txt, fout.txt.\n";
    }

    ifstream ins(argv[1]);

    if(!ins)
    {
        cerr<<"Failed to open "<<argv[1]<<endl;
        return 1;
    }

    ofstream outs(argv[2]);
    if(!outs)
    {
        cerr<<"Failed to open "<<argv[2]<<endl;
    }

    string first;
    string second;

    while(ins>>first)
    {
        cout<<"Type a word to follow "<<first<<": ";
        cin>>second;
        
        outs << first << ", " << second << endl;
    }

    ins.close();
    outs.close();
    return 0;
}