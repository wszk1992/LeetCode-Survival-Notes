class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> list;
        for(string word : wordList) {
            list.insert(word);
        }
        unordered_map<string, int> wordLevel;
        unordered_map<string, vector<string>> paths;
        int level = 0;
        queue<string> q;
        q.push(beginWord);
        wordLevel[beginWord] = 0;
        //bfs to find all path to endWord
        while(!q.empty()) {
            unordered_set<string> nextLevelWords;
            int n = q.size();
            while(n--) {
                string cur = q.front();
                cout << cur << ",";
                q.pop();
                vector<string> next = nextLadder(cur, list, wordLevel, level);
                paths[cur] = next;
                for(string s : next) {
                    if(!nextLevelWords.count(s)) {
                        nextLevelWords.insert(s);
                        q.push(s);
                    }
                }
            }
            cout << endl;
            if(nextLevelWords.count(endWord)) {
                break;
            }
            level++;
        }
        
        vector<vector<string>> ladders;
        vector<string> ladder;
        ladder.push_back(beginWord);
        backTracking(ladders, ladder, paths, level, 0, beginWord, endWord);
        return ladders;
    }
    
    vector<string> nextLadder(string cur, unordered_set<string>& list, unordered_map<string, int>& wordLevel, int level) {
        vector<string> next;
        for(int i = 0; i < cur.length(); i++) {
            char c = cur[i];
            for(int j = 0; j < 26; j++) {
                cur[i] = 'a' + j;
                if(cur[i] != c && list.count(cur) && (!wordLevel.count(cur) || wordLevel[cur] > level)) {
                    wordLevel[cur] = level + 1;
                    next.push_back(cur);
                }
            }
            cur[i] = c;
        }
        return next;
    }
    
    void backTracking(vector<vector<string>>& ladders, vector<string>& ladder, unordered_map<string, vector<string>>& paths, int& level, int k, string& word, string& endWord) {
        if(k == level + 1) {
            ladders.push_back(ladder);
            return;
        }
        for(string next : paths[word]) {
            if(k < level || next == endWord) {
                ladder.push_back(next);
                backTracking(ladders, ladder, paths, level, k + 1, next, endWord);
                ladder.pop_back();
            }

        }
    }
};