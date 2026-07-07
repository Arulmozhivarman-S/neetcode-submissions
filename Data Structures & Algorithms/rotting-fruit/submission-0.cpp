class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        
        int fc = 0, n = g.size(), m = g[0].size();

        queue<pair<int, pair<int, int>>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if( g[i][j]==1 ) fc++;
                else if( g[i][j]==2 ){
                    q.push( { 0, {i, j} } );
                }
            }
        }

        vector<vector<int>> dir = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
        int ans = 0;

        while(!q.empty()){

            auto t = q.front(); q.pop();

            int time = t.first, x = t.second.first, y = t.second.second;
            ans = max( ans, time);

            for( auto k:dir){
                int dx = x+k[0], dy = y+k[1];

                if( dx>=0  && dx<n && dy>=0 && dy<m && g[dx][dy]==1){
                    g[dx][dy] = 2;
                    fc--;
                    q.push( { time+1, { dx, dy } } );
                }
            }
        }
        if( fc>0 ) return -1;
        return ans;
    }
};
