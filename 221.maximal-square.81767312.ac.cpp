class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxSize = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = matrix[i][j] - '0';
                }else {
                    int size = dp[i - 1][j - 1];
                    for(int k = 0; k <= size; k++) {
                        if(matrix[i - k][j] == '1' && matrix[i][j - k] == '1') {
                            dp[i][j]++;
                        }else {
                            break;
                        }
                    }
                }
                maxSize = max(maxSize, dp[i][j]);
            }
        }
        //display(dp);
        return maxSize * maxSize;
    }
    
    void display(vector<vector<int>>& dp) {
        cout<<"[";
        for(auto i : dp) {
            for(auto j : i) {
                cout << j<<" ";
            }
            cout << endl;
        }
        cout <<"]"<<endl;
    }
};

