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
        ListNode* rotateRight(ListNode* head, int k){
            
            if(head == nullptr || head->next == nullptr) return head;
            if(k == 0) return head;

            ListNode* first_node = head;
            ListNode* second_node = head;
            
            int list_len = 0;
            bool flag = false;
            int index = 0;

            while(index < k){
                list_len += 1;
                if(first_node->next == nullptr){
                    flag = true;
                    break;
                }

                first_node = first_node->next;
                index += 1;
            }
            //cout << "List Len: " << list_len << endl;

            if(!flag){
                while(first_node->next != nullptr){
                    first_node = first_node->next;
                    second_node = second_node->next;
                }
                ListNode* res_head = second_node->next;
                //cout << "debug: " << res_head->val << endl;
    
                first_node->next = head;
                second_node->next = nullptr;
                return res_head;
            }
            else{
                k = k % list_len;
                return rotateRight(head, k);
            }
            
        }
};

int main(){

    Solution s = Solution();

    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;

    ListNode* res = s.rotateRight(l1, 2);
    while(res != nullptr){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;

    ListNode* l6 = new ListNode(0);
    ListNode* l7 = new ListNode(1);
    ListNode* l8 = new ListNode(2);
    l6->next = l7;
    l7->next = l8;

    ListNode* res_2 = s.rotateRight(l6, 4);
    while(res_2 != nullptr){
        cout << res_2->val << " ";
        res_2 = res_2->next;
    }
    cout << endl;

    return 0;
}