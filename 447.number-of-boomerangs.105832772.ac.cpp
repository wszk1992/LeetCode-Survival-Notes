class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = points.size();
        int num = 0;
        vector<vector<int>> distances(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            unordered_map<int, int> sameDis;
            vector<int> uniqDis;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(distances[i][j] == 0) {
                    distances[i][j] = distances[j][i] = dis(points[i], points[j]);
                }
                if(sameDis.count(distances[i][j])) {
                    sameDis[distances[i][j]]++;
                } else {
                    sameDis[distances[i][j]] = 1;
                    uniqDis.push_back(distances[i][j]);
                }
            }
            for(int d : uniqDis) {
                num += sameDis[d] * (sameDis[d] - 1);
            }
        }
        return num;
    }
    
    int dis(pair<int, int>& p1, pair<int, int>& p2) {
        int dx = p1.first - p2.first;
        int dy = p1.second - p2.second;
        return dx * dx + dy * dy;
    }
};