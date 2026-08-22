class Solution {
public:
    double myPow(double x, int n) {
        
        if(x==0) return 0;
        if(n==0) return 1;

        double res = 1;
        long pw = abs((long)n);

        while(pw){
            if(pw&1) res*=x;
            x = x*x;
            pw>>=1;
        }
        return n>=0 ?res:1/res;
    }
};
