class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if(grid.empty()) {
            return 0;
        }
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> killsOnRow(m, vector<int>(n)), killsOnCol(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            int start = 0;
            int kills = 0;
            for(int j = 0; j <= n; j++) {
                if(j == n || grid[i][j] == 'W') {
                    for(int k = start; k < j; k++) {
                        killsOnRow[i][k] = kills;
                    }
                    start = j + 1;
                    kills = 0;
                } else if(grid[i][j] == 'E') {
                    kills++;
                }
            }
        }
        for(int j = 0; j < n; j++) {
            int start = 0;
            int kills = 0;
            for(int i = 0; i <= m; i++) {
                if(i == m || grid[i][j] == 'W') {
                    for(int k = start; k < i; k++) {
                        killsOnCol[k][j] = kills;
                    }
                    start = i + 1;
                    kills = 0;
                } else if(grid[i][j] == 'E') {
                    kills++;
                }
            }
        }
        int kills = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '0') {
                    kills = max(kills, killsOnRow[i][j] + killsOnCol[i][j]);
                }
            }
        }
        return kills;
    }
};