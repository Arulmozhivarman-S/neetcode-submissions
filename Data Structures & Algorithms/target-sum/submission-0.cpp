#include<cstring>
class Solution {
public:
    int dp[21][2001];
    int f(int i, int tar, vector<int>& nums){
        if(i==nums.size()) return tar==0;

        if( dp[i][tar+1000]!=-1 ) return dp[i][tar+1000];

        int ans = 0;

        ans += f(i+1, tar-nums[i], nums);
        ans += f(i+1, tar+nums[i], nums);
        return dp[i][tar+1000] = ans;
    }
    int findTargetSumWays(vector<int>& nums, int tar) {
        
        int n = nums.size();
        memset(dp, -1, sizeof(dp));

        return f(0, tar, nums);
    }
};
