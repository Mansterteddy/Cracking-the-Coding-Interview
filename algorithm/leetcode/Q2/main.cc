#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
            ListNode* res_start = new ListNode(0);
            ListNode* l1_cur = l1;
            ListNode* l2_cur = l2;
            int next = 0;
            ListNode* cur_res = res_start;
            while(l1_cur != NULL || l2_cur != NULL){
                int x = (l1_cur != NULL) ? l1_cur->val : 0;
                int y = (l2_cur != NULL) ? l2_cur->val : 0;
                int sum = next + x + y;
                next = sum / 10;
                cur_res->next = new ListNode(sum % 10);
                cur_res = cur_res->next;
                if (l1_cur != NULL) l1_cur = l1_cur->next;
                if (l2_cur != NULL) l2_cur = l2_cur->next;
            }

            if (next > 0) {
                cur_res->next = new ListNode(next);
            }

            return res_start->next;
        }
};

void printListNode(ListNode* ptr){
    while(ptr != NULL){
        cout << ptr->val << endl;
        ptr = ptr->next;
    }
}

int main(){

    ListNode a1 = ListNode(2);
    ListNode a2 = ListNode(4);
    ListNode a3 = ListNode(3);
    a1.next = &a2;
    a2.next = &a3;

    ListNode b1 = ListNode(5);
    ListNode b2 = ListNode(6);
    ListNode b3 = ListNode(4);
    b1.next = &b2;
    b2.next = &b3;

    /*
    输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
    输出：7 -> 0 -> 8
    原因：342 + 465 = 807 
    */

    printListNode(&a1);
    printListNode(&b1);

    Solution s = Solution();
    auto res = s.addTwoNumbers(&a1, &b1);
    printListNode(res);

    return 0;
}