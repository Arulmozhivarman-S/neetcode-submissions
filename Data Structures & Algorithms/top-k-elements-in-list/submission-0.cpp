class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;

        for(int i:nums) mp[i]++;

        priority_queue<pair<int, int>> q;

        for(auto [v, fq]:mp){
            q.push({fq, v});
        }

        vector<int> ans;

        while(!q.empty() && k--){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};
