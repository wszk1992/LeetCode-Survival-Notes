class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0, startCount = 0, startIndex = -1;
        int tank = 0;
        int maxTank = -1;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += gas[i] - cost[i];
        }
        while(i < n || (tank > 0 && i < 2 * n)) {
            //cout << i % n << endl;
            int cur = gas[i % n] - cost[i % n];
            //cout << tank << "," << cur << endl;
            if(cur + tank < 0) {
                tank = 0;
            }else {
                if(tank == 0) {
                    startCount = i;
                }
                tank += cur;
                if(tank > maxTank) {
                    //cout << "startIndex:" << startIndex << endl;
                    startIndex = startCount;
                    maxTank = tank;
                }
            }
            i++;
        }
        return sum < 0 ? -1 : startIndex;
    }
};