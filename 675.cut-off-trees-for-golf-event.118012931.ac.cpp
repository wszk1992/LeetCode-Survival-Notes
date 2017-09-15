class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size();
        map<int, pair<int, int>> pos;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(forest[i][j] >= 2) {
                    pos[forest[i][j]] = make_pair(i, j);
                }
            }
        }
        pair<int, int> lastPos = {0, 0};
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        int totalStep = 0;
        for(auto p : pos) {
            int height = p.first;
            //go bfs to find position of lastHeight
            //bfs from two end
            queue<pair<int, int>> q;
            q.push(p.second);
            int step = 0;
            vector<vector<bool>> arrived(m, vector<bool>(n));
            arrived[p.second.first][p.second.second] = 1;
            bool found = false;
            while(!found && !q.empty()){
                int len = q.size();
                while(len--) {
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    if(r == lastPos.first && c == lastPos.second) {
                        found = true;
                        break;
                    }
                    for(auto d : dir) {
                        int newR = r + d[0];
                        int newC = c + d[1];
                        if(newR >= 0 && newR < m && newC >= 0 && newC < n && forest[newR][newC] != 0 && arrived[newR][newC] != 1) {
                            arrived[newR][newC] = 1;
                            q.push(make_pair(newR, newC));
                        }
                    }
                }
                step++;
            }
            if(!found) {
                return -1;
            }
            totalStep += step - 1;
            lastPos = p.second;
        }
        return totalStep;
    }
};