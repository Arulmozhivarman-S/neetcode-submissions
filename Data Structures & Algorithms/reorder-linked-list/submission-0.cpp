/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<int> val;

        ListNode* t = head;

        while(t){
            val.push_back(t->val);
            t = t -> next;
        }

        int i = 0, j = val.size()-1, fl = 0;

        while(head){
            if(!fl){
                head->val = val[i++];
            }
            else  head->val = val[j--];
            head = head->next;
            fl ^= 1;
        }

    }
};
