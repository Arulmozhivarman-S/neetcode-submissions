#include<cstring>
class Solution {
public:
    int dp[1001][1001];
    int f(int i, int j, int n, int m, string &s, string &t){
        if(j==m) return 1;
        if(i==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = 0;

        if(s[i]==t[j]){
            ans += f(i+1, j+1, n, m, s, t);
        }
        ans += f(i+1, j, n, m, s, t);
        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
       
        memset(dp, -1, sizeof(dp));
        return f(0, 0, n, m, s, t);

    }
};
