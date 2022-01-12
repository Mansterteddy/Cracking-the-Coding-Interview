#include <vector>
#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};

class Solution{
    public:

        pair<ListNode*, ListNode*> rearrage(ListNode* head, int k){
            vector<ListNode*> vec;

            int count = 0;
            while(head != nullptr && count < k){
                vec.push_back(head);
                head = head->next;
                count++;                
            }

            if(count < k) return make_pair(nullptr, nullptr);

            vec[0]->next = vec[k-1]->next;
            for(int i = k - 1; i > 0; i--){
                vec[i]->next = vec[i-1];
            }

            return make_pair(vec[k-1], vec[0]);

        }

        ListNode* reverseKGroup(ListNode* head, int k){

            if(head == nullptr || head->next == nullptr || k == 1) return head;

            auto first_pair = rearrage(head, k);
            ListNode* start = first_pair.first;
            ListNode* end = first_pair.second;

            if(start == nullptr) return head;

            while(true){
                auto next_pair = rearrage(end->next, k);
                if(next_pair.first == nullptr) break;
                end->next = next_pair.first;
                end = next_pair.second;
            }

            return start;
        }
};

int main(){

    Solution s = Solution();

    ListNode* node_1 = new ListNode(1);
    ListNode* node_2 = new ListNode(2);
    ListNode* node_3 = new ListNode(3);
    ListNode* node_4 = new ListNode(4);
    ListNode* node_5 = new ListNode(5);

    node_1->next = node_2;
    node_2->next = node_3;
    node_3->next = node_4;
    node_4->next = node_5;

    ListNode* res = s.reverseKGroup(node_1, 2);
    while(res != nullptr){
        cout << res->val << endl;
        res = res->next;
    }

    return 0;
}