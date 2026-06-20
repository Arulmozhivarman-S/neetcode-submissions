class Solution {
public:
    bool f(int pos, int tc, int tar, int n, vector<int> &par, vector<int>& nums, int k){

        if(pos==n){
            return tc==k;
        }

        for(int i=0; i<k; i++){
            if(par[i]+nums[pos]>tar) continue;

            par[i]+=nums[pos];
            if(par[i]==tar) tc++;

            if(f(pos+1, tc, tar, n, par, nums, k)) return true;

            if(par[i]==tar) tc--;
            par[i]-=nums[pos];
        }   
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        long long tot = accumulate(nums.begin(), nums.end(), 0LL);
        if(tot%k!=0) return false;
        int tar = tot/k;

        sort(nums.rbegin(), nums.rend());
        vector<int> par(k);
        return f(0, 0, tar, n, par, nums, k);
    }
};