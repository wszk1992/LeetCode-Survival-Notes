class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        if(n <= 2) {
            return res;
        }
        vector<int> candidate;
        backTracking(res, candidate, n);
        return res;
    }
    
    void backTracking(vector<vector<int>>& res, vector<int>& candidate, int n) {
        int i = candidate.empty() ? 2 : candidate.back();
        while(i <= sqrt(n)) {
            if(n % i == 0) {
                candidate.push_back(i);
                backTracking(res, candidate, n / i);
                candidate.pop_back();
            }
            i++;
        }
        if(candidate.size()) {
            candidate.push_back(n);
            res.push_back(candidate);
            candidate.pop_back();
        }
        
    }
    
};