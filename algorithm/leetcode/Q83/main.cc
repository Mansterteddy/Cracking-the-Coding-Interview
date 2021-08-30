#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        auto cur_node = head;
        auto next_node = head->next;

        while(true){
            
            while(next_node != nullptr && cur_node->val == next_node->val){
                next_node = next_node->next;
            }
            
            if(next_node == nullptr){
                cur_node->next = next_node;
                break;
            }
            else{
                cur_node->next = next_node;
                cur_node = next_node;
                next_node = next_node->next;
            }

        }

        return head;
    }
};

int main(){

    Solution s = Solution();

    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(1);
    ListNode* c = new ListNode(2);
    ListNode* d = new ListNode(3);
    ListNode* e = new ListNode(3);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    ListNode* res = s.deleteDuplicates(a);

    while(res != nullptr){
        cout << res->val << " ";
        res = res->next;
    }

    return 0;
}