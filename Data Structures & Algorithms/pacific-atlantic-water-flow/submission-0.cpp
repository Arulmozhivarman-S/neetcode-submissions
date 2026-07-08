static vector<vector<int>> dir = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<int>>& oc, vector<vector<int>>& h){
        oc[i][j] = 1;

        for(auto t:dir){
            int dx = i+t[0], dy = j+t[1];
            if( dx>=0 && dx<n && dy>=0 && dy<m && oc[dx][dy]==0 && h[i][j]<=h[dx][dy]){
                dfs(dx, dy, n, m, oc, h);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n = h.size(), m = h[0].size();
        vector<vector<int>> pac(n, vector<int>(m)), atl(n, vector<int>(m));

        for(int i=0; i<n; i++) dfs(i, 0, n, m, pac, h);
        for(int i=0; i<m; i++) dfs(0, i, n, m, pac, h);

        for(int i=0; i<m; i++) dfs(n-1, i, n, m, atl, h);
        for(int i=0; i<n; i++) dfs(i, m-1, n, m, atl, h);

        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if( pac[i][j] && atl[i][j] ){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
