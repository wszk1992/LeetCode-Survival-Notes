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
    struct Cmp {
        bool operator() (Interval& i1, Interval& i2) {
            return i1.start < i2.start;
        }
    };

    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), Cmp());
        priority_queue<int, vector<int>, greater<int>> pq;
        int rooms = 0;
        for(auto iv : intervals) {
            while(!pq.empty() && iv.start >= pq.top()) {
                pq.pop();
            }
            pq.push(iv.end);
            rooms = max(rooms, (int)pq.size());
        }
        return rooms;
    }
};