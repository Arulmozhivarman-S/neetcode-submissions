class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> dp;

        for(int i=0; i<n; i++){
            int v = nums[i];
            if( dp.empty() || dp.back()<v ){
                dp.push_back(v); continue;
            }
            int ind = lower_bound(dp.begin(), dp.end(), v)-dp.begin();
            dp[ind] = v;
        }
        return dp.size();
    }
};
