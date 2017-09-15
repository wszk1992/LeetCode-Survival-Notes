/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
private:
    unordered_map<int, int> unionMap;
    map<int, Interval> rootToRange;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        if(unionMap.count(val)) {
            return;
        }
        int left = unionMap.count(val - 1) ? findRoot(val-1) : -1;
        int right = unionMap.count(val + 1) ? findRoot(val+1) : -1;
        if(left == -1 && right != -1) {
            unionMap[val] = right;
            rootToRange[right].start--;
        } else if(left != -1 && right == -1) {
            unionMap[val] = left;
            rootToRange[left].end++;
        } else if(left != -1 && right != -1){
            //combine two range
            unionMap[val] = left;
            unionMap[right] = left;
            rootToRange[left].end = rootToRange[right].end;
            rootToRange.erase(right);
        } else {
            unionMap[val] = val;
            rootToRange[val] = Interval(val, val);
        }
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> res;
        for(auto it : rootToRange) {
            res.push_back(it.second);
        }
        return res;
    }
    
    int findRoot(int val) {
        while(val != unionMap[val]) {
            val = unionMap[val];
        }
        return val;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */