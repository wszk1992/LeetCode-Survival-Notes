class MedianFinder {
private:
    priority_queue<int,vector<int>,greater<int>> right;
    priority_queue<int> left;
    double median;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        median = 0;
    }
    
    void addNum(int num) {
        if(num > median) {
            right.push(num);
        } else {
            left.push(num);
        }
        if(left.size() - right.size() == 2) {
            right.push(left.top());
            left.pop();
        } else if(right.size() - left.size() == 2) {
            left.push(right.top());
            right.pop();
        }
        median = left.size() == right.size() ? double(left.top()+right.top())/2 : right.size() > left.size() ? right.top() : left.top();
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */