class Solution {
public:
    string foreignDictionary(vector<string>& w) {
        unordered_map<char, vector<char>> mp;
        vector<int> deg(26, 0);
        vector<bool> vis(26, false); // Tracks all unique characters present

        // 1. Initialize vis for every character present in the dictionary
        int unique_chars = 0;
        for (const string& s : w) {
            for (char c : s) {
                if (!vis[c - 'a']) {
                    vis[c - 'a'] = true;
                    unique_chars++;
                }
            }
        }

        int n = w.size();
        for (int i = 0; i < n - 1; i++) {
            string a = w[i], b = w[i + 1];
            int p = 0, q = 0;

            while (p < a.size() && q < b.size() && a[p] == b[q]) {
                p++, q++;
            }

            // 2. Fix: Check invalid prefix rule (e.g., "wrt" before "wr")
            if (p < a.size() && q == b.size()) {
                return ""; 
            }

            if (p < a.size() && q < b.size()) {
                char c1 = a[p], c2 = b[q];
                deg[c2 - 'a']++;
                mp[c1].push_back(c2);
            }
        }

        queue<char> q;
        for (int i = 0; i < 26; i++) {
            if (vis[i] && deg[i] == 0) {
                q.push(i + 'a');
            }
        }

        string ans = "";
        while (!q.empty()) {
            char t = q.front(); 
            q.pop();
            ans += t; // 3. Fix: Append char directly, not to_string()

            for (char &c : mp[t]) {
                if (--deg[c - 'a'] == 0) { // Fix: Adjusted index shift for deg
                    q.push(c);
                }
            }
        }

        // 4. Fix: If ans length doesn't match total unique characters, a cycle exists
        return ans.size() == unique_chars ? ans : "";
    }
};