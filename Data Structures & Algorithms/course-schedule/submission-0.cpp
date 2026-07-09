class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
    
        vector<vector<int>> g(n);
        vector<int> indg(n);

        for(auto t:prereq){
            g[t[1]].push_back(t[0]);
            indg[t[0]]++;
        }

        queue<int> q;

        for(int i=0; i<n; i++) if( indg[i]==0 ) q.push(i);

        int ans = 0;

        while(!q.empty()){
            int t = q.front(); q.pop();

            ans++;

            for(int v:g[t]){
                indg[v]--;
                if( indg[v]==0 ) q.push(v);
            }
        }   
        return ans==n;
    }
};
