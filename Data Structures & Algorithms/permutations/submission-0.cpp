class Solution {
public:
    vector<vector<int>> ans;

    void f(int l, int r, vector<int>& nums){

        if( l==r ){
            ans.push_back(nums);
            return;
        }

        for(int i=l; i<=r; i++){
            swap(nums[l], nums[i]);
            f(l+1, r, nums);
            swap(nums[l], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n = nums.size();

        f( 0, n-1, nums);
        return ans;
    }
};
