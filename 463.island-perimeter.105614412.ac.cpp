class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty()) {
            return 0;
        }
        int cells = 0;
        int neighbors = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    cells++;
                    neighbors += neighbor(grid, i, j);
                }
            }
        }
        return cells * 4 - neighbors;
    }
    
    int neighbor(vector<vector<int>>& grid, int i, int j) {
        int num = 0;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(auto dir : dirs) {
            int x = i + dir[0];
            int y = j + dir[1];
            if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1) {
                num++;
            }
        }
        return num;
    }
};