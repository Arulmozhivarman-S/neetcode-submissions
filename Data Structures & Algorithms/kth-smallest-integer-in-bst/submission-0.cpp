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
    int f(TreeNode* r, vector<int>& s){
        if(!r) return 0;

        f(r->left, s);
        s.push_back(r->val);
        f(r->right, s);
        return 0;
    }
    int kthSmallest(TreeNode* r, int k) {
        vector<int> s;
        f(r, s);
        for(int i:s) cout<<i<<" ";
        return s[k-1];
    }
};
