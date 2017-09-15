class Solution {
public:
    struct Trie {
        bool isEnd;
        Trie* next[26];
        Trie(bool end = false) : isEnd(end) {
            for(int i = 0; i < 26; i++) {
                next[i] = NULL;
            }
        }
    };
    vector<vector<string>> wordSquares(vector<string>& words) {
        Trie* root = new Trie();
        for(string word : words) {
            Trie* p = root;
            for(char c : word) {
                if(p->next[c - 'a'] == NULL) {
                    p->next[c - 'a'] = new Trie();
                }
                p = p->next[c - 'a'];
            }
            p->isEnd = true;
        }
        vector<vector<string>> squares;
        vector<string> square;
        backTracking(words, root, squares, square, 0);
        return squares;
        
    }
    
    void backTracking(vector<string>& words, Trie*& root, vector<vector<string>>& squares, vector<string>& square, int k) {
        if(k == words[0].length()) {
            squares.push_back(square);
            return;
        }
        Trie* p = root;
        string prefix;
        for(int i = 0; i < k; i++) {
            char c = square[i][k];
            prefix += c;
            p = p->next[c - 'a'];
            if(p == NULL) {
                return;
            }
        }
        vector<string> potantialWords;
        string s;
        getWordsWithPrefix(potantialWords, prefix, p, s);
        for(string word : potantialWords) {
            square.push_back(word);
            backTracking(words, root, squares, square, k + 1);
            square.pop_back();
        }
        
    }
    
    void getWordsWithPrefix(vector<string>& res, string& prefix, Trie* cur, string& s) {
        if(cur->isEnd) {
            res.push_back(prefix + s);
            return;
        }
        for(int i = 0; i < 26; i++) {
            if(cur->next[i] != NULL) {
                s.push_back(i + 'a');
                getWordsWithPrefix(res, prefix, cur->next[i], s);
                s.pop_back();
            }
        }
    }
    
};