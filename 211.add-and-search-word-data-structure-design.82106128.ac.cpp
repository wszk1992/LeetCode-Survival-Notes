class WordDictionary {
    struct TrieNode {
        bool isEnd;
        TrieNode* next[26];
        TrieNode() {
            isEnd = false;
            for(int i = 0; i < 26; i++) {
                next[i] = NULL;
            }
        }
    };
    TrieNode* root;
public:
    
    
    WordDictionary() {
        root = new TrieNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* p = root;
        for(char c : word) {
            if(!p->next[c - 'a']) {
                p->next[c - 'a'] = new TrieNode();
            }
            p = p->next[c - 'a'];
        }
        p->isEnd = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(word, 0, root);
    }
    
    bool search(string& word, int startIndex, TrieNode* start) {
        if(start == NULL) {
            return false;
        }
        TrieNode* p = start;
        for(int i = startIndex; i < word.size(); i++) {
            if(word[i] == '.') {
                for(int k = 0; k < 26; k++) {
                    if(search(word, i + 1, p->next[k])) {
                        return true;
                    }
                }
                return false;
            }else {
                if(p->next[word[i] - 'a']) {
                    p = p->next[word[i] - 'a'];
                }else {
                    return false;
                }
            }
        }
        return p->isEnd;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");