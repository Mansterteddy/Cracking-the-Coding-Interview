//You have two very large binary trees: T1, with millions of nodes, and T2, with hundreds of nodes. 
//Create an algorithm to decide if T2 is a subtree of T1 
#include <iostream>
#include <string>

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

//暴力求解 用到递归
bool match(Node* r1, Node* r2)
{
    if(r1 == NULL && r2 == NULL) return true;
    else if(r1 == NULL || r2 == NULL) return false;
    else if(r1->key != r2->key) return false;
    else return match(r1->lchild, r2->lchild) && match(r1->rchild, r2->rchild);
}

bool subtree(Node* r1, Node* r2)
{
    if(r1 == NULL) return false;
    else if(r1->key == r2->key)
    {
        if(match(r1, r2)) return true;
    }
    else
    {
        return subtree(r1->lchild, r2) || subtree(r1->rchild, r2);
    }
}

bool contain_tree(Node* r1, Node* r2)
{
    if(r2 == NULL) return true;
    else return subtree(r1, r2);
}


//在大数据情况下，快速查找和匹配。可以采用暴力匹配的法，先匹配根，然后再依次匹配左右子树。存在特殊情况，比如多一个最右子节点，那么查看先序遍历和中序遍历后是否始终包含它
//先序遍历和中序遍历可以确定一棵树，中序遍历和后序遍历可以确定一棵树，然而先序遍历和后序遍历无法确定一棵树，因为无法分开先序遍历根节点后面的部分，无法知道哪部分是左子树，哪部分是右子树，进而无法递归处理。
//如果先序、中序、后序遍历小树和大树，小树得到的序列始终是大树的子序列，则为子树。
void pre_traverse(Node *nd, string* str)
{
    if(nd == NULL) return;
    cout<<"Node: "<<nd->key<<endl;
    (*str) += char(nd->key + 48);
    pre_traverse(nd->lchild, str);
    pre_traverse(nd->rchild, str);
}

void mid_traverse(Node *nd, string* str)
{
    if(nd == NULL) return;
    mid_traverse(nd->lchild, str);
    cout<<"Node: "<<nd->key<<endl;
    (*str) += char(nd->key + 48);
    mid_traverse(nd->rchild, str);
}

void back_traverse(Node *nd, string* str)
{
    if(nd == NULL) return;
    back_traverse(nd->lchild, str);
    back_traverse(nd->rchild, str);
    cout<<"Node: "<<nd->key<<endl;
    (*str) += char(nd->key + 48);
}

bool isSubTree(string s1, string c1, string s2, string c2, string s3, string c3)
{
    unsigned int loc_1 = s1.find(c1, 0);
    unsigned int loc_2 = s2.find(c2, 0);
    unsigned int loc_3 = s3.find(c3, 0);
    if(loc_1 != string::npos && loc_2 != string::npos && loc_3 != string::npos) return true;
    return false;
}

int main()
{
    init();
    create_minmal_binary_tree(0, 8, -1);
    cout<<"Result: "<<contain_tree(&node[0], &node[0])<<endl;

    string s1 = "";
    pre_traverse(&node[0], &s1);
    cout<<"s1: "<<s1<<endl;

    string s2 = "";
    mid_traverse(&node[0], &s2);
    cout<<"s2: "<<s2<<endl;

    string s3 = "";
    back_traverse(&node[0], &s3);
    cout<<"s3: "<<s3<<endl;
    
    string c1 = "";
    pre_traverse(&node[1], &c1);
    cout<<"c1: "<<c1<<endl;

    string c2 = "";
    mid_traverse(&node[1], &c2);
    cout<<"c2: "<<c2<<endl;

    string c3 = "";
    back_traverse(&node[1], &c3);
    cout<<"c3: "<<c3<<endl;

    cout<<"Result: "<<isSubTree(s1, c1, s2, c2, s3, c3);

    return 0;
}
