class Solution {
public:
    string alienOrder(vector<string>& words) {
        if(words.empty()) {
            return "";
        }
        string order;
        vector<vector<bool>> graph(26, vector<bool>(26));
        //build graph
        for(int i = 0; i < words.size(); i++) {
            for(char c : words[i]) {
                graph[c-'a'][c-'a'] = 1;
            }
            if(i == 0) {
                continue;
            }
            int j = 0;
            while(j < words[i-1].size() && j < words[i].size() && words[i-1][j] == words[i][j]) {
                j++;
            }
            if(j == words[i-1].size()) {
                continue;
            }
            if(j == words[i].size()) {
                return "";
            }
            graph[words[i-1][j]-'a'][words[i][j]-'a'] = 1;
        }
        //use bfs to go through the graph
        //1. get the indegree of every node
        vector<int> indegrees(26, 0);
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                if(graph[i][j]) {
                    indegrees[j]++;
                }
            }
        }
        //every time get the letter with 1 indegree
        bitset<26> arrived;
        vector<int> oneIndegrees = findOneIndegree(indegrees, arrived);
        while(!oneIndegrees.empty()) { 
            for(int letter : oneIndegrees) {
                order.push_back(letter + 'a');
                for(int i = 0; i < 26; i++) {
                    if(graph[letter][i]) {
                        indegrees[i]--;
                    }
                }
            }
            oneIndegrees = findOneIndegree(indegrees, arrived);
        }
        for(int i = 0; i < 26; i++) {
            if(indegrees[i] != 0) {
                return "";
            }
        }
        // cout << arrived.count() << ", " <<order.size() << endl;
        return order;
    }
    
    vector<int> findOneIndegree(vector<int>& indegrees, bitset<26>& arrived) {
        vector<int> oneIndegrees;
        for(int i = 0; i < 26; i++) {
            if(indegrees[i] == 1 && !arrived[i]) {
                oneIndegrees.push_back(i);
                arrived[i] = 1;
                // cout << (char)('a' + i)<< " " ;
            }
        }
        // cout << endl;
        return oneIndegrees;
    }
};