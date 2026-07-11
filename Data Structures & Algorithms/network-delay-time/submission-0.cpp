class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        k--;
        vector<vector<pair<int, int>>> g(n);

        for(auto t:times){
            int u = t[0], v = t[1], req = t[2];
            u--, v--;
            g[u].push_back({v, req});
        }

        vector<int> time(n, INT_MAX);
        time[k] = 0;

        using st = pair<int, int>;

        priority_queue<st, vector<st>, greater<st>> q;
        q.push({0, k});

        while(!q.empty()){
            
            auto t = q.top(); q.pop();
            int curt = t.first, u = t.second;

            for(auto [v, req]:g[u]){
                if( curt+req<time[v] ){
                    time[v] = curt+req;
                    q.push({time[v], v});
                }
            }
        }
        int ans = *max_element(time.begin(), time.end());
        return ans==INT_MAX?-1:ans;
    }
};
