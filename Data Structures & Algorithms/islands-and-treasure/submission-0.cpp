class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& g) {
        
        int n = g.size(), m = g[0].size();

        queue<pair<int, pair<int, int>>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if( g[i][j]==0 ){
                    q.push({ 0, {i, j}});
                }
            }
        }

        vector<vector<int>> dir = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

        while(!q.empty()){
            
            auto t = q.front(); q.pop();
            int co = t.first, x = t.second.first, y = t.second.second;

            for(auto k:dir){
                int dx = x+k[0], dy = y+k[1];
    
                if( dx>=0 && dx<n && dy>=0 && dy<m && g[dx][dy]!=0 ){
                    if( co+1<g[dx][dy] ){
                        q.push( { co+1, { dx, dy} } );
                        g[dx][dy] = co+1;
                    }
                }
            }
        }
        
    }
};
