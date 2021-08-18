#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
    public:
        ListNode* removeElements(ListNode* head, int val){
            
            ListNode* start = head;
            
            while(start != nullptr){
                if(start->val == val) 
                    start = start->next;
                else
                    break;
            }

            if(start == nullptr) return start;

            ListNode* pre_node = start;
            ListNode* cur_node = start->next;
            while(cur_node != nullptr){
                if(cur_node->val == val){
                    pre_node->next = cur_node->next;
                    cur_node = cur_node->next;
                }
                else{
                    pre_node = cur_node;
                    cur_node = cur_node->next;
                }
            }

            return start;
        }
};


int main(){

    Solution s = Solution();

    ListNode a_1 = ListNode(1);
    ListNode a_2 = ListNode(2);
    ListNode a_3 = ListNode(6);
    ListNode a_4 = ListNode(3);
    ListNode a_5 = ListNode(4);
    ListNode a_6 = ListNode(5);
    ListNode a_7 = ListNode(6);

    a_1.next = &a_2;
    a_2.next = &a_3;
    a_3.next = &a_4;
    a_4.next = &a_5;
    a_5.next = &a_6;
    a_6.next = &a_7;

    auto a_res = s.removeElements(&a_1, 6);

    while(a_res != nullptr){
        cout << a_res->val << " ";
        a_res = a_res->next;
    }
    cout << endl;

    return 0;
}