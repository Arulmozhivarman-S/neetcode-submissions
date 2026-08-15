class Solution {
public:
    bool isNStraightHand(vector<int>& h, int gs) {
        
        int n = h.size();
        if(n%gs!=0) return false;

        sort(h.begin(), h.end());

        unordered_map<int, int> mp;
        for(int i:h) mp[i]++;
        
        for(int v:h){
            if(mp[v]>0){
                for(int i=v; i<v+gs; i++){
                    if(mp[i]==0) return false;
                    mp[i]--;
                }
            }
        }
        return true;
    }
};
