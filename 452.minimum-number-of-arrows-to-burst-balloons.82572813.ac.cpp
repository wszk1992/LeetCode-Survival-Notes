//1,6 2,8 7,12 10,16

class Solution {
public:
    struct Cmp {
        bool operator() (pair<int, int> a, pair<int, int> b) {
            if(a.first == b.first) {
                return a.second < b.second;
            }else {
                return a.first < b.first;
            }
        }
    }cmp;
    
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.empty()) {
            return 0;
        }
        sort(points.begin(), points.end(), cmp);
        int limit = points[0].second;
        int count = 1;
        for(int i = 1; i < points.size(); i++) {
            if(points[i].first <= limit) {
                limit = min(limit, points[i].second);
            }else {
                count++;
                limit = points[i].second;
            }
        }
        return count;
    }
};