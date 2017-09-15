class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> list;
        unordered_set<string> visited;
        for(string word : wordList) {
            list.insert(word);
        }
        int len = 1;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty() && !visited.count(endWord)) {
            int k = q.size();
            while(k--) {
                vector<string> next = nextLadder(list, visited, q.front());
                q.pop();
                for(string w : next) {
                    q.push(w);
                }
            }
            len++;
        }
        return visited.count(endWord) ? len : 0;
    }
    
    vector<string> nextLadder(unordered_set<string>& list, unordered_set<string>& visited, string word) {
        vector<string> next;
        for(int i = 0; i < word.length(); i++) {
            char c = word[i];
            for(int j = 0; j < 26; j++) {
                word[i] = 'a' + j;
                if(list.count(word) && !visited.count(word)) {
                    next.push_back(word);
                    visited.insert(word);
                }
            } 
            word[i] = c;
        }
        return next;
    }
};