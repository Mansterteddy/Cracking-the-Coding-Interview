//Given a linked list, swap every two adajacent nodes and return its head. 

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
        ListNode* swapPairs(ListNode* head)
        {
            ListNode* res = head;
            ListNode* modified;
            bool flag = true;
            while(true)
            {
                if(head == NULL || head->next == NULL) break;
                else if(flag)
                {
                    flag = false;
                    res = head->next;
                    ListNode* head_next = head->next;
                    head->next = head->next->next;
                    head_next->next = head;
                    modified = head;
                }
                else
                {
                    ListNode* head_next = head->next;
                    head->next = head->next->next;
                    head_next->next = head;
                    modified->next = head_next;
                    modified = head;
                }
                head = head->next;
            }

            return res;
        }
};

int main()
{
    Solution s;

    int a[] = {1, 2, 3, 4, 5};
    int length = sizeof(a) / sizeof(a[0]);
    ListNode* start = arrayToList(a, length);

    ListNode* res = s.swapPairs(start);
    printList(res);

    return 0;
}