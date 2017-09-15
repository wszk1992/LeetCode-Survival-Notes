class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        vector<int> pos(n + 1, 0);
        for(int i = 0; i < n; i++) {
            pos[org[i]] = i;
        }
        int match = 0;
        vector<int> flag(n, 0);
        if(n == 1) {
            match -= 1;
            for(auto seq : seqs) {
                if(seq.size() == 0) continue;
                if(flag[0] == 0 && seq.size() == 1 && seq[0] == 1) {
                    flag[0] = 1;
                    match++;
                }
            }
        }
        for(auto seq : seqs) {
            for(int i = 0; i < seq.size(); i++) {
                if(seq[i] < 1 || seq[i] > n) return false;
                if(i == 0) continue;
                if(pos[seq[i]] <= pos[seq[i-1]]) return false;
                if(flag[pos[seq[i]]] == 0 && pos[seq[i]] - pos[seq[i-1]] == 1) {
                    flag[pos[seq[i]]] = 1;
                    match++;
                }
            }
        }
        return match == n - 1;
    }
};