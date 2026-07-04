class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {

        unordered_map<string, vector<string>> mp;

        for(auto &k:s){
            string t = k;
            sort(t.begin(), t.end());
            mp[t].push_back(k);
        }
       
        vector<vector<string>> ans;
        for(auto t:mp){
            ans.push_back(t.second);
        }
    
        return ans;
    }
};
