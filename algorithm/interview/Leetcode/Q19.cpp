//Given a linked list, remove the n^th node from the end of list and return its head 


//Tag: Double pointer
//选择两个不同时间出发的指针

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* arrayToList(int* arr, int length)
{
    if(length == 0) return NULL;
    ListNode *start, *pre;

    for(int i = 0; i < length; ++i)
    {
        ListNode* cur = new ListNode(arr[i]);
        if(i == 0)
        {
            start = cur;
            pre = cur;
            continue;
        }
        pre->next = cur;
        pre = pre->next;
    }

    return start;
}

void printList(ListNode* start)
{
    while(start != NULL)
    {
        cout<<start->val<<" ";
        start = start->next;
    }
    cout<<endl;
}

class Solution
{
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n)
        {
            if(n == 0) return NULL;
            ListNode *p_1, *p_2;
            p_1 = head;
            p_2 = head;
            for(int i = 0; i < n; ++i) 
            {
                p_1 = p_1->next;
                if(p_1 == NULL) 
                {
                    head = head->next;
                    return head;
                }
            }
            
            /*if(p_1->next == NULL)
            {
                cout<<"oh"<<endl;
                head = head->next;
                return head;
            }*/

            while(p_1->next != NULL)
            {
                p_1 = p_1->next;
                p_2 = p_2->next;
            }

            p_2->next = p_2->next->next;

            return head;
        }
};

int main()
{
    Solution s;

    int a[] = {1};
    int length = sizeof(a) / sizeof(a[0]);
    ListNode* start = arrayToList(a, length);
    printList(start);

    ListNode* res = s.removeNthFromEnd(start, 0);
    printList(res);

    return 0;
}