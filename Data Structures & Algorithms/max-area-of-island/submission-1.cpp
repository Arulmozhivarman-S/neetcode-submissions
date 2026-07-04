static vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& g, vector<vector<bool>>& vis){

        vis[i][j] = true;

        int ans = 1;

        for(auto t:dir){
            int dx = i+t[0], dy = j+t[1];
            if( dx>=0 && dx<g.size() && dy>=0 && dy<g[0].size() && !vis[dx][dy] && g[dx][dy]==1 ){
                ans += f(dx, dy, g, vis);
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& g) {
        
        int n = g.size(), m = g[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if( g[i][j]==1 && !vis[i][j] ){
                    ans = max( ans, f(i, j, g, vis));
                }
            }
        }   
        return ans;
    }
};
