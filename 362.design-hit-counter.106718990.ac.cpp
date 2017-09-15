class HitCounter {
public:
    vector<int> clk;
    vector<int> hits;
    /** Initialize your data structure here. */
    HitCounter() {
        clk = vector<int>(300, 0);
        hits = vector<int>(300, 0);
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int t = timestamp % 300;
        if(clk[t] == timestamp) {
            hits[t]++;
        } else {
            clk[t] = timestamp;
            hits[t] = 1;
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int count = 0;
        for(int i = 0; i < 300; i++) {
            if(timestamp - clk[i] < 300) {
                count += hits[i];
            }
        }
        return count;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */