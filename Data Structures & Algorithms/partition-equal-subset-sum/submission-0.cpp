#include<cstring>
class Solution {
public:
    int dp[101][2501];
    bool f(int i, int tar, vector<int>& nums){
        if(i==nums.size()) return tar==0;
        if( tar<0 ) return false;
        if(tar==0) return true;

        if( dp[i][tar]!=-1 ) return dp[i][tar];

        if(f(i+1, tar, nums)) return true;
        if(f(i+1, tar-nums[i], nums)) return true;
        return dp[i][tar] = false;
    }
    bool canPartition(vector<int>& nums) {
        long long tot =  accumulate(nums.begin(), nums.end(), 0LL);
        memset( dp, -1, sizeof(dp) );

        if( tot%2!=0 ) return false;
        int tar = tot>>1;

        return f(0, tar, nums);
    }
};
