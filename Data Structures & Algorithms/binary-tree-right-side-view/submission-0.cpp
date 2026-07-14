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
    vector<int> rightSideView(TreeNode* r) {
        if(!r) return {};
        vector<int> ans;

        queue<TreeNode*> q;
        q.push(r);

        while(!q.empty()){
            int n = q.size(), val = 0;

            while(n--){

                auto t = q.front(); q.pop();
                val = t->val;

                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            ans.push_back(val);
        }
        return ans;
    }
};
