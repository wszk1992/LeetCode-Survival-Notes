class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> pos;
        if(matrix.empty()) {
            return pos;
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, 0));
        vector<vector<bool>> atlantic(m, vector<bool>(n, 0));
        //the positions can get pacific
        for(int i = 0; i < m; i++) {
            //to left
            goHigh(matrix, pacific, i, 0, 0);
            goHigh(matrix, atlantic, i, n - 1, 0);
        }
        for(int j = 0; j < n; j++) {
            goHigh(matrix, pacific, 0, j, 0);
            goHigh(matrix, atlantic, m - 1, j, 0);
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    pos.push_back(make_pair(i, j));
                }
            }
        }
        return pos;
    }
    
    void goHigh(vector<vector<int>>& matrix, vector<vector<bool>>& ocean, int i, int j, int lastHeight) {
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] < lastHeight || ocean[i][j]) {
            return;
        }
        ocean[i][j] = 1;
        goHigh(matrix, ocean, i - 1, j, matrix[i][j]);
        goHigh(matrix, ocean, i + 1, j, matrix[i][j]);
        goHigh(matrix, ocean, i, j - 1, matrix[i][j]);
        goHigh(matrix, ocean, i, j + 1, matrix[i][j]);
    }
};