#include<cstring>
class Solution {
public:
    int dp[5001][2];
    int f(int i, bool fl, int n, vector<int>& p){

        if(i>=n) return fl?0:-1e9;

        if( dp[i][fl]!=-1 ) return dp[i][fl];
        int ans = 0;

        if( fl ){
            ans = max( -p[i]+f(i+1, false, n, p), f(i+1, fl, n , p)) ;
        }
        else{
            ans = max( p[i]+f(i+2, true, n, p), f(i+1, fl, n, p) );
        }
        return dp[i][fl] = ans;
    }
    int maxProfit(vector<int>& p) {
        int n = p.size();
        memset(dp, -1, sizeof(dp));

        return f(0, true, n, p);
    }
};
