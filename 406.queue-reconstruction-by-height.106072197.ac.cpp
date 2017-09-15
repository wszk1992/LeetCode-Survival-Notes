class Solution {
public:
    struct Cmp {
        bool operator() (pair<int, int>& p1, pair<int, int>& p2) {
            return p1.first != p2.first ? p1.first < p2.first : p1.second > p2.second;
        }
    };
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> queue(people.size(), pair<int, int>(-1, -1));
        sort(people.begin(), people.end(), Cmp());
        for(auto p : people) {
            int count = 0;
            int i = 0;
            for(; i < queue.size(); i++) {
                if(queue[i].second != -1) {
                    continue;
                }
                if(count == p.second) {
                    break;
                }
                count++;
            }
            queue[i] = p;
        }
        return queue;
    }
};