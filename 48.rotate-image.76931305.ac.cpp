class Solution {
public:
    pair<int, int> rotatePoint(pair<int, int> p, int n) {
        pair<int, int> rotP;
        rotP.first = n - 1 - p.second;
        rotP.second = p.first;
        return rotP;
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        pair<int, int> p;
        for(int i = 0; i < n / 2; i++) {
            for(int j = i; j < n - i - 1; j++) {
                int temp = matrix[i][j];
                p = pair<int, int>(i, j);
                for(int m = 0; m < 3; m++) {
                    pair<int, int> rotP = rotatePoint(pair<int, int>(p.first , p.second), n);
                    matrix[p.first][p.second] = matrix[rotP.first][rotP.second];
                    p = rotP;
                }
                matrix[p.first][p.second] = temp;
            }
        }
    }
};