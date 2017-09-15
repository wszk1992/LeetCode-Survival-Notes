class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) {
            return vector<int>();
        }
        vector<int> diagonalOrder;
        int m = matrix.size(), n = matrix[0].size();
        for(int sum = 0; sum < m + n - 1; sum++) {
            if(sum % 2) {
                int i = sum < n ? 0 : sum - n + 1;
                int j = sum < n ? sum : n - 1;
                while(i < m && j >= 0) {
                    diagonalOrder.push_back(matrix[i++][j--]);
                }
            } else {
                int i = sum < m ? sum : m - 1;
                int j = sum < m ? 0 : sum - m + 1;
                while(i >= 0 && j < n) {
                    diagonalOrder.push_back(matrix[i--][j++]);
                }
            }
        }
        return diagonalOrder;
    }
};