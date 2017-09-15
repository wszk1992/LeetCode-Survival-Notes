class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int front = 0;
        int end = m * n - 1;
        while(front < end) {
            int mid = (front + end) / 2;
            int val = matrix[mid/n][mid%n];
            if(target < val) {
                end = mid;
            } else if(target > val) {
                front = mid + 1;
            } else {
                return true;
            }
        }
        return target == matrix[front/n][front%n];
    }
};