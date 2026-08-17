class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intv, vector<int>& ni) {
        
        intv.push_back(ni);
        sort(intv.begin(), intv.end());

        vector<vector<int>> ans;

        for(auto t:intv){
            int s = t[0], e = t[1];

            if( ans.empty() || s>ans.back()[1] ){
                ans.push_back({s, e});
            }
            else{
                ans.back()[1] = max(e, ans.back()[1]) ;
            }
        }
        return ans;
    }
};
