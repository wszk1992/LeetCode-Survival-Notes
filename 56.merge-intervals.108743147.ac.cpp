/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    struct Cmp {
        bool operator() (Interval& i1, Interval& i2) {
            return i1.start < i2.start;
        }
    };
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.empty()) {
            return res;
        }
        //1. sort by start
        sort(intervals.begin(), intervals.end(), Cmp());
        //2. check if i1 and i1 + 1 is overlapped, if yes, merge them
        for(int i = 0; i < intervals.size(); i++) {
            if(!res.empty() && intervals[i].start <= res.back().end) {
                //merge
                res[res.size()-1].end = max(res.back().end, intervals[i].end);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};