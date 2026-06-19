class Solution {
public:
    int f(int l, int r, vector<int>& a) {
        int n = r - l + 1;

        if (n == 1) return a[l];

        vector<int> dp(n);

        dp[0] = a[l];
        dp[1] = max(a[l], a[l + 1]);

        for (int i = l + 2; i <= r; i++) {
            dp[i - l] = max(dp[i - l - 1],
                            dp[i - l - 2] + a[i]);
        }

        return dp[n - 1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];

        return max(
            f(0, n - 2, nums), // exclude last
            f(1, n - 1, nums)  // exclude first
        );
    }    
};
