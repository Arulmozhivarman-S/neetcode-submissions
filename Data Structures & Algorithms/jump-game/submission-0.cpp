class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size(), pos = 0;

        for(int i=0; i<n; i++){
            
            pos = max(pos, i+nums[i]);

            if(pos==i){
                return pos==n-1;
            }
        }
        return true;
    }
};
