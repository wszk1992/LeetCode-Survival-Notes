
class graphNode {
public:
    int val;
    vector<graphNode*> next;
    graphNode(int v) : val(v) {};
};

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(prerequisites.empty()) {
            return true;
        }
        vector<graphNode*> graph(numCourses, NULL);
        vector<bool> checked(numCourses, false);
        constructGragh(graph, prerequisites);
        for(auto node : graph) {
            unordered_set<graphNode*> path;
            if(findCircle(node, checked, path)) {
                return false;
            }
        }
        return true;
        
    }
    
    void constructGragh(vector<graphNode*>& graph, vector<pair<int, int>>& prerequisites) {
        for(int i = 0; i < graph.size(); i++) {
            graph[i] = new graphNode(i);
        }
        for(auto pre : prerequisites) {
            graph[pre.first]->next.push_back(graph[pre.second]);
        }
    }
    
    bool findCircle(graphNode* node, vector<bool>& checked, unordered_set<graphNode*>& path) {
        if(path.count(node)) {
            return true;
        }
        if(checked[node->val]) {
            return false;
        }
        checked[node->val] = true;
        path.insert(node);
        for(auto nextNode : node->next) {
            if(findCircle(nextNode, checked, path)) {
                return true;
            }
        }
        path.erase(node);
        return false;
    }
};