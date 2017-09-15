class Trie {
private:
    struct TrieNode {
        bool end;
        vector<TrieNode*> next;
        TrieNode() : end(false), next(vector<TrieNode*>(26, NULL)) {}
    };
    TrieNode* root;
public:
    
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for(char c : word) {
            if(!p->next[c-'a']) {
                p->next[c-'a'] = new TrieNode();
            }
            p = p->next[c-'a'];
        }
        p->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = root;
        for(char c : word) {
            if(p->next[c-'a']) {
                p = p->next[c-'a'];
            } else {
                return false;
            }
        }
        return p->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(char c : prefix) {
            if(p->next[c-'a']) {
                p = p->next[c-'a'];
            } else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */