class Solution {
public:

    string encode(vector<string>& s) {
        string t = "";

        for(auto &k:s){
            t += (to_string(k.size())+"#"+k);
        }
        return t;
    }

    vector<string> decode(string s) {
       
       vector<string> ans;

        for(int i=0; i<s.size(); ){
            int j = s.find('#', i);
            int len = stoi(s.substr(i, j-i));
            i = j+1;
            ans.push_back( s.substr(i, len) );
            i += len;
        }
        return ans;
    }   
};
