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
    int f(TreeNode* r, bool &fl){

        if(!r) return 0;

        int l = f(r->left, fl);
        int ri = f(r->right, fl);

        if( abs(l-ri)>1 ){
            fl = false; return 0;
        }
        return max(l, ri)+1;
    }
    bool isBalanced(TreeNode* r) {
        bool fl = true;
        f(r, fl);
        return fl;
    }
};
