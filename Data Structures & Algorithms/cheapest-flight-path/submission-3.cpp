class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& fl, int src, int dst, int k) {
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for(int i=0; i<=k; i++){
            
            vector<int> t = dist;

            for(auto k:fl){
                int u = k[0], v = k[1], w = k[2];

                if( dist[u]!=INT_MAX && dist[u]+w<t[v] ){
                    t[v] = dist[u]+w;
                }
            }
            dist = t;
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};
