class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wl) {
        unordered_set<string> s(wl.begin(), wl.end());
        
        // If the end word isn't even in the dictionary, a path is impossible
        if (s.find(ew) == s.end()) return 0;

        // Standard FIFO queue is perfect for unweighted shortest paths
        // pair<string, int> stores {current_word, current_ladder_length}
        queue<pair<string, int>> q;
        q.push({bw, 1}); // Start length is 1 (includes the begin word)

        while (!q.empty()) {
            auto [w, co] = q.front(); 
            q.pop();

            if (w == ew) return co;

            for (int i = 0; i < w.size(); i++) {
                char cur = w[i];
                
                // Try changing the i-th character to every letter from 'a' to 'z'
                for (char c = 'a'; c <= 'z'; c++) {
                    w[i] = c;
                    
                    if (s.find(w) != s.end()) {
                        q.push({w, co + 1});
                        s.erase(w); // Mark as visited immediately so no other path re-processes it
                    }
                }
                w[i] = cur; // Revert back for the next position loop
            }
        }
        return 0;
    }
};