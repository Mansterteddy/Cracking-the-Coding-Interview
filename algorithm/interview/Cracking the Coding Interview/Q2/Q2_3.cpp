//Implement an algorithm to delete a node in the middle of single linked list, given only access to that node.
//Example: Input: the node 'c' from the linked list a->b->c->d->e Result: nothing is returned, but the new linked list looks like a->b->d->e

//给定list中某一个指针，删除掉这个指针指向的元素，但是没有前一个元素的指针
//可以考虑将这个指针指向的元素 换成下一个元素的内容 然后删除下一个元素 但是看起来 和要求相同
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *init(int a[], int n)
{
    Node *head;
    Node *prev;
    
    for(int i = 0; i < n; i++)
    {
        Node *nd = new Node();
        nd->data = a[i];
        if(i == 0)
        {
            head = nd;
            prev = nd;
        }
        prev->next = nd;
        prev = prev->next;
    }
    
    return head;
}

void print(Node *head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

//分为四种情况：1、头结点；2、中间结点；3、尾结点；4、为空。需要特殊处理尾结点
//如果直接删除尾结点，在最后重新打印链表时会出现问题，可以使用一些特殊处理，比如将尾结点的元素设置为特殊值 然后打印时判断是否打印
bool remove(Node *cur)
{
    if(cur == NULL) return 0;
    if(cur->next == NULL) return 0;
    
    Node *q = cur->next;
    cur->data = q->data;
    cur->next = q->next;
    delete q;
    
    return 1;
    
}

int main()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(a) / sizeof(a[0]);
    Node *head = init(a, length);
    print(head);
    
    int cc = 4;
    Node *c =head;
    for(int i = 1; i < cc; i++) c = c->next;
    print(c);
    
    if(remove(c))
    {
        print(head);
    }
    else
    {
        cout<<"Bad Cases!"<<endl;
    }
    
    return 0;
}