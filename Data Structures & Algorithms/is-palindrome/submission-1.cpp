class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";
        for(char c:s){
            if(isdigit(c) || (c>='a' && c<='z') || (c>='A' && c<='Z') ) ans+=tolower(c);
        }
        int i=0, j = ans.size()-1;
        
        while(i<j){
            if(ans[i]!=ans[j]) return false;
            i++, j--;
        }
        return true;
    }
};
