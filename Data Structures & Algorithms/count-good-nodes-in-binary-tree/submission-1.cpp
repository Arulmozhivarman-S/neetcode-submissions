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
    void f(TreeNode* r, int mx, int &ans){
        if(!r) return ;

        if(r->val>=mx){
            mx = r->val;
            ans++;
        }
        f(r->left, mx, ans);
        f(r->right, mx, ans);
    }
    int goodNodes(TreeNode* r) {
        
        int ans = 0;

        f(r, INT_MIN, ans);
        return ans;
    }
};
