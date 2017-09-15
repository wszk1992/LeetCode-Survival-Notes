class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) {
            return vector<int>();
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> arrived(m, vector<bool>(n, 0));
        vector<int> spiral;
        int count = m * n;
        int i = 0, j = 0;
        int d = 0;
        while(count--) {
            arrived[i][j] = 1;
            spiral.push_back(matrix[i][j]);
            int nexti = i + dir[d][0];
            int nextj = j + dir[d][1];
            if(nexti < 0 || nexti >= m || nextj < 0 || nextj >= n || arrived[nexti][nextj]) {
                d = (d + 1) % 4;
            }
            i += dir[d][0];
            j += dir[d][1];
        }
        return spiral;
    }
};