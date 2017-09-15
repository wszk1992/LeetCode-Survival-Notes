class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = B[0].size();
        vector<vector<int>> AB(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int k = 0; k < B.size(); k++) {
                if(A[i][k] == 0) {
                    continue;
                }
                for(int j = 0; j < n; j++) {
                    AB[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return AB;
    }
};