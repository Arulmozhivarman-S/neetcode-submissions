class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.size(), m = t.size();
        if( m==0 ) return "";

        unordered_map<char, int> mp, mp2;

        int ans = INT_MAX, i = -1;

        for(char c:t) mp[c]++;

        int need = mp.size(), have = 0;

        for(int l=0,r=0; r<n; r++){
            mp2[s[r]]++;

            if( mp[s[r]]==mp2[s[r]] ){
                have++;
            }

            while( have==need ){

                if( (r-l+1)<ans ){
                    ans = r-l+1;
                    i = l;
                }

                mp2[s[l]]--;

                if( mp2[s[l]]<mp[s[l]] ) have--;
                l++;
            }
           
        }
        return ans==INT_MAX? "" : s.substr(i, ans);
    }
};
