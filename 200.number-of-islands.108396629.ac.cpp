class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) {
            return 0;
        }
        int count = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
            return;
        }
        grid[i][j] = 'x';
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(auto d : dir) {
            dfs(grid, i + d[0], j + d[1]);
        }
    }
};