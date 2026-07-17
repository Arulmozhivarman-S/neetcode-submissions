class Solution {
public:
    int maxProfit(vector<int>& p) {

        int mn = INT_MAX;

        int ans = 0;

        for(int i:p){
            mn = min( mn, i);
            ans = max( ans, i-mn);
        }
        return ans;
    }
};
