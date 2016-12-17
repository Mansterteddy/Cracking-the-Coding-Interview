//Given a directed graph, design an algorithm to find out whether there is a route between two nodes.  
#include <iostream>
#include <fstream>
#include <list>
using namespace std;

//就是遍历，看是否在遍历完成之前，遍历到给定的顶点
const int maxn = 100;
int graph[maxn][maxn];
list<int> li;
//用于标记每个位置是否被访问到，因为这是graph，而不是tree
int visited[maxn];

void init()
{
    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));
}

bool BFS(int index, int size, int dst)
{
    if(index > size) 
    {
        cout<<"Too Large!"<<endl;
        return false;
    }
    li.push_back(index);
    while(!li.empty())
    {
        int temp = li.front();
        visited[temp] = 1;
        li.pop_front();
        if(graph[temp][dst] == 1) return true; 
        for(int i = 0; i < size; i++)
        {
            if(graph[temp][i] == 1 && visited[i] == 0)
            {
                li.push_back(i);
                cout<<"Visit: "<<i<<endl;
            }
        }
    }

    return false;
}

//ARG Counts, ARG Vectors
int main(int argc, char** argv)
{
    if (argc == 1) return 1;
    char* filename = argv[1];
    ifstream inputStream(filename, ios::in);
    int size = 0;
    inputStream>>size;
    cout<<"Size: "<<size<<endl;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            int temp = 0;
            inputStream>>temp;
            graph[i][j] = temp;
            cout<<"Val: "<<graph[i][j]<<endl;
        }
    }
    cout<<"Result: "<<BFS(2, 3, 1)<<endl;
    return 0;
}