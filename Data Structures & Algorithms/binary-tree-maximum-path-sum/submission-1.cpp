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
    int f(TreeNode* r, int &ans){
        if(!r) return 0;

        int ls = max(0, f(r->left, ans));
        int rs = max(0, f(r->right, ans));

        int cur = r->val;
        ans = max( ans, cur+ls+rs);

        return cur+max(ls, rs);
    }
    int maxPathSum(TreeNode* r) {
        int ans = INT_MIN;
        f(r, ans);
        return ans;
    }
};
