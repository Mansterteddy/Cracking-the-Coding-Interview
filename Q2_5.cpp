//Given a circular linked list, implement an algorithm which returns node at the beginning of the loop
//DEFINITION
//Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so as to make a loop in the linked list.
//EXAMPLE:
//Input: A->B->C->D->E->C [the same C as earlier]
//Output: C
#include <iostream>
#include <map>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *init(int a[], int n, int m)
{
    Node *head;
    Node *p;
    Node *mark;
    for(int i = 0; i < n; i++)
    {
        Node *nd = new Node();
        nd->data = a[i];
        if(i == 0)
        {
            head = nd;
            p = nd;
        }
        if(i == m - 1)
        {
            mark = nd;
        }
        p->next = nd;
        p = p->next;
        if(i == n - 1)
        {
            nd->next = mark;
        }
    }
    
    return head;
    
}

void print(Node *head)
{
    int n = 20;
    while(n)
    {
        cout<<head->data<<" ";
        head = head->next;
        n--;
    }
    cout<<endl;
}

/*
这道题是个非常有趣的题目 有一个很漂亮的解法 我在做这道题时 发现两个思维的盲区
1、指针的速度，指针是可以有快慢之分的，来自于人为的定义，速度可以不同，甚至可以控制速度的比例
2、计算得到的性质或者规律是有用的，要学会在以往状态的基础上利用性质
实现设置速度为1：2的两个指针，那么在这个循环链表中，指针总会相遇
a = x + n * y + c; a / 2 = x + m * y + c;
a是快指针走的路程，a / 2是慢指针的路程
最终得到结论 x + c = p * y;
也就是x + c是y的整数倍
那么当前停留的点我们可以认为是：x + n * y + c;进一步 x + c;
那么此时停留的点再走x步就回到了循环开始的起点
如果此时起点出发一个相同速度的指针，那么走x步后也到了循环开始的起点
那么此时会发生事件：两个指针指向的内容相同
那么此时这个点就是我们要返回的点
NOTE：快慢指针相遇的点 不一定是循环开始的起点
*/
Node *find_start(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    
    while(fast->data == slow->data)
    {
        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
    }
    
    fast = head;
    while(fast->data == slow->data)
    {
        fast = fast->next;
        slow = slow->next;
    }
    
    return slow;
    
}

map<Node*, bool> hash_1;

Node *find_start_1(Node *head)
{
    while(head)
    {
        if(hash_1[head]) return head;
        else
        {
            hash_1[head] = true;
            head = head->next;
        }
    }
    
    return head;
}


int main()
{
    int a[] = {0, 1, 2, 3, 4};
    int length = sizeof(a) / sizeof(a[0]);
    int entr = 2;
    
    Node *head = init(a, length, entr);
    print(head);
    
    Node *start = find_start_1(head);
    print(start);
    
    Node *start_1 = find_start(head);
    print(start);
    
    return 0;
}