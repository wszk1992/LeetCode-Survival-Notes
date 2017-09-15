class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {

        points.push_back(points[0]);
        points.push_back(points[1]);
        vector<int> lastVec = getVec(points[0], points[1]);
        vector<int> curVec = getVec(points[1], points[2]);
        int dir = 0;
        for(int i = 2; i < points.size(); i++) {
            curVec = getVec(points[i-1], points[i]);
            if(dir == 0) {
                dir = clockwise(lastVec, curVec);
            }
            if((dir > 0 && clockwise(lastVec, curVec) < 0) || (dir < 0 && clockwise(lastVec, curVec) > 0)) {
                return false;
            }
            lastVec = curVec;
        }
        return true;
    }
    
    int clockwise(vector<int>& last, vector<int>& cur) {
        return  last[1] * cur[0] - last[0] * cur[1];
    }
    
    vector<int> getVec(vector<int>& p0, vector<int>& p1) {
        return vector<int>({p1[0] - p0[0], p1[1] - p0[1]});
    }
};