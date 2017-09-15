class MinStack {
    stack<int> mst;
    stack<int> st;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if(mst.empty() || x <= mst.top()) {
            mst.push(x);
        }
    }
    
    void pop() {
        if(st.top() == mst.top()) {
            mst.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */