class Solution {
public:
    int swimInWater(vector<vector<int>>& g) {
        
        using st = array<int, 3>;
        int n = g.size(), m = g[0].size();

        priority_queue<st, vector<st>, greater<st>> q;
        q.push({ g[0][0], 0, 0 });

        vector<vector<int>> dir = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vis[0][0] = true;

        while(!q.empty()){

            auto t = q.top(); q.pop();

            int v = t[0], i = t[1], j = t[2];

            if(i==n-1 && j==m-1) return v;

            for(auto k:dir){
                int dx = i+k[0], dy = j+k[1];

                if( dx>=0 && dx<n && dy>=0 && dy<m && !vis[dx][dy] ){
                    q.push({ max( v, g[dx][dy] ), dx, dy });
                    vis[dx][dy] = true;
                }
            }
        }
        return -1;
    }
};
