class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool positive = (numerator >= 0 && denominator > 0) || (numerator <= 0 && denominator < 0);
        long posNum = abs((long)numerator), posDenum = abs((long)denominator);
        string beforeDot = to_string(posNum / posDenum);
        posNum = posNum % posDenum; 
        string afterDot;
        unordered_map<long, long> map;
        int recycle = -1;
        while(posNum != 0) {
            map[posNum] = afterDot.length();
            afterDot += to_string(posNum * 10 / posDenum);
            posNum = posNum * 10 % posDenum;
            if(map.count(posNum)) {
                recycle = map[posNum];
                break;
            }
        }
        if(recycle != -1) {
            afterDot.insert(recycle, 1, '(');
            afterDot.push_back(')');
        }
        string res = (positive ? "" : "-") + beforeDot + (afterDot.empty() ? "" : ("." + afterDot));
        return res;
    }
};