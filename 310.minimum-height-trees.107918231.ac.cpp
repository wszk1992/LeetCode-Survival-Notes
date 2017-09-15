class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        //1. build a graph
        vector<vector<int>> graph(n);
        for(auto edge : edges) {
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }
        //2. select a random edge and find the farthest edge from it
        vector<int> path;
        vector<int> longestPath;
        findLongestPath(graph, path, longestPath, 0);
        //3. starting at the farthest edge, find the longest path
       	int start = longestPath.back();
        findLongestPath(graph, path, longestPath, start);
        //4. find the mid edges of the longest path
        vector<int> root;
        if(longestPath.size() % 2) {
            root.push_back(longestPath[longestPath.size() / 2]);
        } else {
            root.push_back(longestPath[longestPath.size() / 2 - 1]);
            root.push_back(longestPath[longestPath.size() / 2]);
        }
        return root;
    }
    
    void findLongestPath(vector<vector<int>>& graph, vector<int>& path, vector<int>& longestPath, int k) {
        int last = path.empty() ? -1 : path.back();
        path.push_back(k);
        for(auto neighbor : graph[k]) {
            if(neighbor != last) {
                findLongestPath(graph, path, longestPath, neighbor);
            }
        }
        if(path.size() > longestPath.size()) {
            longestPath = path;
        }
        path.pop_back();
    }
};