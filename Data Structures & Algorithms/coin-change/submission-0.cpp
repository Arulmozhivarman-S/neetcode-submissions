class Solution {
public:
    int coinChange(vector<int>& c, int amt) {
        
        vector<int> dp(amt+1, 1e9);
        dp[0] = 0;

        sort(c.begin(), c.end());

        for(int i=1; i<=amt; i++){
            for(int v:c){
                if(i-v>=0){
                    dp[i] = min( dp[i], dp[i-v]+1);
                }
            }
        }
        return dp[amt]==1e9?-1:dp[amt];
    }
};
