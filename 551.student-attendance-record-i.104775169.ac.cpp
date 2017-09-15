class Solution {
public:
    bool checkRecord(string s) {
        int numOfA = 0, numOfL = 0;
        for(char c : s) {
            if(c == 'A') {
                numOfA++;
            }
            if(c == 'L') {
                numOfL++;
            } else {
                numOfL = 0;
            }
            
            if(numOfA > 1 || numOfL > 2) {
                return false;
            }
        }
        return true;
    }
};