class Solution {
public:
    struct Cmp {
        bool operator() (pair<int, int>& p1, pair<int, int>& p2) {
            return p1.first > p2.first;
        }
    };
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(1, 1);
        vector<int> index(primes.size(), 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
        for(int i = 0; i < primes.size(); i++) {
            pq.push(make_pair(primes[i], i));
        }
        while(ugly.size() < n) {
            int num = pq.top().first;
            int i = pq.top().second;
            if(num > ugly.back()) {
                ugly.push_back(num);
            }
            pq.pop();
            index[i]++;
            pq.push(make_pair(primes[i] * ugly[index[i]], i));
        }
        return ugly.back();
        
    }
};