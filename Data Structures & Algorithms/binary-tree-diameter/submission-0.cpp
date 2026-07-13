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
    int dfs(TreeNode* r, int &res){

        if(!r) return 0;

        int l = dfs(r->left, res);
        int ri = dfs(r->right, res);

        res = max( res, l+ri);
        return max(l, ri)+1;
    }
    int diameterOfBinaryTree(TreeNode* r) {
        int res = 0;
        dfs(r, res);
        return res;
    }
};
