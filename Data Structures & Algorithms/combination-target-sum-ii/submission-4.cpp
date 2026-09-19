class Solution {
public:
    vector<vector<int>> st;
    void f(int i, int n, vector<int>& nums, vector<int>& cur, int t){
        if(t==0){
            st.push_back(cur);
            return ;
        }

        for(int j=i; j<n; j++){

            if( j>i &&  nums[j]==nums[j-1]){
                continue;
            }

            if( nums[j]>t ) break;

            cur.push_back(nums[j]);
            f(j+1, n, nums, cur, t-nums[j]);
            cur.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int t) {

        int n = nums.size();
        st.clear();
        sort(nums.begin(), nums.end());

        vector<int> cur;

        f(0, n, nums, cur, t);

        return st;
    }
};
