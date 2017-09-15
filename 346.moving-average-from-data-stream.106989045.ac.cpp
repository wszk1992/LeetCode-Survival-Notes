class MovingAverage {
public:
    int size;
    int sum;
    queue<int> window;
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        sum = 0;
    }
    
    double next(int val) {
        sum += val;
        window.push(val);
        if(window.size() > size) {
            sum -= window.front();
            window.pop();
        }
        return (double)sum / window.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */