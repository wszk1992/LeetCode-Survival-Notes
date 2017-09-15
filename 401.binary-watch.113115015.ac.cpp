class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        //time --> xxxx(hours) xxxxxx(minutes)
        vector<string> times;
        helper(times, 0, num, 1);
        return times;
    }

    void helper(vector<string>& times, int time, int num, int bit) {
        if((bit << num) > (1 << 10)) return;
        if(num == 0) {
            if((time >> 6) >= 12 || (time & 63) >= 60) return;
            string hour = to_string(time >> 6);
            string minute = (time & 63) >= 10 ? to_string(time & 63) : "0" + to_string(time & 63);
            times.push_back(hour + ":" + minute);
            return;
        }
        //LED off in this bit
        helper(times, time, num, bit << 1);
        //LED on in this bit
        time |= bit;
        helper(times, time, num - 1, bit << 1);
    }
};