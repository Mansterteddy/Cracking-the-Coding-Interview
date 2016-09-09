//You are given a binary tree in which each node contains a value. 
//Design an algorithm to print all paths which sum up to that value. 
//Note that it can be any path in the tree. It does not have to start at the root. 
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 100;

int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

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

//肯定是最中间的数做中点 树最矮 而这要用到递归
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

//从每一个节点，向parent依次走，这样可以不需要额外的空间存储
void print(Node* head, int level)
{
    vector<int> v;
    for(int i = 0; i < level; i++)
    {
        v.push_back(head->key);
        head = head->parent;
    }

    while(!v.empty())
    {
        cout<<v.back()<<" ";
        v.pop_back();
    }
    cout<<endl;
}

void find_sum(Node* head, int sum)
{
    if(head == NULL) return;
    Node *no = head;
    int tmp = 0;
    for(int i = 1; no != NULL; i++)
    {
        tmp += no->key;
        if(tmp == sum)
        {
            print(head, i);
        }
        no = no->parent;
    }
    find_sum(head->lchild, sum);
    find_sum(head->rchild, sum);
}

//从每一个节点向下走，需要记录路径，也就是额外的空间。
void print2(vector<int>* v, int level)
{
    cout<<"Enter"<<v->size()<<" "<<level<<endl;    
    for(int i = 0; i < v->size(); i++)
    {
        cout<<v->at(i)<<" ";
    }
    cout<<endl;
}

void find_sum2(Node* head, int sum, int above_sum, vector<int> *v, int level)
{
    if(head == NULL) return;

    v->push_back(head->key);
    level = level + 1;
    if(above_sum + head->key == sum)
    {
        print2(v, level);

    }
    find_sum2(head->lchild, sum, above_sum + head->key, v, level);
    find_sum2(head->rchild, sum, above_sum + head->key, v, level);

    v->pop_back();
    level = level - 1;

    //vector<int> v1, v2;
    //find_sum2(head->lchild, sum, 0, &v1, 0);
    //find_sum2(head->rchild, sum, 0, &v2, 0);
}

int main()
{
    init();
    create_minmal_binary_tree(0, 8, -1);
    find_sum(&node[0], 18);

    //vector<int> v;
    //find_sum2(&node[0], 8, 0, &v, 0);
    for(int i = 0; i < cnt; i++)
    {
        vector<int> v;
        find_sum2(&node[i], 18, 0, &v, 0);
    }
    return 0;
}
