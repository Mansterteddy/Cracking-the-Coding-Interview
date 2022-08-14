#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {} 
};

class Solution{
    public:
        ListNode* reverseBetween(ListNode* head, int left, int right){

            if(left == right) return head;

            if(left == 1){
                
                ListNode* new_head;
                ListNode* prev_node;
                ListNode* next_node;
                ListNode* cur_node = head;

                for(int i = 0; i < right; ++i){ 
                    if(i == 0){
                        next_node = cur_node->next;
                        prev_node = cur_node;
                        cur_node = next_node;
                    }
                    else if(i == right - 1){
                        next_node = cur_node->next;
                        head->next = next_node;
                        cur_node->next = prev_node;
                        new_head = cur_node;
                    }
                    else{
                        next_node = cur_node->next;
                        cur_node->next = prev_node;
                        prev_node = cur_node;
                        cur_node = next_node;
                    }
                }

                return new_head;
            }

            ListNode* start_node = head;
            ListNode* prev_start_node;

            for(int i = 0; i < left - 1; ++i){
                prev_start_node = start_node;
                start_node = start_node->next;
            }

            ListNode* new_head;
            ListNode* prev_node;
            ListNode* next_node;
            ListNode* cur_node = start_node;

            for(int i = left - 1; i < right; ++i){
                if(i == left - 1){
                    next_node = cur_node->next;
                    prev_node = cur_node;
                    cur_node = next_node;
                }
                else if(i == right - 1){
                    next_node = cur_node->next;
                    start_node->next = next_node;
                    cur_node->next = prev_node;
                    new_head = cur_node;
                }
                else{
                    next_node = cur_node->next;
                    cur_node->next = prev_node;
                    prev_node = cur_node;
                    cur_node = next_node;
                }
            }
            
            prev_start_node->next = new_head;

            return head;

        }
};

int main(){

    Solution s = Solution();

    ListNode* l5 = new ListNode(5);
    ListNode* l4 = new ListNode(4, l5);
    ListNode* l3 = new ListNode(3, l4);
    ListNode* l2 = new ListNode(2, l3);
    ListNode* l1 = new ListNode(1, l2);

    auto res = s.reverseBetween(l1, 2, 5);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }

    return 0;
}