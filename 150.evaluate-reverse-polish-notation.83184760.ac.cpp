class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty()) {
            return 0;
        }
        stack<int> s;
        for(auto token : tokens) {
            if(isOperator(token)) {
                int r = s.top();
                s.pop();
                int l = s.top();
                s.pop();
                s.push(getResult(l, token, r));
            }else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
    
    bool isOperator(string s) {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
    
    int getResult(int l, string op, int r) {
        if(op == "+") {
            return l + r;
        }else if(op == "-") {
            return l - r;
        }else if(op == "*") {
            return l * r;
        }else {
            return l / r;
        }
    }
};