//Given a binary search tree, design an algorithm which creates a linked list of all the nodes
//at each depth (i.e., if you have a tree with depth D, you'll have D linked lists)
#include <iostream>
#include <cstring>
#include <vector>
#include <list>

using namespace std;

const int maxn = 100;

//本质上是个BFS
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

int dep[maxn];
int pos = 0;

vector<list<Node*>> BFS(Node *bfs_head)
{
    memset(dep, 0, sizeof(dep));
    vector<list<Node*>> ret;
    list<Node*> li;
    list<Node*> li_st;
    li_st.push_back(bfs_head);
    //ret.push_back(li_st);
    li.push_back(bfs_head);
    int count = 0;
    int pre = 1;
    dep[0] = 1;
    while(!li.empty())
    {
        if(pos == 0)
        {
            cout<<"Push already!"<<pre<<endl;
        }
        else if(dep[pos] == pre)
        {
            cout<<"In one level!"<<pre<<endl;
            Node* temp = li.front();
            li_st.push_back(temp);
            cout<<"List size:"<<li_st.size()<<endl;

        }
        else
        {
            cout<<"Another level!"<<endl;
            ret.push_back(li_st);
            list<Node*> new_li_st;
            li_st = new_li_st;
            Node* temp = li.front();
            li_st.push_back(temp);
            cout<<"List size:"<<li_st.size()<<endl;
        }

        pre = dep[pos];
        pos++;
        
        Node* temp = li.front();
        li.pop_front();
        cout<<"BFS: "<<temp->key<<endl;
        if(temp->lchild != NULL)
        {
            li.push_back(temp->lchild);
            count++;
            dep[count] = pre + 1;
        }
        if(temp->rchild != NULL)
        {
            li.push_back(temp->rchild);
            count++;
            dep[count] = pre + 1;
        }
    }
    ret.push_back(li_st);
    return ret;
}

int main()
{
    init();
    create_minmal_binary_tree(0, 8, -1);
    vector<list<Node*>> a = BFS(&node[0]);
    cout<<"Size a: "<<a.size()<<endl;
    for(int i = 0; i < a.size(); i++)
    {
        list<Node*> b = a[i];
        cout<<"Size :"<<i<<" "<<b.size()<<endl;
    }
    list<Node*> b = a[1];
    
    //迭代器是指针，应当尽可能使用迭代器，而非变量。
    list<Node*>::iterator It;
    for(It = b.begin(); It != b.end(); It++)
    {
        cout<<(*It)->key<<endl;
    }
    return 0;
}