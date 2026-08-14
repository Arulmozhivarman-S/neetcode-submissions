class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int mx = INT_MIN, cur = 0;

        for(int i:nums){
            cur = max( cur+i, i);
            mx = max( mx, cur);
        }
        return mx;
    }
};
