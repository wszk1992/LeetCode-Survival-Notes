class MyQueue {
private:
    stack<int> main, cache;
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!main.empty()) {
            cache.push(main.top());
            main.pop();
        }
        main.push(x);
        while(!cache.empty()) {
            main.push(cache.top());
            cache.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = main.top();
        main.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        return main.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return main.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */