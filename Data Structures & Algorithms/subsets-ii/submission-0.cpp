class Solution {
public: 
    vector<vector<int>> ans;
    set<vector<int>> seen;

    void f(int i, int n, vector<int>& nums, vector<int>& cur){

        if(i==n){
            if(seen.find(cur)==seen.end()) {
                ans.push_back(cur);
                seen.insert(cur);
            }
            return;
        }

        cur.push_back(nums[i]);
        f(i+1, n, nums, cur);
        cur.pop_back();

        f(i+1, n, nums, cur);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> cur;

        f(0, n, nums, cur);
        return ans;
    }
};
