class Solution {
public:
    struct Cmp {
        bool operator() (pair<int, int>& p1, pair<int, int>& p2) {
            return p1.first > p2.first;
        }
    };
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        //pair<num, index>
        // priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
        // for(int i = 0; i < nums.size(); i++) {
        //     while(!pq.empty() && nums[i] > pq.top().first) {
        //         res[pq.top().second] = nums[i];
        //         pq.pop();
        //     }
        //     pq.push(make_pair(nums[i], i));
        // }
        // for(int i = 0; i < nums.size() && !pq.empty(); i++) {
        //     while(!pq.empty() && nums[i] > pq.top().first) {
        //         res[pq.top().second] = nums[i];
        //         pq.pop();
        //     }
        // }
        
        stack<int> st;
        for(int i = 0; i < nums.size() * 2; i++) {
            int num = nums[i % nums.size()];
            while(!st.empty() && num > nums[st.top()]) {
                res[st.top()] = num;
                st.pop();
            }
            if(i < nums.size()) {
                st.push(i);
            }
        }
        return res;
    }
};