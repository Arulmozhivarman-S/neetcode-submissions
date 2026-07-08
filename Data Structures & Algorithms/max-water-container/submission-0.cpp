class Solution {
public:
    int maxArea(vector<int>& h) {
        
        int n = h.size();

        int l = 0, r = n-1;

        int ans = 0;

        while(l<r){
            int hei = min(h[l], h[r]);
            ans = max( ans, (r-l)*hei);
            if( h[l]<h[r] ) l++;
            else r--;
        }
        return ans;
    }
};
