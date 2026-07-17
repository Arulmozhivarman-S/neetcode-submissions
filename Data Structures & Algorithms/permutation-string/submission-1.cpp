class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n = s1.size();
        if(n>s2.size()) return false;

        vector<int> fq1(26), fq2(26);
        for(int i=0; i<n; i++){
            fq1[s1[i]-'a']++;
            fq2[s2[i]-'a']++;
        }

        if(fq1==fq2) return true;

        for(int i=n; i<s2.size(); i++){
            fq2[s2[i-n]-'a']--;
            fq2[s2[i]-'a']++;
            if(fq1==fq2) return true;
        }
        return false;
    }
};
