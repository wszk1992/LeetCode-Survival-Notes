class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        for(char c : magazine) {
            if(map.count(c)) {
                map[c]++;
            }else {
                map[c] = 1;
            }
        }
        for(char c : ransomNote) {
            if(!map.count(c) || map[c] == 0) {
                return false;
            }else {
                map[c]--;
            }
        }
        return true;
    }
};