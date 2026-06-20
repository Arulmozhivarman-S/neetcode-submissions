class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        vector<vector<bool>> pal(n+1, vector<bool>(n+1, false));

        int st = 0, len = 1;

        for(int i=1; i<n; i++){
            pal[i][i] = true;
            for(int j=0; j<i; j++){
                if(s[i]==s[j]){
                    if(i-j<=2 || pal[j+1][i-1] ){
                        if( i-j+1>len ){
                            len = i-j+1;
                            st = j;
                        }
                        pal[j][i] = true;
                    }
                }
            }
        }
        return s.substr(st, len);
    }
};
