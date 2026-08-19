class Solution {
public:
    int missingNumber(vector<int>& nums) {
       
       int n = nums.size();

        int tot = n*(n+1)/2;

        for(int i:nums) tot-=i;
        return tot;
    }
};
