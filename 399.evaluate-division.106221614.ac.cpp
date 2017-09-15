class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> res(queries.size(), -1.0);
        unordered_map<string, vector<pair<double, string>>> map;
        for(int i = 0; i < equations.size(); i++) {
            map[equations[i].first].push_back(make_pair(values[i], equations[i].second));
            map[equations[i].second].push_back(make_pair(1.0 / values[i], equations[i].first));
        }
        for(int i = 0; i < queries.size(); i++) {
            unordered_set<string> path;
            res[i] = map.count(queries[i].first) && map.count(queries[i].second) ? dfs(queries[i].first, queries[i].second, path, map) : -1.0;
        }
        return res;
    }
    
    double dfs(string dividend, string& divisor, unordered_set<string>& path, unordered_map<string, vector<pair<double, string>>>& map) {
        path.insert(dividend);
        if(dividend == divisor) {
            return 1.0;
        }
        for(int i = 0; i < map[dividend].size(); i++) {
            if(!path.count(map[dividend][i].second)) {
                double getRes = dfs(map[dividend][i].second, divisor, path, map);
                if(getRes != -1.0) {
                    return map[dividend][i].first * getRes;
                }
            }
        }
        path.erase(dividend);
        return -1.0;
    }
};