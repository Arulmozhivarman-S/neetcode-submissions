class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> l(26);

        int n = s.size();

        for(int i=0; i<n; i++){
            l[s[i]-'a'] = i;
        }

        int co = 0, mr = 0;
        vector<int> ans;

        for(int i=0; i<n; i++){
            co++;
            mr = max( mr, l[s[i]-'a']);
            if(mr==i){
                ans.push_back(co);
                co = 0;
            }
        }
        return ans;
    }
};
