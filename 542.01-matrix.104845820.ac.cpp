class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) {
            return vector<vector<int>>();
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> upm(m, vector<int>(n, INT_MAX));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    bfs(matrix, upm, i, j, 0);
                }
            }
        }
        return upm;
    }
    
    void bfs(vector<vector<int>>& matrix, vector<vector<int>>& upm, int i, int j, int dis) {
        upm[i][j] = dis;
        if(i + 1 < matrix.size() && matrix[i+1][j] != 0 && upm[i+1][j] > dis + 1) {
            bfs(matrix, upm, i + 1, j, dis + 1);
        }
        if(i - 1 >= 0 && matrix[i-1][j] != 0 && upm[i-1][j] > dis + 1) {
            bfs(matrix, upm, i - 1, j, dis + 1);
        }
        if(j + 1 < matrix[0].size() && matrix[i][j+1] != 0 && upm[i][j+1] > dis + 1) {
            bfs(matrix, upm, i, j + 1, dis + 1);
        }
        if(j - 1 >= 0 && matrix[i][j-1] != 0 && upm[i][j-1] > dis + 1) {
            bfs(matrix, upm, i, j - 1, dis + 1);
        }
        
        
        // if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || (matrix[i][j] == 0 && dis != 0) || upm[i][j] <= dis) {
        //     return;
        // }
        // upm[i][j] = dis;
        // bfs(matrix, upm, i + 1, j, dis + 1);
        // bfs(matrix, upm, i - 1, j, dis + 1);
        // bfs(matrix, upm, i, j + 1, dis + 1);
        // bfs(matrix, upm, i, j - 1, dis + 1);
    }
};