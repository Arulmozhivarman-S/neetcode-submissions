class Solution {
public:
    vector<int> par;
    int fup(int u){
        return u==par[u]?u:( fup(par[u]) );
    }
    void merge(int u, int v){
        int pu = fup(u), pv = fup(v);
        par[pu] = pv;
    }
    int minCostConnectPoints(vector<vector<int>>& p) {
        
        int n = p.size();
        par.assign(n, 0);
        iota(par.begin(), par.end(), 0);

        vector<array<int, 3>> arr;

        for(int i=0; i<n; i++){
            int x1 = p[i][0], y1 = p[i][1];
            for(int j=i+1; j<n; j++){
                int x2 = p[j][0], y2 = p[j][1];
                int dist = abs(x1-x2) + abs(y1-y2);
                arr.push_back({ dist, i, j });
            }
        }

        sort(arr.begin(), arr.end());

        int ans = 0, co = 0;

        for(auto [dist, i, j]:arr){

            if( fup(i)!=fup(j) ){
                merge(i, j);
                ans += dist;
                co++;
            }
            if(co==n-1) break;
        }
        return ans;
    }
};
