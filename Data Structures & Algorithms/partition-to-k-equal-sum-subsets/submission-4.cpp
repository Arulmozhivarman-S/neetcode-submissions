class Solution {
public:
    bool f(int msk, int sum, vector<int> &nums, int tar,vector<int> &cah, int n){
        
        if( msk==(1<<n)-1 ) return true;
        if(cah[msk]!=-1) return cah[msk];

        for(int i=0; i<n; i++){
            if( msk&(1<<i) ) continue;
            if( sum+nums[i]>tar ) continue;
        
            int ns = (sum+nums[i])%tar;
            if(f(msk|(1<<i), ns , nums, tar, cah, n)) {
                cah[msk] = 1;
                return true;
            }
        }
        return cah[msk] = false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        long long tot = accumulate(nums.begin(), nums.end(), 0LL);
        sort(nums.rbegin(), nums.rend());
        int tar = tot/k;
        if(tot%k!=0 || nums[0]>tar) return false;
        vector<int> cah(1<<n, -1);

        return f( 0, 0, nums, tar, cah, n);
    }
};