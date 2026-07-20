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
    int fl(ListNode* h){

        int co = 0;

        while(h){
            h = h->next; co++;
        }
        return co;
    }
    ListNode* removeNthFromEnd(ListNode* h, int n) {
        
        int len = fl(h);

        if( n>len ) return h;

        int dif = len-n;
        ListNode* r = new ListNode(0);
        r->next = h;
        ListNode* cur = r;

        while(dif){
            cur = cur->next;
            dif--;
        }

        cur->next = cur->next->next;
        return r->next;
    }
};
