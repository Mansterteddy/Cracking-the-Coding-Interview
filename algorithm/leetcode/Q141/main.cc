#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution{
    public:
        bool hasCycle(ListNode *head){
            
            if(head == nullptr) return false;

            while(true){
                if(head->next == nullptr){
                    return false;
                }
                else if(head->val == 100002){
                    return true;
                }
                else{
                    head->val = 100002;
                    head = head->next;
                }
            }

            return true;

        }
};


int main(){

    Solution s = Solution();

    ListNode *a = new ListNode(3);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(0);
    ListNode *d = new ListNode(-4);

    a->next = b;
    b->next = c;
    c->next = d;
    //d->next = b;

    auto res = s.hasCycle(a);
    cout << res << endl;

    return 0;
}