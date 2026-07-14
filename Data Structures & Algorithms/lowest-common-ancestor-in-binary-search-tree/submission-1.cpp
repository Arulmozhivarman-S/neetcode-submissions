/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* r, TreeNode* p, TreeNode* q) {
        if( p->val>q->val ) swap(p, q);
        
        while(r){
            if( r->val>=p->val && r->val<=q->val ) return r;
            else if( r->val<p->val ) r = r->right;
            else if(r->val>q->val) r = r->left;
        }
        return nullptr;
    }
};
