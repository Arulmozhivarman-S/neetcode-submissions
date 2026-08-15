class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1) return 0;
        int mr = nums[0], co = 1, curend = nums[0];

        for(int i=0; i<n-1; i++){
            mr = max( mr, i+nums[i]);

            if(i==curend){
                co++;
                curend = mr;
                if(mr>=n-1) break;
            }
        }
        return co;
    }
};
