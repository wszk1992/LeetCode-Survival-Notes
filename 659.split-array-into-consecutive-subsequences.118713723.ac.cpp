class Solution {
    struct Cmp {
        bool operator() (pair<int, int>& p1, pair<int, int>& p2) {
            return p1.first != p2.first ? p1.first > p2.first : p1.second > p2.second;
        }
    };
public:
    bool isPossible(vector<int>& nums) {
        priority_queue<pair<int, int>,vector<pair<int, int>>, Cmp> pq;
        int startCount = 0, endCount = 0;
        for(int i = 0; i < nums.size(); i++) {
            while(!pq.empty() && nums[i] > pq.top().first + 1) {
                if(pq.top().second < 3) {
                    return false;
                }
                pq.pop();
            }
            if(pq.empty() || nums[i] == pq.top().first) {
                pq.push(make_pair(nums[i], 1));
            } else {
                int count = pq.top().second + 1;
                pq.push(make_pair(nums[i], count));
                pq.pop();
            }
        }
        while(!pq.empty()) {
            if(pq.top().second < 3) {
                return false;
            }
            pq.pop();
        }
        return true;
    }
};