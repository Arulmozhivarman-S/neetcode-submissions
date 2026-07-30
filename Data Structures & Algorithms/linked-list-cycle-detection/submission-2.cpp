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
    bool hasCycle(ListNode* head) {
        ListNode* sl = head, *fst = head;

        while(fst && fst->next){
            sl = sl->next;
            fst = fst->next->next;
            if(sl==fst) return true;
        }
        return false;
    }
};
