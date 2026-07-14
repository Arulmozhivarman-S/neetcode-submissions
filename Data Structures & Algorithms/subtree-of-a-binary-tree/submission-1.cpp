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
    bool ch(TreeNode* r, TreeNode* sr){
        if(!r && !sr) return true;
        if( !r || !sr || r->val!=sr->val) return false;

        if(!ch(r->left, sr->left)) return false;
        if(!ch(r->right, sr->right)) return false;
        return true;
    }
    bool f(TreeNode* r, TreeNode* sr){
        if(!r || !sr) return false;

        if( r->val==sr->val ){
            if(ch(r, sr)) return true;
        }
        if(f(r->left, sr)) return true;
        if(f(r->right, sr)) return true;
        return false;
    }
    bool isSubtree(TreeNode* r, TreeNode* sr) {
        return f(r, sr);
    }
};
