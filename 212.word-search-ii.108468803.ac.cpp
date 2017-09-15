class Solution {
public:
    struct TrieNode {
        bool isEnd;
        vector<TrieNode*> next;
        TrieNode(bool end = false) : isEnd(end), next(vector<TrieNode*>(26, NULL)) {}
    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty()) {
            return vector<string>();
        }
        TrieNode* root = new TrieNode();
        for(string word : words) {
            TrieNode* p = root;
            for(char c : word) {
                if(!p->next[c-'a']) {
                    p->next[c-'a'] = new TrieNode();
                }
                p = p->next[c-'a'];
            }
            p->isEnd = true;
        }
        vector<string> res;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                string word;
                dfs(res, word, board, root, i, j);
            }
        }
        return res;
    }
    
    void dfs(vector<string>& res, string& word, vector<vector<char>>& board, TrieNode* root, int i, int j) {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '-' || root->next[board[i][j]-'a'] == NULL) {
            return;
        }
        char curChar = board[i][j];
        board[i][j] = '-';
        word += curChar;
        if(root->next[curChar-'a']->isEnd) {
            res.push_back(word);
            root->next[curChar-'a']->isEnd = false;
        }
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(auto d : dir) {
            dfs(res, word, board, root->next[curChar-'a'], i + d[0], j + d[1]);
        }
        board[i][j] = curChar;
        word.pop_back();
    }
};