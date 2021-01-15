//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list. 

//Tag: vector
#include <iostream>
#include <vector>

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
        ListNode* reverseKGroup(ListNode* head, int k)
        {
            if(head == NULL) return NULL;
            ListNode* start = head;
            ListNode* next_node = head;
            ListNode* modified_node;
            vector<ListNode*> vec(k);
            bool flag = true;
            bool start_flag = true;

            while(true)
            {
                for(int i = 0; i < k; ++i)
                {
                    if(next_node != NULL)
                    {
                        vec[i] = next_node;
                        next_node = next_node->next;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                if(!flag) break;
                if(start_flag)
                {
                    start = vec[k-1];
                    start_flag = false;
                }
                else
                {
                    modified_node->next = vec[k-1];
                }
                reverse(vec);

                modified_node = vec[0];
            }

            return start;
        }
    private:
        void reverse(vector<ListNode*> vec)
        {
            vec[0]->next = vec[vec.size() - 1]->next;
            for(int i = 1; i < vec.size(); ++i)
            {
                vec[i]->next = vec[i-1];
            }
        }
};

int main()
{
    Solution s;

    //int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int a[] = {1};
    int length = sizeof(a) / sizeof(a[0]);
    ListNode* start = arrayToList(a, length);
    ListNode* res = s.reverseKGroup(start, 3);
    printList(res);

    return 0;
}