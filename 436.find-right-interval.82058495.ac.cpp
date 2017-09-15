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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<int> res;
        map<int, int> map;
        for(int i = 0; i < intervals.size(); i++) {
            map[intervals[i].start] = i;
        }
        for(auto interval : intervals) {
            auto it = map.lower_bound(interval.end);
            if(it == map.end()) {
                res.push_back(-1);
            }else {
                res.push_back(it->second);
            }
        }
        return res;
    }
};