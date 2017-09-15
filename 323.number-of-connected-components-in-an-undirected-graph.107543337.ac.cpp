class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> graph;
        for(int i = 0; i < n; i++) graph.push_back(i);
        vector<int> weight(n, 1);
        for(auto edge : edges) {
            unionEdges(weight, graph, edge.first, edge.second);
        }
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(graph[i] == i) {
                count++;
            }
        }
        return count;
    }
    
    int findRoot(vector<int>& graph, int index) {
        while(graph[index] != index) {
            index = graph[index];
        }
        return index;
    }
    
    void unionEdges(vector<int>& weight, vector<int>& graph, int i1, int i2) {
        int root1 = findRoot(graph, i1);
        int root2 = findRoot(graph, i2);
        if(root1 != root2) {
            if(weight[root1] > weight[root2]) {
                graph[root2] = root1;
                weight[root1] += weight[root2];
            } else {
                graph[root1] = root2;
                weight[root2] += weight[root1];
            }
        }
    }
};