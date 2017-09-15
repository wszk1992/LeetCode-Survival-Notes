class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int limit = 1000000001;
        heaters.insert(heaters.begin(), -limit);
        heaters.push_back(2*limit);
        int maxDis = 0;
        int ih = 0;
        for(int i = 0; i < houses.size(); i++) {
            while(houses[i] > heaters[ih + 1]) {
                ih++;
            }
            int minDis = min(houses[i] - heaters[ih], heaters[ih + 1] - houses[i]);
            maxDis = max(maxDis, minDis);
        }
        return maxDis;
    }
};