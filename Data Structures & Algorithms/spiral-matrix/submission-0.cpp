class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        
        int n = mat.size(), m = mat[0].size();

        vector<int> ans;
        int t=0, b = n-1, l=0, r = m-1;

        while( t<=b && l<=r ){

            for(int j=l; j<=r; j++){
                ans.push_back(mat[t][j]);
            }
            t++;
            for(int i=t; i<=b; i++){
                ans.push_back(mat[i][r]);
            }
            r--;

            if(t<=b){
                for(int j=r; j>=l; j--) ans.push_back(mat[b][j]);
                b--;
            }
            if(l<=r){
                for(int i=b; i>=t; i--) ans.push_back(mat[i][l]);
                l++;
            }

        }
        return ans;

    }
};
