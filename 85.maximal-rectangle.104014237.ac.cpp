class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size();
        int max_area = 0;
        vector<int> left(n, 0);
        vector<int> right(n, n);
        vector<int> height(n, 0);
        for(int i = 0; i < m; i++) {
            int cur_left = 0, cur_right = n;
            //height
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            //left boundary
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '0') {
                    left[j] = 0;
                    cur_left = j + 1;
                } else {
                    left[j] = max(left[j], cur_left);
                }
            }
            
            //right boundary
            for(int j = n - 1; j >= 0; j--) {
                if(matrix[i][j] == '0') {
                    right[j] = n;
                    cur_right = j;
                } else {
                    right[j] = min(right[j], cur_right);
                }
            }
            
            //max_area
            for(int j = 0; j < n; j++) {
                max_area = max(max_area, (right[j] - left[j]) * height[j]);
            }
        }
        return max_area;
    }
};