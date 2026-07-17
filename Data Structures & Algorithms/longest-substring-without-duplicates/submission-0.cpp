class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size(), ans = 0;

        unordered_map<char, int> mp;

        for(int l=0,r=0; r<n; r++){
            mp[s[r]]++;

            while(mp[s[r]]>1 && l<r){
                mp[s[l]]--;
                l++;
            }
            ans = max( ans, r-l+1);
        }
        return ans;
    }
};
