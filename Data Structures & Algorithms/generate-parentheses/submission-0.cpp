class Solution {
public:
    void f(string cur, int op, int cl, int n, vector<string> &ans){
        if(op>n || cl>n) return;
        if(op==n && cl==n){
            ans.push_back(cur); return;
        }

        f(cur+"(", op+1, cl, n, ans);
        if(op>cl) f(cur+")", op, cl+1, n, ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        f("", 0, 0, n, ans);
        return ans;
    }
};
