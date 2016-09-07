//Write an algorithm to find the 'next' node (i.e. in-order successor) of a given node in a binary search tree where each node has a link to its parent. 
#include <iostream>
#include <cstring>
#include <vector>
#include <list>

using namespace std;

const int maxn = 100;

//先序遍历：先访问根节点，然后左子树，右子树
//中序遍历：先遍历左子树，再访问根节点，右子树
//后序遍历：先访问左子树，再访问右子树，根节点
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

Node* find_left_in_right(Node* head)
{
    Node* res;
    res = head->rchild;
    while(res->lchild != NULL)
    {
        res = res->lchild;
    }
    return res;
}

//给定任意一个节点，如果这个节点有右子树，则该节点的右子树的最左节点为下一个节点
//如果这个节点没有右子树，则为第一个大于该节点key的树节点
//如果是最右点，则返回NULL
//应当使用递归的方法
Node* findNext(Node* head)
{
    int val = head->key;
    Node* next;
    if(head->rchild == NULL)
    {
        while(head->parent != NULL)
        {
            if(val < (head->parent)->key)
            {
                return head->parent;
            }
            head = head->parent;
        }
        return NULL;
    }
    else
    {
        next = find_left_in_right(head);
    }

    return next;
}


int main()
{
    init();
    create_minmal_binary_tree(0, 8, -1);
    Node* next = findNext(&node[2]);
    if(next == NULL)
    {
        cout<<"No next!"<<endl;
        return 0;
    }
    cout<<"Next is: "<<next->key<<endl;
    return 0;
}
