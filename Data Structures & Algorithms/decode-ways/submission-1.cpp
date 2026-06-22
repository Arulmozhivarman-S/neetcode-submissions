#include<cstring>
class Solution {
public:
    int dp[101][27];

    int f(int i, int v, int n, string s){
        if(i==n) return v>0;

        int ans = 0;
        if(dp[i][v]!=-1) return dp[i][v];

        int d = s[i]-'0';
        int nv = v*10+d;
        if((v==0 && d==0) || (nv>26)) return 0;
        
        ans += f(i+1, nv, n, s);
        if(nv>0) ans += f(i+1, 0, n, s);
        return dp[i][v] = ans;
    }
    int numDecodings(string s) {
        int n = s.size();
        if(s[0]=='0') return 0;
        memset(dp, -1, sizeof(dp));
        return f(0, 0, n, s);
    }
};
