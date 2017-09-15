//bad codes
/*
class NumMatrix {
public:

    vector<vector<int>> dp;
    int error = 0;

    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.empty() || matrix[0].empty()){
            error = 1;
        }
        else {
            int m = matrix.size();
            int n = matrix[0].size();
            int row, col;
            dp = vector<vector<int>>(m,vector<int>(n,0));
            dp[0][0] = matrix[0][0];
            for(row = 1; row < m; row++){
                dp[row][0] = dp[row-1][0] + matrix[row][0];
            }
            for(col = 1; col < n; col++){
                dp[0][col] = dp[0][col-1] + matrix[0][col];
            }
            for(row = 1; row < m; row++){
                for(col = 1; col < n; col++){
                    dp[row][col] = dp[row-1][col] + dp[row][col-1] - dp[row-1][col-1] + matrix[row][col];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(error){
            return 0;
        }
        if(row1 == 0 && col1 == 0){
            return dp[row2][col2];
        }
        else if(row1 == 0){
            return dp[row2][col2] - dp[row2][col1-1];
        }
        else if(col1 == 0){
            return dp[row2][col2] - dp[row1-1][col2];
        }
        else{
            return dp[row2][col2] - dp[row2][col1-1] - dp[row1-1][col2] + dp[row1-1][col1-1];
        }
    }
};
*/
//good codes
class NumMatrix {
public:

    vector<vector<int>> dp;
    int error = 0;

    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.empty() || matrix[0].empty()){
            error = 1;
        }
        else {
            int m = matrix.size();
            int n = matrix[0].size();
            int row, col;
            dp = vector<vector<int>>(m+1,vector<int>(n+1,0));
            
            for(row = 1; row <= m; row++){
                for(col = 1; col <= n; col++){
                    dp[row][col] = dp[row-1][col] + dp[row][col-1] - dp[row-1][col-1] + matrix[row-1][col-1];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(error){
            return 0;
        }
        return dp[row2+1][col2+1] - dp[row2+1][col1] - dp[row1][col2+1] + dp[row1][col1];
    }
};

// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);