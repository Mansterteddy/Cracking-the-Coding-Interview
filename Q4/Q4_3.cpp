//Given a sorted (increasing order) array, write an algorithm to create a binary tree with minimal height. 
#include <iostream>

using namespace std;

const int maxn = 1000;

int a[] = {1, 2, 3, 4, 5, 6, 7};

struct Node
{
    int key;
    Node* parent;
    Node* lchild;
    Node* rchild;
};

Node node[maxn];
int cnt = 0;

void init()
{
    memset(node, '\0', sizeof(node));
}

//肯定是最中间的数做中点 树最矮 而这似乎要用到递归
void create_minmal_binary_tree(int start, int end, int parent_id)
{
    if(start > end) return;
    if(start == end) 
    {
        node[cnt].key = a[start];
        node[cnt].lchild = NULL;
        node[cnt].rchild = NULL;
        cout<<"Create node:"<<node[cnt].key<<" pos:"<<cnt<<" Parent:"<<node[parent_id].key<<endl;
        if(parent_id > 0)
        {
            node[cnt].parent = &node[parent_id];
            if(node[parent_id].key > node[cnt].key) node[parent_id].lchild = &node[cnt];
            else node[parent_id].rchild = &node[cnt];
        }
        cnt++;
        return;
    }
    int mid = (start + end) / 2;
    int temp_key = a[mid];
    int current_id = cnt;
    node[cnt].key = temp_key;
    cout<<"Create node:"<<temp_key<<" pos:"<<cnt<<" Parent:"<<node[parent_id].key<<endl;
    if(parent_id >= 0)
    {
        node[cnt].parent = &node[parent_id];
        if(node[parent_id].key > temp_key) node[parent_id].lchild = &node[cnt];
        else node[parent_id].rchild = &node[cnt];
    }
    cnt++;
    create_minmal_binary_tree(start, mid - 1, current_id);
    create_minmal_binary_tree(mid + 1, end, current_id); 
}

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

int height()
{
    int max = dep[0];
    for(int i = 0; i < pos; i++)
    {
        if(dep[i] > max)
            max = dep[i];
    }
    return max;
}


int main()
{
    init();
    create_minmal_binary_tree(0, 6, -1);
    DFS(&node[0]);
    cout<<"Max Height: "<<height()<<endl;
    return 0;
}