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
    pair<int, int> f(TreeNode* r){
        if(!r) return {0, 0};

        auto l = f(r->left);
        auto ri = f(r->right);
        
        int ans = r->val + l.second + ri.second;

        return { ans, max(l.first, l.second)+ max(ri.first, ri.second) };
    }
    int rob(TreeNode* r) {
        auto t = f(r);
        return max(t.first, t.second);
    }
};