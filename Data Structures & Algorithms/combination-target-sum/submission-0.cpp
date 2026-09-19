class Solution {
public:
    vector<vector<int>> ans;
    void f(int i, int n, vector<int>& nums, vector<int>& cur, int t){
        if( i==-1 ){
            if( t==0 ) ans.push_back( cur );
            return;
        }

        if( nums[i]<=t ){
            cur.push_back(nums[i]);
            f(i, n, nums, cur, t-nums[i]);
            cur.pop_back();
        }
        f(i-1, n, nums, cur, t);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int t) {
        
        sort(nums.begin(), nums.end());
        vector<int> cur;
        int n = nums.size();

        f(n-1, n, nums, cur, t);
        return ans;
    }
};
