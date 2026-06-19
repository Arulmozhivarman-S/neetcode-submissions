#include <cstring>
class Solution {
public:
    long long dp[30000][2];
    int f(int i, bool fl, int n, vector<int>& p){
        if(i==n) {
            if(fl) return 0;
            return -1e9;
        }
        if(dp[i][fl]!=-1) return dp[i][fl];
        int ans = 0;

        if(fl){
            ans = max( -p[i]+f(i+1, false, n, p), f(i+1, fl, n, p) );
        }
        else{
            ans = max( f(i+1, false, n, p), p[i]+f(i+1, true, n, p ) );
        }
        return dp[i][fl] = ans;
    }
    int maxProfit(vector<int>& p) {
        int n = p.size();
        memset(dp, -1, sizeof(dp));
        return f(0, true, n, p);
    }
};