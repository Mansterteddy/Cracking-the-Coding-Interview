//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
}; 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) return NULL;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *start, *pre;
        int count = 0;
        int next = 0;
        while(!(l1 == NULL && l2 == NULL && next == 0 ))
        {
            cout<<"next: "<<next<<endl;
            int sum;
            if(l1 != NULL && l2 != NULL)
            {
                sum = l1->val + l2->val + next;
            }
            else if(l1 != NULL && l2 == NULL)
            {
                sum = l1->val + next;
            }
            else if(l1 == NULL && l2 != NULL)
            {
                sum = l2->val + next;
            }
            else
            {
                sum = next;
            }

            cout<<"sum: "<<sum<<endl;
            if(sum >= 10)
            {
                next = 1;
                sum = sum - 10;
            }
            else
            {
                next = 0;
            }

            ListNode* cur = new ListNode(sum);

            if(count == 0)
            {
                start = cur;
                pre = cur;
            }
            else
            {
                pre->next = cur;
                pre = pre->next;
            }

            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;;
            count++;
            cout<<"count: "<<count<<endl;
        }
        return start;
    }
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

int main()
{
    int a[] = {0};
    int b[] = {8};

    int length_a = sizeof(a) / sizeof(a[0]);
    int length_b = sizeof(b) / sizeof(b[0]);

    ListNode* list_a = arrayToList(a, length_a);
    ListNode* list_b = arrayToList(b, length_b);

    printList(list_a);
    printList(list_b);
    
    Solution s1;
    ListNode* res = s1.addTwoNumbers(list_a, list_b);
    printList(res);

    return 0;
}