class Solution {
private:
    struct Cell {
        int i;
        int j;
        int h;
        Cell(int _i, int _j, int _h) : i(_i), j(_j), h(_h) {}
    };
    struct Cmp {
        bool operator()(Cell& c1, Cell& c2) {
            return c1.h > c2.h;
        }
    };
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.empty()) {
            return 0;
        }
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        priority_queue<Cell, vector<Cell>, Cmp> pq;
        for(int i = 0; i < m; i++) {
            pq.push(Cell(i, 0, heightMap[i][0]));
            pq.push(Cell(i, n-1, heightMap[i][n-1]));
            visited[i][0] = visited[i][n-1] = true;
        }
        for(int j = 1; j < n - 1; j++) {
            pq.push(Cell(0, j, heightMap[0][j]));
            pq.push(Cell(m-1, j, heightMap[m-1][j]));
            visited[0][j] = visited[m-1][j] = true;
        }
        int traps = 0;
        while(!pq.empty()) {
            Cell cur = pq.top();
            pq.pop();
            vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for(auto d : dir) {
                int row = cur.i + d[0], col = cur.j + d[1];
                if(row >= 0 && row < m && col >= 0 && col < n && !visited[row][col]) {
                    visited[row][col] = true;
                    traps += max(0, cur.h - heightMap[row][col]);
                    pq.push(Cell(row, col, max(cur.h, heightMap[row][col])));
                }
            }
        }
        return traps;
                                
    }
};