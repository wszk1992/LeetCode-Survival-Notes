class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        string add(max(len1, len2), '0');
        int i = add.length() - 1;
        int i1 = len1 - 1;
        int i2 = len2 - 1;
        int carry = 0;
        while(i1 >= 0 || i2 >= 0) {
            int sum = (i1 >= 0 ? num1[i1] - '0' : 0) + (i2 >= 0 ? num2[i2] - '0' : 0) + carry;
            add[i--] += sum % 10;
            carry = sum / 10;
            i1--;
            i2--;
        }
        if(carry) {
            add = "1" + add;
        }
        return add;
    }
};