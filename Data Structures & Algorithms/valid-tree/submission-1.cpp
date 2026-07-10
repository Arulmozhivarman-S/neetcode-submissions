class Solution {
public:
    bool dfs(int u, int p, vector<vector<int>> &g, vector<int> &vis){

        vis[u] = 1;

        for(int v:g[u]){
            if(v==p) continue;
            if(vis[v]) return false;
            if(!dfs(v, u, g, vis)) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& e) {

        vector<vector<int>> g(n);

        for(auto t:e){
            g[t[0]].push_back(t[1]);
            g[t[1]].push_back(t[0]);
        }
        vector<int> vis(n);
        if(!dfs(0, -1, g, vis)) return false;
        for(int i:vis){
            if(i==0) return false;
        }
        return true;
    }
};
