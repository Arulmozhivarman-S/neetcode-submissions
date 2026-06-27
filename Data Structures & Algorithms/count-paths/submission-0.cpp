class Solution {
public:
    int uniquePaths(int m, int n) {
        // Total steps needed to reach (m-1, n-1) from (0,0)
        int total_steps = m + n - 2;
        // Number of Right (or Down) moves we need to choose
        int r = n - 1; 
        
        // Optimization: C(n, k) == C(n, n-k)
        if (r > total_steps - r) {
            r = total_steps - r;
        }

        long long ans = 1;

        // Compute combination efficiently on the fly
        for (int i = 1; i <= r; i++) {
            ans = ans * (total_steps - r + i) / i;
        }

        return (int)ans;
    }
};