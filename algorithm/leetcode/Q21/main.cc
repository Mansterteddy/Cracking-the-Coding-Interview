#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode *cur_node = new ListNode(0);
        ListNode *res_start = cur_node;

        while(l1 != nullptr || l2 != nullptr){
            if(l1 == nullptr){
                ListNode* next_node = new ListNode(l2->val);
                cur_node->next = next_node;
                l2 = l2->next;
            }
            else if(l2 == nullptr){
                ListNode* next_node = new ListNode(l1->val);
                cur_node->next = next_node;
                l1 = l1->next;
            }
            else{
                if(l1->val <= l2->val){
                    ListNode* next_node = new ListNode(l1->val);
                    cur_node->next = next_node;                
                    l1 = l1->next;
                }
                else{
                    ListNode* next_node = new ListNode(l2->val);
                    cur_node->next = next_node;                
                    l2 = l2->next;
                }
            }

            cur_node = cur_node->next;
        }

        return res_start->next;

    }
};

int main(){
    
    Solution s = Solution();

    ListNode* a_1 = new ListNode(4);
    ListNode* a_2 = new ListNode(2, a_1);
    ListNode* a_3 = new ListNode(1, a_2);

    ListNode* b_1 = new ListNode(4);
    ListNode* b_2 = new ListNode(3, b_1);
    ListNode* b_3 = new ListNode(1, b_2);

    ListNode* res = s.mergeTwoLists(a_3, b_3);
    while(res != nullptr){
        cout << res->val << endl;
        res = res->next;
    }

    return 0;
}