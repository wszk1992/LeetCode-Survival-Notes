class Solution {
public:
    int calculate(string s) {
        stack<pair<int, char>> calc;
        calc.push(make_pair(0, '+'));
        s += '+';
        int num = 0;
        for(char c : s) {
            if(c == ' ') {
                continue;
            } else if(c == '+' || c == '-') {
                calc.top().first += calc.top().second == '+' ? num : -num;
                calc.top().second = c;
                num = 0;
            } else if(c == '(') {
                calc.push(make_pair(0, '+'));
                num = 0;
            } else if(c == ')') {
                num = calc.top().first + (calc.top().second == '+' ? num : -num);
                calc.pop();
            } else {
                num = num * 10 + (c - '0');
            }
        }
        return calc.top().first;
    }
};