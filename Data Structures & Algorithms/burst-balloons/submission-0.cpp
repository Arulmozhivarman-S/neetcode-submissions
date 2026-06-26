class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>( n, 0));

        for(int l=2; l<n; l++){

            for(int i=0; i<n-l; i++){
                int j = i+l;
                for(int k=i+1; k<j; k++){
                    int v = nums[i]*nums[j]*nums[k];
                    dp[i][j] = max( dp[i][j], v + dp[i][k] + dp[k][j] );
                }
            }
        }
        return dp[0][n-1];
    }
};
