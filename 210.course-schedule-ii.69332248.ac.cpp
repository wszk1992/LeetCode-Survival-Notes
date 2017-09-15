class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> vertex(numCourses, vector<int>());
        for(auto course : prerequisites) {
            vertex[course.second].push_back(course.first);
        }
        vector<bool> visited(numCourses, false);
        stack<int> s;
        vector<int> res;
        for(int i = 0; i < numCourses; i++) {
            vector<bool> visiting(numCourses, false);
            if(!visited[i]) {
                if(!dfs(vertex, visiting, visited, s, i)) {
                    return res;
                }
            }
        }
        
        while(!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
    
    bool dfs(vector<vector<int>>& vertex, vector<bool>& visiting, vector<bool>& visited, stack<int>& s, int label) {
        if(visiting[label] && !visited[label]) {
            return false;
        }
        visiting[label] = true;
        for(auto next : vertex[label]) {
            if(!visited[next]) {
                if(!dfs(vertex, visiting, visited, s, next)) {
                    return false;
                }
            }
        }
        visited[label] = true;
        s.push(label);
        return true;
    }
};