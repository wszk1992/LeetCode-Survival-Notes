class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int count = 0;
        for(int d : data) {
            int mask = 1 << 7;
            int leadingOnes = 0;
            while(d & mask) {
                leadingOnes++;
                mask >>= 1;
            }
            if(count) {
                if(leadingOnes != 1) {
                    return false;
                }
                count--;
            } else {
                if(leadingOnes == 1 || leadingOnes > 4) {
                    return false;
                }
                count = leadingOnes == 0 ? 0 : leadingOnes - 1;
            }
        }
        return count == 0;
    }
};