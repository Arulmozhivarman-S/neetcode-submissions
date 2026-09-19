class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();

        vector<int> ans;
        priority_queue<pair<int, int>> q;

        for(int l=0,r=0; r<n; r++){

            q.push({ nums[r], r });

            while( !q.empty() && q.top().second<l ){
                q.pop();
            }

            if( r-l+1==k ){
                ans.push_back( q.top().first );
                l++;
            }

        }
        return ans;
    }
};
