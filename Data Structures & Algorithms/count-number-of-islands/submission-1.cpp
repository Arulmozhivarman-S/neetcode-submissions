static vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& g, vector<vector<bool>>& vis){
        
        vis[i][j] = true;

        for(auto t:dir){
            int dx = i+t[0], dy = j+t[1];
            if( dx>=0 && dx<g.size() && dy>=0 && dy<g[0].size() && !vis[dx][dy] && g[dx][dy]=='1' ){
                dfs(dx, dy, g, vis);
            }
        }

    }
    int numIslands(vector<vector<char>>& g) {
        
        int n = g.size(), m = g[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if( g[i][j]=='1' && !vis[i][j] ){
                    dfs(i, j, g, vis);
                    ans ++;
                }
            }
        }
        return ans;
    }
};
