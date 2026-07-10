class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        
        vector<vector<int>> g(n);
        vector<int> deg(n);

        for(auto t:pre){
            int u = t[0], v = t[1];
            g[v].push_back(u);
            deg[u]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(deg[i]==0) q.push(i);
        }

        vector<int> ans;

        while(!q.empty()){
            int t = q.front(); q.pop();
            ans.push_back(t);

            for(int v:g[t]){
                deg[v]--;
                if(deg[v]==0) q.push(v);
            }
        }
        vector<int> emp;
        return ans.size()==n?ans:emp;
    }
};
