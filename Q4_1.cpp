//Implement a function to check if a tree is balanced. For the purposes of this question,
//a balanced tree is defined to be a tree such that no two leaf nodes differ in distance from the root by more than one. 
//这道题考察的就是遍历所有的结点，BFS或者DFS，记录每一个结点的深度，随后check isBalance。
#include <iostream>
#include <cstring>
#include <list>
#include "math.h"
using namespace std;

const int maxn = 100;

struct Node
{
    int key;
    Node *lchild, *rchild, *parent;
};

//必须在静态变量区申请node空间，否则在函数里会被释放，无法保存。
Node *head, *p, node[maxn];
int cnt;

void init()
{
    head = p = NULL;
    memset(node, '\0', sizeof(node));
    cnt = 0;
}

void insert(Node* insert_head, int x)
{
    if(insert_head == NULL)
    {
        cout<<"Insert: "<<x<<endl;
        if(p != NULL)
            cout<<"Parent Key: "<<p->key<<endl;
        node[cnt].key = x;
        node[cnt].parent = p;
        if(p != NULL)
        {
            if(p->key > x)
                p->lchild = &(node[cnt]);
            else
                p->rchild = &(node[cnt]);
        }
        cnt++;
        head = &node[0];
        return;
    }
    p = insert_head;
    if(x < insert_head->key)
        insert(insert_head->lchild, x);
    else
        insert(insert_head->rchild, x);
}

//此题不是很适合使用BFS，想用的话，就要在结构体里增加一条tree level的记录
void BFS(Node *bfs_head)
{
    list<Node*> li;
    li.push_back(bfs_head);
    while(!li.empty())
    {
        Node* temp = li.front();
        li.pop_front();
        cout<<"BFS: "<<temp->key<<endl;
        if(temp->lchild != NULL)
            li.push_back(temp->lchild);
        if(temp->rchild != NULL)
            li.push_back(temp->rchild);
    }
}


//DFS的核心就是不断递归，直到没路可走，随后返回。

int dep[maxn];
int pos = 0;
int depth = 0;

void DFS(Node *dfs_head)
{
    if(dfs_head == NULL) return;
    cout<<"DFS: "<<dfs_head->key<<endl;
    depth++;
    if(dfs_head->lchild == NULL && dfs_head->rchild == NULL)
    {
        dep[pos] = depth;
        pos++;
    }
    DFS(dfs_head->lchild);
    DFS(dfs_head->rchild);
    depth--;
}

//pos已经包含了数组的长度
bool isBalance()
{
    int min = dep[0];
    int max = dep[0];
    for(int i = 0; i < pos; i++)
    {
        if(dep[i] > max) max = dep[i];
        if(dep[i] < min) min = dep[i];
    }

    if(max - min <= 1) return true;
    else return false;
}

int main()
{
    int a[] = {5, 3, 8, 1, 4, 7, 10, 2, 6, 9, 11, 12};
    int length = sizeof(a) / sizeof(a[0]);
    for(int i = 0; i < length; i++)
    {
        insert(head, a[i]);
    }
    DFS(&node[0]);
    cout<<"Result: "<<isBalance()<<endl;
    BFS(&node[0]);
    return 0;
}
