class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        //1. build graph
        vector<vector<int>> graph(n);
        for(auto edge : edges) {
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }
        //2. find circle using dfs
        unordered_set<int> path;
        unordered_set<int> arrived;
        return dfs(graph, arrived, path, -1, 0) && arrived.size() == n;
    }
    
    bool dfs(vector<vector<int>>& graph, unordered_set<int>& arrived, unordered_set<int>& path, int last, int cur) {
        path.insert(cur);
        arrived.insert(cur);
        for(int i = 0; i < graph[cur].size(); i++) {
            if(last == graph[cur][i]) {
                continue;
            }
            if(path.count(graph[cur][i])) {
                return false;
            }
            if(!dfs(graph, arrived, path, cur, graph[cur][i])) {
                return false;
            }
        }
        path.erase(cur);
        return true;
    }
};