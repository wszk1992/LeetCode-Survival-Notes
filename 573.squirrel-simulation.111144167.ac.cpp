class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int sum = 0;
        int minDis = INT_MAX;
        for(auto nut : nuts) {
            int D = abs(tree[0] - nut[0]) + abs(tree[1] - nut[1]);
            int S = abs(squirrel[0] - nut[0]) + abs(squirrel[1] - nut[1]);
            sum += 2 * D;
            minDis = min(minDis, S - D);
        }
        return sum + minDis;
    }
};