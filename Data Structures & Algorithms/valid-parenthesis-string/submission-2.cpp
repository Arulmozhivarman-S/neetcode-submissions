class Solution {
public:
    bool checkValidString(string s) {

        int n = s.size();
        stack<int> l, st;

        for(int i=0; i<n; i++){
            if(s[i]=='*') st.push(i);
            else if(s[i]=='(') l.push(i);
            else{
                if( l.empty() && st.empty() ) return false;
                if(!l.empty()) l.pop();
                else st.pop();
            }
        }

        while(!l.empty() && !st.empty()){
            if(l.top()>st.top()) return false;
            l.pop();
            st.pop();
        }
        return l.empty();
    }
};
