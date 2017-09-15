class Solution {
public:
    int countArrangement(int N) {
        vector<bool> selected(N, 0);
        int count = 0;
        backTracking(N, selected, 1, count);
        return count;
    }
    
    void backTracking(int& N, vector<bool>& selected, int index, int& count) {
        if(index == N + 1) {
            count++;
            return;
        }
        for(int i = 1; i <= N; i++) {
            if(!selected[i - 1] && (i % index == 0 || index % i == 0)) {
                selected[i - 1] = 1;
                backTracking(N, selected, index + 1, count);
                selected[i - 1] = 0;
            }
        }
    }
};