class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> freq;
        for(int num : nums) {
            freq[num]++;
        }
        for(auto f : freq) {
            pq.push(make_pair(f.second, f.first));
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};