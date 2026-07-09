vector<vector<int>> dir = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<char>>& b, vector<vector<bool>>& vis){

        vis[i][j] = true;
        for(auto k:dir){
            int dx = i+k[0], dy = j+k[1];

            if( dx>=0 && dx<n && dy>=0 && dy<m && b[dx][dy]=='O' && !vis[dx][dy]){
                dfs(dx, dy, n, m, b, vis);
            }
        }
    }
    void solve(vector<vector<char>>& b) {
        
        int n = b.size(), m = b[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            if( b[i][0]=='O' ) dfs(i, 0, n, m, b, vis);
            if( b[i][m-1]=='O' ) dfs(i, m-1, n, m, b, vis);
        }

        for(int i=0; i<m; i++){
            if( b[0][i]=='O' ) dfs(0, i, n, m, b, vis);
            if( b[n-1][i]=='O' ) dfs(n-1, i, n, m, b, vis);
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if( b[i][j]=='O' && !vis[i][j]) b[i][j] = 'X';
            }
        }

    }
};
