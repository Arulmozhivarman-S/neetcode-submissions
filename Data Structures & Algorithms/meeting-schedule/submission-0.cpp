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
    static bool cmp(Interval a, Interval b){
        return a.start<=b.start;
    }
    bool canAttendMeetings(vector<Interval>& intv) {
        
        sort(intv.begin(), intv.end(), cmp);
        int end = -1;

        for(auto t:intv){
            int s = t.start;
            if( s<end ) return false;
            end = t.end;
        }
        return true;
    }
};
