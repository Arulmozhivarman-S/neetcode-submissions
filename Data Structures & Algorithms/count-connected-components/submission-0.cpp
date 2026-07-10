class Solution {
public:
    void dfs(int u, int p, vector<vector<int>>& g, vector<int> &vis){

        vis[u] = 1;

        for(int v:g[u]){
            if(v==p || vis[v]) continue;
            dfs(v, u, g, vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& edg) {

        vector<vector<int>> g(n);

        for(auto t:edg){
            int u = t[0], v = t[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> vis(n);
        int ans = 0;

        for(int i=0; i<n; i++){
            if( !vis[i] ){
                dfs(i, -1, g, vis);
                ans++;
            }
        }
        return ans;
    }
};
