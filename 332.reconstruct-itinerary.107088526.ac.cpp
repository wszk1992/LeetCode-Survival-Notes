class Solution {
public:
    struct Cmp {
        bool operator() (pair<string, bool>& p1, pair<string, bool>& p2) {
            return p1.first < p2.first;
        }
    };
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        //@graph = key: from, value: (to, ticked used)
        unordered_map<string, vector<pair<string, bool>>> graph;
        for(auto t : tickets) {
            graph[t.first].push_back(make_pair(t.second, 0));
        }
        for(auto it = graph.begin(); it != graph.end(); it++) {
            sort(it->second.begin(), it->second.end(), Cmp());
        }
        vector<string> itinerary(1, "JFK");
        int size = tickets.size() + 1;
        dfs(graph, itinerary, size, "JFK");
        return itinerary;
    }
    
    bool dfs(unordered_map<string, vector<pair<string, bool>>>& graph, vector<string>& itinerary, int& size, string from) {
        if(itinerary.size() == size) {
            return true;
        }
        for(int i = 0; i < graph[from].size(); i++) {
            if(!graph[from][i].second) {
                // the ticket is not used
                itinerary.push_back(graph[from][i].first);
                graph[from][i].second = 1;
                if(dfs(graph, itinerary, size, graph[from][i].first)) {
                    return true;
                }
                graph[from][i].second = 0;
                itinerary.pop_back();
            }
        }
        return false;
    }
};