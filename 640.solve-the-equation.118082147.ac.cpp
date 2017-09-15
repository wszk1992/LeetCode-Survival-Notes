class Solution {
public:
    string solveEquation(string equation) {
        bool left = true;
        bool pos = true;
        int num = 0;
        int coeff = 0;
        int sum = 0;
        for(int i = 0; i <= equation.size(); i++) {
            char c = i == equation.size() ? '=' : equation[i];
            if(c == '=') {
                sum += pos ^ left ? -num : num;
                num = 0;
                pos = true;
                left = false;
            } else if(c == 'x') {
                if(i == 0 || !isdigit(equation[i-1])) {
                    num = 1;
                }
                coeff += pos ^ left ? -num : num;
                num = 0;
            } else if(c == '+' || c == '-') {
                sum += pos ^ left ? -num : num;
                num = 0;
                pos = c == '+';
            } else {
                num = num * 10 + c - '0';
            }
        }
        // cout << coeff << " * x + " << sum << " = 0 " << endl;
        //coeff * x + sum = 0
        if(coeff == 0) {
            return sum == 0 ? "Infinite solutions" : "No solution";
        } else {
            return "x=" + to_string(-sum / coeff);
        }
    }
};