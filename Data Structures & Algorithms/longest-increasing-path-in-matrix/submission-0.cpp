#include<cstring> 
class Solution {
public:
    int memo[101][101];
    vector<vector<int>> dir = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    int f(int i, int j, int n, int m, vector<vector<int>>& mat){

        if( memo[i][j]!=-1 ) return memo[i][j];
        int ans = 1;
        int v = mat[i][j];

        for(auto t:dir){
            int x = i+t[0], y = j+t[1];
            if( x<n && x>=0 && y<m && y>=0 && mat[x][y]>mat[i][j]){  
                ans = max( ans, 1+f(x, y, n, m, mat));
            }
        }
        return memo[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {

        int n = mat.size(), m = mat[0].size();

        int ans = 0;
        memset(memo, -1, sizeof(memo));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans = max( ans, f(i, j, n, m, mat));
            }
        }
        return ans;
    }
};
