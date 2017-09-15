class Solution {
public:
    string originalDigits(string s) {
        string res;
        unordered_map<char, string> even({
            {'z',"zero"},
            {'w',"two"},
            {'u',"four"},
            {'x',"six"},
            {'g',"eight"}
        });
        unordered_map<char, string> odd({
            {'o',"one"},
            {'h',"three"},
            {'f',"five"},
            {'s',"seven"}
        });
        unordered_map<string, int> digit({
            {"zero",0},
            {"one",1},
            {"two",2},
            {"three",3},
            {"four",4},
            {"five",5},
            {"six",6},
            {"seven",7},
            {"eight",8},
            {"nine",9}
        });
        vector<int> nums(10, 0);
        vector<int> alpha(26, 0);
        for(char c : s) {
            alpha[c - 'a']++;
            if(even.count(c)) {
                for(char cc : even[c]) {
                    alpha[cc - 'a']--;
                }
                nums[digit[even[c]]]++;
            }
        }
        for(int i = 0; i < alpha.size(); i++) {
            char ch = i + 'a';
            int n = alpha[i];
            if(odd.count(ch)) {
                for(char c : odd[ch]) {
                    alpha[c - 'a'] -= n;
                }
                nums[digit[odd[ch]]] += n;
            }
        }
        nums[9] += alpha['e'-'a'];
        for(int i = 0; i < nums.size(); i++) {
            while(nums[i]--) {
                res += '0' + i;
            }
        }
        return res;
    }
};