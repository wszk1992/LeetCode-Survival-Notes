class Solution {
public:
    struct Cmp {
        bool operator() (pair<int, int>& p1, pair<int, int>& p2) {
            return p1.second == p2.second ? p1.first < p2.first : p1.second < p2.second;
        }
    };
    bool isReflected(vector<pair<int, int>>& points) {
        if(points.empty()) {
            return true;
        }
        sort(points.begin(), points.end(), Cmp());
        int start = 0;
        double line = 0;
        bool assigned = false;
        for(int i = 1; i < points.size(); i++) {
            if(points[i].second != points[i-1].second) {
                for(int j = start; j <= (i + start - 1) / 2; j++) {
                    double mid = (points[j].first + points[i - j + start - 1].first) / 2.0;
                    if(!assigned) {
                        line = mid;
                        assigned = true;
                    } else {
                        if(mid != line) {
                            return false;
                        }
                    }
                }
                start = i;
            }
        }
        for(int j = start; j <= (points.size() + start - 1) / 2; j++) {
            double mid = (points[j].first + points[points.size() - j + start - 1].first) / 2.0;
            if(!assigned) {
                line = mid;
                assigned = true;
            } else {
                if(mid != line) {
                    return false;
                }
            }
        }
        return true;
    }
};