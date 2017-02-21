//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 

//Tag: Insert Sort, List
#include <iostream>
#include <vector>
#include <algorithm>

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

bool less_func(ListNode*& a, ListNode*& b)
{
    return a->val < b->val;
}

class Solution
{
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists)
        {
            if(lists.size() == 0) return NULL;
            init(lists);
            if(sorted_list.size() == 0) return NULL;
            ListNode *res, *start;
            bool flag = true;

            while(sorted_list.size() != 0)
            {

                if(flag)
                {
                    flag = false;
                    res = sorted_list[0];
                    start = res;
                    sorted_list.erase(sorted_list.begin());
                    insert(res->next);
                }
                else
                {
                    ListNode* temp = sorted_list[0];
                    res->next = temp;
                    sorted_list.erase(sorted_list.begin());
                    insert(temp->next);
                    res = temp;
                }
            }

            return start;
        }

    private:
        vector<ListNode*> sorted_list;

        void init(vector<ListNode*> lists)
        {
            for(int i = 0; i < lists.size(); ++i)
            {
                if(lists[i] != NULL) sorted_list.push_back(lists[i]);
            }
            if(sorted_list.size() == 0) return;
            sort(sorted_list.begin(), sorted_list.end(), less_func);
        }

        void insert(ListNode* node)
        {
            if(node == NULL)
            {
                return;
            }
            else
            {
                int min = 0;
                int max = sorted_list.size() - 1;
                while(min <= max)
                {
                    int value = sorted_list[(min + max) / 2]->val; 
                    if(node->val > value)
                    {
                        min = (min + max) / 2 + 1;
                    }
                    else
                    {
                        max = (min + max) / 2 - 1;
                    }
                }
                int insert_index = max + 1;
                sorted_list.insert(sorted_list.begin() + insert_index, node);

                /*sorted_list.push_back(node);
                for(int i = sorted_list.size() - 1; i > 0; --i)
                {
                    if(sorted_list[i]->val > sorted_list[i - 1]->val)
                    {
                        break;
                    }
                    else
                    {
                        ListNode* temp = sorted_list[i];
                        sorted_list[i] = sorted_list[i-1];
                        sorted_list[i-1] = temp; 
                    }
                }*/

                for(int i = 0; i < sorted_list.size(); ++i)
                {
                    cout<<sorted_list[i]->val<<" ";
                }
                cout<<endl;

            }
        }

};

int main()
{
    Solution s;

    int a[] = {1, 2, 3, 5, 7};
    int len_a = sizeof(a) / sizeof(a[0]);
    int b[] = {6, 7, 8, 9, 11};
    int len_b = sizeof(b) / sizeof(b[0]);
    int c[] = {10, 12, 14, 16, 17};
    int len_c = sizeof(c) / sizeof(c[0]);
    int d[] = {11, 13, 15, 18};
    int len_d = sizeof(d) / sizeof(d[0]);

    ListNode* list_a = arrayToList(a, len_a);
    ListNode* list_b = arrayToList(b, len_b);
    ListNode* list_c = arrayToList(c, len_c);
    ListNode* list_d = arrayToList(d, len_d);

    vector<ListNode*> lists;
    lists.push_back(list_a);
    lists.push_back(list_b);
    lists.push_back(list_c);
    lists.push_back(list_d);

    ListNode* res = s.mergeKLists(lists);
    printList(res);

    return 0;
}