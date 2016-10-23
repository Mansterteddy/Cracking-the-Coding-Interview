#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <map>

using namespace std;

struct Node
{
    char key;
    int value;
    string rep;
    Node *lchild, *rchild;
};

bool cmp(Node* a1, Node* a2)
{
    return (a1->value > a2->value);
}

void DFS(Node *parent)
{
    //cout<<"Node"<<parent->rep<<endl;
    if(parent->lchild == NULL && parent->rchild == NULL)
    {
        cout<<parent->rep<<endl;
        return;
    } 
    if(parent->lchild != NULL)
    {
        //cout<<"Lchild: "<<parent->rep<<" | "<<parent->lchild->rep<<endl;
        parent->lchild->rep = parent->rep + parent->lchild->rep;
        DFS(parent->lchild);
    }
    if(parent->rchild != NULL)
    {
        //cout<<"Rchild: "<<parent->rep<<" | "<<parent->rchild->rep<<endl; 
        parent->rchild->rep = parent->rep + parent->rchild->rep;
        DFS(parent->rchild);
    }
}

map<char, string> get_hash(Node *start)
{
    map<char, string> m1;
    list<Node*> li;
    li.push_back(start);
    while(!li.empty())
    {
        Node* n = li.front();
        li.pop_front();
        if(n->lchild != NULL) li.push_back(n->lchild);
        if(n->rchild != NULL) li.push_back(n->rchild);
        if(n->lchild == NULL && n->rchild == NULL)
        {
            m1[n->key] = n->rep;
        }
    }
    return m1;
}

void encode(char *a)
{
    map<char, int> m1;
    for(int i = 0; a[i] != '\0'; i++)
    {
        if(m1[a[i]] == 0)
        {
            m1[a[i]] = 1;
        }
        else
        {
            m1[a[i]]++;
        }
    } 
    map<char, int>::iterator mi;
    vector<Node*> v1;
    for(mi = m1.begin(); mi != m1.end(); mi++)
    {
        Node* p = new Node();
        p->key = mi->first;
        p->value = mi->second;
        p->rep = "";
        p->lchild = NULL;
        p->rchild = NULL;
        v1.push_back(p);
    }

    sort(v1.begin(), v1.end(), cmp);

    while(v1.size() != 1)
    {
        Node* n1 = v1.back();
        n1->rep = "0";
        v1.pop_back();

        Node* n2 = v1.back();
        n2->rep = "1";
        v1.pop_back();

        Node* n_parent = new Node();
        n_parent->key = NULL;
        n_parent->rep = "";
        n_parent->value = n1->value + n2->value;
        n_parent->lchild = n1;
        n_parent->rchild = n2;

        v1.push_back(n_parent);
        sort(v1.begin(), v1.end(), cmp);
    }

    DFS(v1[0]);
    map<char, string> m2 = get_hash(v1[0]);

    map<char, string>::iterator mi_2;
    for(mi_2 = m2.begin(); mi_2 != m2.end(); mi_2++)
    {
        cout<<mi_2->first<<" "<<mi_2->second<<endl;
    }

    for(int i = 0; a[i] != '\0'; i++)
    {
        cout<<m2[a[i]];
    }
    cout<<endl;
}

int main()
{
    char a[] = "aaabbcccd";
    encode(a);
    return 0;
}