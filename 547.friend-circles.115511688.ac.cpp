
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<int> friends(n);
        vector<bool> roots(n, true);
        for(int i = 0; i < n; i++) {
            friends[i] = i;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(M[i][j]) unionFriends(roots, friends, i, j);
            }
        }
        
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(roots[i]) {
                count++;
            }
        }
        return count;
    }
    
    void unionFriends(vector<bool>& roots, vector<int>& friends, int i, int j) {
        int root1 = findRoot(friends, i);
        int root2 = findRoot(friends, j);
        friends[root1] = root2;
        //remove root1
        if(root1 != root2) roots[root1] = false;
    }
    
    
    
    int findRoot(vector<int>& friends, int i) {
        int root = i;
        while(friends[root] != root) {
            root = friends[root];
        }
        //compress
        friends[i] = root;
        return root;
    }
};