class Solution {
public:
    void f(int i, int n, vector<int>& cur, vector<vector<int>>& ans, vector<int>& nums){
        if(i==n){
            ans.push_back(cur); return;
        }

        cur.push_back(nums[i]);
        f(i+1, n, cur, ans, nums);
        cur.pop_back();
        f(i+1, n, cur, ans, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> cur;
        f(0, n, cur, ans, nums);
        return ans;
    }
};
