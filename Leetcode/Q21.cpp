//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists. 
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
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
        {
            ListNode *start, *cur;
            if(l1 == NULL) return l2;
            if(l2 == NULL) return l1;
            
            if(l1->val < l2->val)
            {
                start = l1;
                l1 = l1->next;
            }
            else
            {
                start = l2;
                l2 = l2->next;
            }

            cur = start;

            while(l1 != NULL && l2 != NULL)
            {
                if(l1->val > l2->val)
                {
                    cur->next = l2;
                    l2 = l2->next;
                    cur = cur->next;
                }
                else
                {
                    cur->next = l1;
                    l1 = l1->next;
                    cur = cur->next;
                }
            }

            if(l1 != NULL)
            {
                cur->next = l1;
            }
            else if(l2 != NULL)
            {
                cur->next = l2;
            }

            return start;
        }
};

int main()
{
    int a[] = {1, 3, 5, 7, 9, 11};
    int b[] = {0, 2, 4, 6, 8, 10};

    int length_a = sizeof(a) / sizeof(a[0]);
    int length_b = sizeof(b) / sizeof(b[0]);

    ListNode* start_a = arrayToList(a, length_a);
    ListNode* start_b = arrayToList(b, length_b);

    Solution s1;
    ListNode* ans = s1.mergeTwoLists(start_a, start_b);
    printList(ans);

    return 0;
}