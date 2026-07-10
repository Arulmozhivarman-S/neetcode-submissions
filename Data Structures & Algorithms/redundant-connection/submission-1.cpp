class Solution {
public: 
    vector<int> par;
    int fup(int u){
        if(u==par[u]) return u;
        return par[u] = fup(par[u]);
    }
    void merge(int u, int v){

        int pu = fup(u), pv = fup(v);
        par[pu] = par[pv];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edg) {
        
        int n = edg.size();
        par.assign(n, 0);
        iota(par.begin(), par.end(), 0);
        vector<int> ans;
        
        for(auto t:edg){
            int u = t[0], v = t[1]; u--, v--;
            
            if( fup(u)==fup(v) ){
                ans = {u+1, v+1};
            }
            merge(u, v);
        }
        
        return ans;
    }
};
