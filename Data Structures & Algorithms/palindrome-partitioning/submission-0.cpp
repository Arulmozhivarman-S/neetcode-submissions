class Solution {
public:
    vector<vector<string>> ans;
    bool ch(string &s){
        int i=0, j = s.size()-1;

        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++, j--;
        }
        return true;
    }
    void f(int i, string t, string &s, int n, vector<string> &cur){
        
        if(i==n){
            if(t=="") ans.push_back(cur); 
            return;
        }


        for(int j=i; j<n; j++){
            t+=s[j];
            if(ch(t)) {
                cur.push_back(t);
                f(j+1, "", s, n, cur);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        ans = {};
        vector<string> cur;
        f(0, "", s, n, cur);
        return ans;
    }
};
