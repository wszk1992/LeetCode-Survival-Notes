class Solution {
public:
    int calculate(string s) {
        s += '+';
        pair<int, char> calc(0, '+');
        pair<int, char> cur(1, '*');
        int num = 0;
        for(char c : s) {
            if(c == ' ') {
                continue;
            } else if(c == '+' || c == '-') {
                num = cur.second == '*' ? cur.first * num : cur.first / num;
                calc.first += calc.second == '+' ? num : -num;
                calc.second = c;
                num = 0;
                cur = make_pair(1, '*');
            } else if(c == '*' || c == '/') {
                cur.first = cur.second == '*' ? cur.first * num : cur.first / num;
                cur.second = c;
                num = 0;
            } else {
                num = num * 10 + c - '0';
            }
        }
        return calc.first;
    }
};