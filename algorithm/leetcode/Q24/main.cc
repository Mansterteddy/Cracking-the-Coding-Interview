#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution{
    public:
        ListNode* swapPairs(ListNode* head){
            if(head == nullptr) return head;
            if(head->next == nullptr) return head;

            ListNode* first_node = head;
            ListNode* second_node = head->next;
            ListNode* new_start_node = second_node;
            ListNode* last_node = nullptr;

            while(second_node != nullptr){
                cout << "first node: " << first_node->val << " second node: " << second_node->val << endl;
                if(last_node != nullptr) cout << "Last ndoe: " << last_node->val << endl;
                ListNode* future_node = second_node->next;
                second_node->next = first_node;
                first_node->next = future_node;

                if(last_node == nullptr)
                    last_node = first_node;
                else{
                    last_node->next = second_node;
                    last_node = first_node;
                }
                
                if(future_node == nullptr) break;

                first_node = future_node;
                second_node = future_node->next;

            }

            return new_start_node;
        }
};

int main(){

    Solution s = Solution();

    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(5);
    //ListNode* f = new ListNode(6);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    //e->next = f;

    auto new_start = s.swapPairs(a);

    while(new_start != nullptr){
        cout << new_start->val << endl;
        new_start = new_start->next;
    }


    return 0;
}