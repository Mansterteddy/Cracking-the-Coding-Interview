//Write code to remove duplicates from an unsorted linked list
//How would you solve this problem if a temporary buffer is not allowed?
#include <iostream>

using namespace std;

//O(n)时间复杂度：应当使用Hash Table
//O(n*n)时间复杂度：设计两个指针，根据第一个指针，去掉第二个指针指向的重复元素。

struct Node
{
    int data;
    Node *next;
};

Node* init(int a[], int n)
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

void remove_duplicate(Node *head)
{
    Node *cur = head;
    bool flag = false;
    while(cur->next != NULL)
    {
        int mark = cur->data;
        Node *now = cur->next;
        Node *prev = cur;
        
        while(now->next != NULL)
        {
            if(now->data == mark)
            {
                prev->next = now->next;
                Node *del = now;
                now = now->next;
                delete del;
            }
            else
            {
                now = now->next;
                prev = prev->next;
            }
        }
        
        if(now->data == mark)
        {
            flag = true;
        }
        
        cur = cur->next;
    }
    
    Node *cur_1 = head->next;
    Node *prev_1 = head;
    
    if(flag == true)
    {
        while(true)
        {
           if(cur_1->next == NULL)
           {
               prev_1->next = NULL;
               delete cur_1;
               break;
           }
           else
           {
                cur_1 =cur_1->next;
                prev_1 = prev_1->next;   
           }
        }
    }
    
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

int main()
{
    int n = 10;
    int a[] = {9, 2, 1, 3, 5, 6, 2, 6, 3, 1};
    
    Node *head = init(a, n);
    print(head);
    
    remove_duplicate(head);
    
    print(head);
    
    return 0;
        
}