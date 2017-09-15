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
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if(intervals.empty()) {
            return vector<Interval>(1, newInterval);
        }
        vector<Interval> res;
        int i = 0;
        while(i < intervals.size() && newInterval.start > intervals[i].end) {
            res.push_back(intervals[i++]);
        }
        if(i == intervals.size()) {
            res.push_back(newInterval);
            return res;
        }
        int lastEnd = INT_MIN;
        int start = min(newInterval.start, intervals[i].start);
        while(i < intervals.size()) {
            if(newInterval.end < intervals[i].start) {
                int end = max(lastEnd, newInterval.end);
                res.push_back(Interval(start, end));
                break;
            } else {
                lastEnd = intervals[i].end;
            }
            i++;
        }
        if(i == intervals.size()) {
            int end = max(lastEnd, newInterval.end);
            res.push_back(Interval(start, end));
        }
        while(i < intervals.size()) {
            res.push_back(intervals[i++]);
        }
        return res;
     }
};