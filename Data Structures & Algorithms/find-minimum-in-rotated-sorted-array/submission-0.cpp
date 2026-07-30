class Solution {
public:
    int findMin(vector<int> &nums) {
        
        int mn = 1e9;

        int l = 0, r = nums.size()-1;

        while(l<=r){
            
            if( nums[l]<nums[r] ){
                mn = min(mn, nums[l]); break;
            }

            int m = l+(r-l)/2;
            
            mn = min( mn, nums[m]);

            if( nums[m]>=nums[l] ){
                l = m+1;
            }
            else r = m-1;

        }
        return mn;

    }
};
