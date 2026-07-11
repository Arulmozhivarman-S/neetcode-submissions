class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> mp;
    vector<string> res;

    void dfs(string air){

        while(!mp[air].empty()){
            string c = mp[air].top(); mp[air].pop();
            dfs(c);
        }
        res.push_back(air);
    }
    vector<string> findItinerary(vector<vector<string>>& tic) {    

        for(auto t:tic){
            mp[t[0]].push(t[1]);
        }
        dfs("JFK");
        reverse(res.begin(), res.end());

        return res;
    }
};
