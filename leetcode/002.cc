#include <iostream>

using namespace std;

// Definition for singly-linked list

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution{
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

void printLinkNode(ListNode* a){
    while(a != NULL){
        cout << a->val << endl;
        a = a->next;
    }
}

int main(){
    cout << "LeetCode 002" << endl;

    ListNode a_1 = ListNode(2);
    ListNode a_2 = ListNode(4);
    ListNode a_3 = ListNode(3);
    a_1.next = &a_2;
    a_2.next = &a_3;

    printLinkNode(&a_1);

    ListNode b_1 = ListNode(5);
    ListNode b_2 = ListNode(6);
    ListNode b_3 = ListNode(4);
    b_1.next = &b_2;
    b_2.next = &b_3;

    printLinkNode(&b_1);

    Solution so = Solution();

    ListNode* res = so.addTwoNumbers(&a_1, &b_1);
    printLinkNode(res);

    return 0;
}