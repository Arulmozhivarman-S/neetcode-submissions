class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        int ans = nums[0];

        int mn = nums[0], mx = nums[0];

        for(int i=1; i<n; i++){
            int v = nums[i];

            if(v<0) swap(mn, mx);

            mx = max( v, v*mx);
            mn = min( v, v*mn);

            ans = max( ans, mx);
        }

        return ans;
    }
};
