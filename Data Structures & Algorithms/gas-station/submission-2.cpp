class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size() , tot =0, cur = 0;
        
        int st = 0;

        for(int i=0; i<n; i++){
            int net = (gas[i]-cost[i]);
            tot += net;
            cur += net;
            if(cur<0){
                cur = 0;
                st = i+1;
            }
        }
        return tot<0?-1:st;
    }
};
