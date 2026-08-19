/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool cmp(Interval &a, Interval &b){
        return a.start<b.start;
    }
    int minMeetingRooms(vector<Interval>& intv) {
        
        sort(intv.begin(), intv.end(), cmp);
        
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> endtime;

        for(auto t:intv){
            int s = t.start, e = t.end;

            if( endtime.empty() || endtime.top()>s ){
                ans++;
            }
            else{
                endtime.pop();
            }
            endtime.push(e);
        }
        return ans;
    }
};
