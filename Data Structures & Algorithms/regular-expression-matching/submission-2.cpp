#include<cstring> 
class Solution {
public:
    int dp[21][21];
    bool f(int i, int j, int n, int m, string &s, string &p){
        if(j==m) return i==n;

        if( dp[i][j]!=-1) return dp[i][j];

        bool match = (i<n && (s[i]==p[j] || p[j]=='.'));

        if( j+1<m && p[j+1]=='*' ){
            return f(i, j+2, n, m, s, p) || (match && f(i+1, j, n, m, s, p));
        }
        if( match ) return f(i+1, j+1, n, m, s, p);
        return false;
    }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        memset(dp, -1, sizeof(dp));
        return f(0, 0, n, m, s, p);
    }
};
