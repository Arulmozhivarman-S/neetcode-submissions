class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;

        long long prod = 1, co = 0;

        for(int i:nums) {
            if(i==0){
                co++;
            }
            else prod*=i;
        }

        for(int i:nums){
            if( i==0 ){
                if(co>1) ans.push_back(0);
                else ans.push_back(prod);
            }
            else{
                int v = co>0?0:prod/i;
                ans.push_back(v);
            }
        }
        return ans;
    }
};
