class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int lw = *min_element(nums.begin(), nums.end());
        int h = *max_element(nums.begin(), nums.end());
        
        auto ch = [&](int m){

            int pr = 0;

            for(int i=0; i<n-1; i++){
                if(nums[i+1]-nums[i]<=m) {
                    pr++; i++;
                }
            }
            return pr>=p;
        };

        int r = h-lw, l = 0;

        while(l<=r){
            int m = l+(r-l)/2;

            if( ch(m) ){
                r = m-1;
            }
            else l = m+1;
        }
        return l;
    }
};