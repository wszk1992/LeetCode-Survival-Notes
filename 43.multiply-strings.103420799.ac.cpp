class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        string leadingZero;
        if(num2 == "0") {
            return "0";
        }
        for(int i = num1.size() - 1; i >= 0; i--) {
            string s = multiply(num2, num1[i]) + leadingZero;
            res = add(res, s);
            leadingZero += "0";
        }
        return res;
    }
    
    string multiply(string num, char c) {
        string res;
        int carry = 0;
        for(int i = num.size() - 1; i >= 0; i--) {
            int dig1 = num[i] - '0';
            int dig2 = c - '0';
            int mul = dig1 * dig2 + carry;
            res = string(1, mul % 10 + '0') + res;
            carry = mul / 10;
        }
        if(carry) {
            res = string(1, carry + '0') + res;
        }
        return res[0] == '0' ? "0" : res;
    }
    
    string add(string num1, string num2) {
        string res;
        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        while(i >= 0 || j >= 0 || carry) {
            int dig1 = i >= 0 ? num1[i--] - '0' : 0;
            int dig2 = j >= 0 ? num2[j--] - '0' : 0;
            int sum = dig1 + dig2 + carry;
            res = string(1, sum % 10 + '0') + res;
            carry = sum / 10;
        }
        return res;
    }
};