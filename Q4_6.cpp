//Design an algorithm and write cide to find the first common ancester of two nodes in a binary tree. 
//Avoid stroing additional nodes in a data structure. NOTE: This is not necessarily a binary search tree.
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <map>

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

//最开始考虑，可以记录一个节点的祖先们和另一个节点的祖先们，比较留下最小的祖先
//但是本题目在数据结构中不允许额外的存储空间
Node* first_ancestor(Node *first, Node *second)
{
    if(first == NULL || second == NULL) return NULL;
    map<Node*, bool> amap;
    while(first != NULL)
    {
        amap[first] = true;
        first = first->parent;
    }
    Node* res = NULL;
    while(second != NULL)
    {
        if(amap[second] == true)
        {
            //return second;
            res = second;
        }
        second = second->parent;
    }

    return res;
}

bool father(Node* n1, Node* n2)
{
    if(n1 == NULL) return false;
    else if(n1 == n2) return true;
    else return father(n1->lchild, n2) || father(n1->rchild, n2);
}

Node* first_ancestor_1(Node* n1, Node* n2)
{
    if(n1 == NULL || n2 == NULL) return NULL;
    while(n1)
    {
        if(father(n1, n2)) return n1;
        n1 = n1->parent;
    }
    return NULL;
}

void first_ancestor_2(Node* head, Node* n1, Node* n2, Node** ans)
{
    if(head == NULL || n1 == NULL || n2 == NULL) return;
    if(head && father(head, n1) && father(head, n2))
    {
        cout<<"Mutual ancestor: "<<head->key<<endl;
        *ans = head;
        first_ancestor_2(head->lchild, n1, n2, ans);
        first_ancestor_2(head->rchild, n1, n2, ans);
    }
}
//如果不允许额外的存储空间，那么只能一个一个试，对第一个节点的每一个祖先，都看是否是另一个节点的祖先
//如果数据结构里不允许有parent，那就只能从每一个parent开始找，看是否有这两个子孙节点。

int main()
{
    init();
    create_minmal_binary_tree(0, 8, -1);
    Node* a = first_ancestor(&node[6], &node[8]);
    if(a == NULL)
    {
        cout<<"No Ancestor!"<<endl;
        return 0;
    }
    cout<<"First Ancestor: "<<a->key<<endl;
    Node* b = first_ancestor_1(&node[6], &node[8]);
    if(b == NULL)
    {
        cout<<"No Ancestor!"<<endl;
        return 0;
    }
    cout<<"First Ancestor: "<<b->key<<endl;
    Node *c;
    first_ancestor_2(&node[0], &node[6], &node[8], &c);
    if(c == NULL)
    {
        cout<<"No Ancestor!"<<endl;
        return 0;
    }
    cout<<"First Ancestor: "<<c->key<<endl;
    return 0;
}
