class Solution {
public:
    int leastInterval(vector<char>& t, int n) {
        
        unordered_map<char, int> mp;
        for(char c:t) mp[c]++;
        
        priority_queue<int> q;

        for(auto t:mp) q.push(t.second);

        int time = 0;

        queue<pair<int,int>> cd;

        while(!q.empty() || !cd.empty()){
            time++;

            if( q.empty() ){
                time = cd.front().second;
            }
            else{
                int t = q.top()-1; q.pop();
        
                if(t>0) cd.push({t, time+n});
            }

            if(!cd.empty() && cd.front().second==time){
                q.push(cd.front().first); cd.pop();
            }

        }

        return time;
    }
};
