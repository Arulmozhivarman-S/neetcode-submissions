class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> s(nums.begin(), nums.end());

        int ans = 0;

        for(int &i:nums){
            if( s.find(i-1)==s.end()  ){
                int co = 0;

                while(s.find(i)!=s.end()){
                    co++, i++;
                }
                ans = max( ans, co);
            }
        }
        return ans;
    }
};
