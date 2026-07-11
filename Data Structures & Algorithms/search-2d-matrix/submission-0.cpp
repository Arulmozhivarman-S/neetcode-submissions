class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        
        int n = mat.size(), m = mat[0].size();

        int l = 0, r = n*m-1;

        while(l<=r){
            int mid = l+(r-l)/2;

            int row = mid/m, col = mid%m;

            if( mat[row][col]==tar ) return true;

            if( mat[row][col]<tar ){    
                l = mid+1;
            }
            else r = mid-1;
        }
        return false;
    }
};
