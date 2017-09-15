class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = -1, col = -1;
        bool flag = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    if(flag) {
                        row = i;
                        col = j;
                        flag = 0;
                    }else {
                        matrix[row][j] = 0;
                        matrix[i][col] = 0;
                    }
                }
            }
        }
        if(row != -1) {
            for(int i = 0; i < m; i++) {
                if(i != row && matrix[i][col] == 0) {
                    for(int j = 0; j < n; j++) {
                        matrix[i][j] = 0;
                    }
                }
            }
            
            for(int j = 0; j < n; j++) {
                if(matrix[row][j] == 0) {
                    for(int i = 0; i < m; i++) {
                        matrix[i][j] = 0;
                    }
                }
            }
            for(int j = 0; j < n; j++) {
                matrix[row][j] = 0;
            }
        }
    }
};