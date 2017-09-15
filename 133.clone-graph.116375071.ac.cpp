/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) {
            return NULL;
        }
        unordered_map<int, UndirectedGraphNode*> dict;
        return dfs(node, dict);
    }
    
    UndirectedGraphNode *dfs(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode*>& dict) {
        UndirectedGraphNode* cur = new UndirectedGraphNode(node->label);
        dict[node->label] = cur;
        for(auto neighbor : node->neighbors) {
            if(dict.count(neighbor->label)) {
                cur->neighbors.push_back(dict[neighbor->label]);
            } else {
                cur->neighbors.push_back(dfs(neighbor, dict));
            }
        }
        return cur;
    }
};