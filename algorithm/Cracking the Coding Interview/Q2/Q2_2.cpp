//Implement an algorithm to find the nth to last element of a singly linked list
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *init(int a[], int n)
{
    Node *head, *p;
    for(int i = 0; i < n; i++)
    {
        Node *nd = new Node();
        nd->data = a[i];
        if(i == 0)
        {
            head = p = nd;
            continue;
        }
        p->next = nd;
        p = nd;
    }
    
    return head;   
}

Node *find_nth(Node *head, int n)
{
    Node *cur = head;
    int length = 0;
    while(cur)
    {
        length++;
        cur = cur->next;
    }    
    cout<<"Length: "<<length<<endl;
    
    int start = 0;
    cur = head;
    while(start != length - n)
    {
        cur = cur->next;
        start++;
    }
    
    cout<<"Cur: "<<cur->data<<endl;
    
    return cur;
}

Node *final = NULL;
//也可以通过栈来实现，先入栈，然后一个一个pop，直到第n个
int find_nth_1(Node *head, int n)
{
    if(head->next == NULL)
    {
        return 1;
    }
    
    int res = find_nth_1(head->next, n) + 1;
    
    if(res == n)
    {
        final = head; 
    }
    
    return res;
}

//最巧的办法是维护两个指针，第一个指针先出发，另一个在n步后出发，当第一个指针抵达终点时，第二个指针正好到达倒数第n个位置
Node* find_nth_2(Node *head, int n)
{
    Node *p;
    Node *q;
    
    p = head;
    for(int i = 0; i < n; i++)
    {
        p = p->next;
    }
    q = head;
    
    while(p)
    {
        p = p->next;
        q = q->next;
    }
    
    return q;
}


void print(Node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}


int main()
{
    int a[] = {1, 2, 4, 3, 6, 14, 8, 7, 9, 0};
    int length = sizeof(a) / sizeof(a[0]);
    Node *head = init(a, length);
    print(head);
    find_nth(head, 6);
    find_nth_1(head, 6);
    cout<<"Final: "<<final->data<<endl;
    Node *res = find_nth_2(head, 6);
    cout<<"Final 1: "<<res->data<<endl;
    return 0;
}
