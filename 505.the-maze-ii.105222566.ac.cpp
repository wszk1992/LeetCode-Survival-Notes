class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        
        if(maze.empty() || maze[0].empty()) {
            return false;
        }
        int m = maze.size(), n = maze[0].size();
        //0, 1   0, -1   1, 0   -1, 0
        vector<vector<int>> dirs(4, vector<int>(2, 0));
        dirs[0][1] = 1, dirs[1][1] = -1, dirs[2][0] = 1, dirs[3][0] = -1;
        
        vector<vector<int>> minDis(m, vector<int>(n, INT_MAX));
        minDis[start[0]][start[1]] = 0;
        
        for(int i = 0; i < 4; i++) {
            bfs(maze, minDis, start, dirs[i], 0);
        }
        return minDis[destination[0]][destination[1]] == INT_MAX ? -1 : minDis[destination[0]][destination[1]];
    }
    
    void bfs(vector<vector<int>>& maze, vector<vector<int>>& minDis, vector<int> pos, vector<int> dir, int dis) {
        vector<int> next = nextPos(pos, dir);
        if(!isWall(maze, next)) {
            bfs(maze, minDis, next, dir, dis + 1);
        } else if(minDis[pos[0]][pos[1]] > dis){
            minDis[pos[0]][pos[1]] = dis;
            vector<int> d1(2, 0), d2(2, 0);
            if(dir[0] == 0) {
                d1[0] = 1;
                d2[0] = -1;
            } else {
                d1[1] = 1;
                d2[1] = -1;
            }
            if(!isWall(maze, nextPos(pos, d1))) {
                bfs(maze, minDis, nextPos(pos, d1), d1, dis + 1);
            }
            if(!isWall(maze, nextPos(pos, d2))) {
                bfs(maze, minDis, nextPos(pos, d2), d2, dis + 1);
            }
        }
    }
    
    bool isWall(vector<vector<int>>& maze, vector<int> pos) {
        return pos[0] < 0 || pos[0] >= maze.size() || pos[1] < 0 || pos[1] >= maze[0].size() || maze[pos[0]][pos[1]];
    }
    
    vector<int> nextPos(vector<int>& pos, vector<int>& dir) {
        vector<int> next(2, 0);
        next[0] = pos[0] + dir[0], next[1] = pos[1] + dir[1];
        return next;
    }
};