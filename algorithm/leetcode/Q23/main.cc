#include <vector>
#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(NULL){}
    ListNode(int x): val(x), next(NULL){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};

class Solution {
public:

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1){
            cur->next = l1;
        }
        if(l2){
            cur->next = l2;
        }
        return head->next;
    }

    ListNode* mergeSort(vector<ListNode*>& lists, int left, int right){
        if(left == right){
            return lists[left];
        }

        if(right - left == 1){
            return mergeTwoLists(lists[left], lists[right]);
        }

        int mid = (left + right) / 2;
        ListNode* l1 = mergeSort(lists, left, mid);
        ListNode* l2 = mergeSort(lists, mid + 1, right);
        return mergeTwoLists(l1, l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];

        int lists_size = lists.size();
        return mergeSort(lists, 0, lists_size - 1);
    }
};

int main()
{
    Solution s = Solution();

    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(4);
    ListNode* l3 = new ListNode(5);

    ListNode* l4 = new ListNode(1);
    ListNode* l5 = new ListNode(3);
    ListNode* l6 = new ListNode(4);

    ListNode* l7 = new ListNode(2);
    ListNode* l8 = new ListNode(6);

    l1->next = l2;
    l2->next = l3;

    l4->next = l5;
    l5->next = l6;

    l7->next = l8;

    vector<ListNode*> lists;
    lists.push_back(l1);
    lists.push_back(l4);
    lists.push_back(l7);

    ListNode* res = s.mergeKLists(lists);
    while (res != NULL) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

    return 0;
}

