class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            int l = i+1, r = n-1; 
            if(i>0 && nums[i]==nums[i-1]) continue;

            while(l<r){
                int s = nums[i]+nums[l]+nums[r];
                if(s==0){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++; r--;
                    while(l<r && nums[l]==nums[l-1]) l++;
                }
                else if( s<0 ){
                    l++;
                }
                else r--;
            }

        }
       
        return ans;
    }
};
