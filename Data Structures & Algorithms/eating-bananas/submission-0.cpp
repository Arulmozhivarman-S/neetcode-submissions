class Solution {
public:
    int ch(int m, vector<int>& p){
        int tot = 0;

        for(int i:p){
            tot+= ( i+m-1 )/m;
        }
        return tot;
    }
    int minEatingSpeed(vector<int>& p, int h) {
        
        int l = 1, r = *max_element(p.begin(), p.end());


        while(l<=r){
            
            int mid = l+(r-l)/2;

            if( ch(mid, p)<=h){
                r = mid-1;
            }
            else l = mid+1;

        }
        return l;
    }
};
