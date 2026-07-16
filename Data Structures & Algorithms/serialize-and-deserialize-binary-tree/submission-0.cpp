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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "null";
        string s = "";

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto t = q.front(); q.pop();
            if( t!=nullptr ){
                s += (to_string(t->val)+",");
                q.push(t->left);
                q.push(t->right);
            }
            else s+="null,";
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if(s=="null") return nullptr;
        stringstream ss(s);

        string token;

        getline(ss , token, ',');

        TreeNode* r = new TreeNode(stoi(token));
        queue<TreeNode*> q;
        q.push(r);
        
        while(!q.empty()){
            TreeNode* cur = q.front(); q.pop();

            if(!getline(ss, token, ',')) break;

            if(token!="null"){
                cur->left = new TreeNode(stoi(token));
                q.push(cur->left);
            }

            if(!getline(ss, token, ',')) break;
            
            if(token!="null"){
                cur->right = new TreeNode(stoi(token));
                q.push(cur->right);
            }

        }
        return r;
    }
};
