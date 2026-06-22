class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = n;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int i=0; i<n; i++) dp[i][i] = true;

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(s[i]==s[j]){
                    if( i-j<=2 || dp[j+1][i-1] ){
                        dp[j][i] = true; ans++;
                    }
                }
            }
        }
        return ans;
    }

};
