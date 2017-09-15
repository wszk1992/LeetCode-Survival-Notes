class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if(maze.empty() || maze[0].empty()) {
            return false;
        }
        int m = maze.size(), n = maze[0].size();
        //0, 1   0, -1   1, 0   -1, 0
        vector<vector<int>> dirs(4, vector<int>(2, 0));
        dirs[0][1] = 1, dirs[1][1] = -1, dirs[2][0] = 1, dirs[3][0] = -1;
        
        vector<vector<bool>> arrived(m, vector<bool>(n, false));
        arrived[start[0]][start[1]] = 1;
        
        for(int i = 0; i < 4; i++) {
            bfs(maze, arrived, start, dirs[i]);
        }
        return arrived[destination[0]][destination[1]];
    }
    
    void bfs(vector<vector<int>>& maze, vector<vector<bool>>& arrived, vector<int> pos, vector<int> dir) {
        vector<int> next = nextPos(pos, dir);
        if(!isWall(maze, next)) {
            bfs(maze, arrived, next, dir);
        } else if(!arrived[pos[0]][pos[1]]){
            arrived[pos[0]][pos[1]] = 1;
            vector<int> d1(2, 0), d2(2, 0);
            if(dir[0] == 0) {
                d1[0] = 1;
                d2[0] = -1;
            } else {
                d1[1] = 1;
                d2[1] = -1;
            }
            if(!isWall(maze, nextPos(pos, d1))) {
                bfs(maze, arrived, nextPos(pos, d1), d1);
            }
            if(!isWall(maze, nextPos(pos, d2))) {
                bfs(maze, arrived, nextPos(pos, d2), d2);
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