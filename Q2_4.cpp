//You have two numbers represented by a linked list, where each node contains a single digit. 
//The digits are stored in reverse order, such that the 1's digit is at the head of the list.
//Write a function that adds the two numbers and returns the sum as a linked list.
//Example:
//Input: (3->1->5), (5->9->2)
//Output: 8->0->8

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node *init(int a[], int n)
{
    Node *head;
    Node *pre;
    for(int i = 0; i < n; i++)
    {
        Node *nd = new Node();
        nd->data = a[i];
        if(i == 0)
        {
            head = nd;
            pre = nd;
        }
        pre->next = nd;
        pre = pre->next;
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

Node *add(Node *head_1, int length_1, Node *head_2, int length_2)
{
    int length = 0;
    if(length_1 > length_2)
    {
        length = length_1;
    }
    else
    {
        length = length_2;
    }
    
    int flag = 0;
    
    Node *res_head = new Node();
    Node *prev = new Node();
  
    for(int i = 0; i < length; i++)
    {
        Node *nd = new Node();
        int temp = 0;
        if(head_1 && head_2)
        {
            temp = head_1->data + head_2->data + flag;
        }
        else if(head_2 == NULL)
        {
            temp = head_1->data + flag;
        }
        else
        {
            temp = head_2->data + flag;    
        }

        int temp_res = temp % 10;
        nd->data = temp_res;
        
        flag = temp / 10;
        
        if(i == 0)
        {
            res_head = nd;
            prev = nd;
        }
        
        prev->next = nd;
        prev = prev->next;
        
        if(head_1 != NULL)
        {
            head_1 = head_1->next;
        }
        
        if(head_2 != NULL)
        {
            head_2 = head_2->next;
        }

        cout<<"Value: "<<temp_res<<endl;
    }
    
    if(flag == 1)
    {
        Node *nd_final = new Node();
        nd_final->data = 1;
        nd_final->next = NULL;
        prev->next = nd_final;
    }
    
    return res_head;
}

int main()
{
    int a_1[] = {3, 1, 5, 3, 4};
    int length_1 = sizeof(a_1) / sizeof(a_1[0]);
    Node *head_1 = init(a_1, length_1);
    print(head_1);
    
    int a_2[] = {5, 9, 5};
    int length_2 = sizeof(a_2) / sizeof(a_2[0]);
    Node *head_2 = init(a_2, length_2);
    print(head_2);
    
    Node *head_3 = add(head_1, length_1, head_2, length_2);
    print(head_3);
    
    return 1;
}