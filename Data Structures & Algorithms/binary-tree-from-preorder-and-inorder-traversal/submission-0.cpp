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
    int preIndx = 0, inIndx = 0;

    TreeNode* f(vector<int>& preorder, vector<int>& inorder, int limit){
        if( preIndx==preorder.size() ) return nullptr;

        if( inorder[inIndx]==limit ) {
            inIndx++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preIndx++]);
        root->left  = f(preorder, inorder, root->val);
        root->right = f(preorder, inorder, limit);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return f(preorder, inorder, INT_MAX);
    }
};
