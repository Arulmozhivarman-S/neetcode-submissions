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
    bool f(TreeNode* r, long l, long ri){
        if(!r) return true;

        if(!( l<r->val && r->val<ri ) ) return false;

        return f(r->left, l, r->val) && f(r->right, r->val, ri);
    }
    bool isValidBST(TreeNode* r) {
        return f(r, LONG_MIN, LONG_MAX);
    }
};
