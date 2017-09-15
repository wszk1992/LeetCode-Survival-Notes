class cmp {
public:
    bool operator() (long a, long b) {
       return a > b; 
    }
};

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0) {
            return 0;
        }
        priority_queue<long, vector<long>, cmp> q;
        long uglyNum = 0;
        q.push(1);
        while(n--) {
            while(q.top() == uglyNum) {
                q.pop();
            }
            uglyNum = q.top();
            q.push(uglyNum * 2);
            q.push(uglyNum * 3);
            q.push(uglyNum * 5);
            //cout << uglyNum << endl;
        }
        return uglyNum;
    }
};