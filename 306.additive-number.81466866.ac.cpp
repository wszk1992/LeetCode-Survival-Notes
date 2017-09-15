class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.length();
        for(int i = 0; i < n; i++) {
            string first = num.substr(0, i + 1);
            if(invalid(first)) {
                return false;
            }
            for(int j = i + 1; j < n; j++) {
                string second = num.substr(i + 1, j - i);
                if(invalid(second)) {
                    break;
                }
                int start = j + 1;
                first = num.substr(0, i + 1);
                second = num.substr(i + 1, j - i);
                for(int k = start; k < n; k++) {
                    string third = num.substr(start, k - start + 1);
                    if(invalid(third)) {
                        break;
                    }
                    
                    string sum = add(first, second);
                    //out << first <<"+"<<second<<"="<<sum<<" >=< "<<third<<endl;
                    int compare = cmp(sum, third);
                    if(compare == 1) {
                        continue;
                    }else if(compare == -1) {
                        break;
                    }else if(k == n - 1){
                        return true;
                    }else {
                        first = second;
                        second = third;
                        start = k + 1;
                    }
                }
            }
        }
        return false;
    }
    
    bool invalid(string& s) {
        return s.length() > 1 && s[0] == '0';
    }
    
    string add(string& s1, string& s2) {
        int i1 = s1.length() - 1, i2 = s2.length() - 1;
        string res = i1 > i2 ? s1 : s2;
        int i = res.length() - 1;
        int carry = 0;
        while(i1 >= 0 || i2 >= 0) {
            int a1 = i1 >= 0 ? s1[i1] - '0' : 0;
            int a2 = i2 >= 0 ? s2[i2] - '0' : 0;
            int sum = a1 + a2 + carry;
            res[i] = sum % 10 + '0';
            carry = sum / 10;
            i1--;
            i2--;
            i--;
        }
        if(carry) {
            res = "1" + res;
        }
        return res;
    }
    
    int cmp(string& s1, string& s2) {
        if(s1.length() != s2.length()) {
            return s1.length() > s2.length() ? 1 : -1;
        }else {
            for(int i = 0; i < s1.length(); i++) {
                if(s1[i] != s2[i]) {
                    return s1[i] > s2[i] ? 1 : -1;
                }
            }
        }
        return 0;
    }
};
