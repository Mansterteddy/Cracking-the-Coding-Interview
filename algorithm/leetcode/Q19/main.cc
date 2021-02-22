#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution{
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n){
            ListNode* first_ptr = head;
            ListNode* second_ptr = head;

            for(int i = 0; i < n; ++i){
                first_ptr = first_ptr->next;
            }

            if(first_ptr == nullptr){
                head = head->next;
                return head;
            }

            //cout << first_ptr->val << endl;

            while(first_ptr->next != nullptr){
                first_ptr = first_ptr->next;
                second_ptr = second_ptr->next;
            }

            //cout << second_ptr->val << endl;

            if(second_ptr->next == nullptr){
                return head;
            }
            else{
                ListNode* next_ptr = second_ptr->next->next;
                second_ptr->next = next_ptr;
                return head;
            }


        }
};

int main(){

    Solution s = Solution();

    ListNode* l_1 = new ListNode(1);
    ListNode* l_2 = new ListNode(2);
    l_1->next = l_2;
    ListNode* l_3 = new ListNode(3);
    l_2->next = l_3;
    ListNode* l_4 = new ListNode(4);
    l_3->next = l_4;
    ListNode* l_5 = new ListNode(5);
    l_4->next = l_5;

    ListNode* cur_ptr = l_1;
    while(cur_ptr != nullptr){
        cout << cur_ptr->val << " ";
        cur_ptr = cur_ptr->next;
    }
    cout << endl;

    ListNode* new_ptr = l_1;
    ListNode* res = s.removeNthFromEnd(new_ptr, 2);

    while(res != nullptr){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

    return 0;
}