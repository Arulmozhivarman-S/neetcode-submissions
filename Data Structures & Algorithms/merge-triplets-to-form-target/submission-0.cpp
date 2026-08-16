class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& tri, vector<int>& t) {
        
        vector<int> ans(3, 0);
        sort(tri.begin(), tri.end());

        for(int i=0; i<3; i++){
            for(int j=0; j<tri.size(); j++){
                vector<int> &cur = tri[j];
                if(cur[i]==t[i]){
                    ans[0] = max(ans[0], cur[0]);
                    ans[1] = max(ans[1], cur[1]);
                    ans[2] = max(ans[2], cur[2]);
                    break;
                }
            }
        }
       
        return ans[0]==t[0] && ans[1]==t[1] && ans[2]==t[2];

    }
};
