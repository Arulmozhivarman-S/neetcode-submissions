#include<cstring>
class Solution {
public:
    int dp[201];
    bool f(int i, string & s, unordered_set<string> &st){

        if( i==s.size() ) return true;
        if( dp[i]!=-1 ) return dp[i];

        string cur = "";

        for(int j=i; j<s.size(); j++ ){
            cur+=s[j];
            if( st.find(cur)!=st.end() ){
                if(f(j+1, s, st)) return true;
            }
        }
        return dp[i] = false;
    }   
    bool wordBreak(string s, vector<string>& wd) {
        memset(dp, -1, sizeof(dp));
        unordered_set<string> st( wd.begin(), wd.end() );
        int n = s.size();

        return f( 0, s, st );
    }
};
