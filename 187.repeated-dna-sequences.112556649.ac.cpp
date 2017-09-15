class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<int, int> count;
        int mask = 0;
        for(int i = 0; i < 20; i++) {
            mask |= 1 << i;
        }
        int seq = 0;
        for(int i = 0; i < 10; i++) {
            int bits = toBits(s[i]);
            seq <<= 2;
            seq |= bits;
        }
        count[seq]++;
        for(int i = 10; i < s.length(); i++) {
            int bits = toBits(s[i]);
            seq <<= 2;
            seq &= mask;
            seq |= bits;
            // cout << bitset<20>(seq) << endl;
            if(++count[seq] == 2) {
                // cout <<"got: " <<bitset<20>(seq) << endl;
                res.push_back(toString(seq));
            }
        }
        return res;
    }
    
    int toBits(char c) {
        return c == 'A' ? 0 : c == 'C' ? 1 : c == 'G' ? 2 : 3;
    }
    
    char toChar(int bits) {
        return bits == 0 ? 'A' : bits == 1 ? 'C' : bits == 2 ? 'G' : 'T';
    }
    
    string toString(int seq) {
        string s;
        for(int i = 18; i >= 0; i -= 2) {
            int bits = (seq >> i) & 3;
            s.push_back(toChar(bits));
        }
        return s;
    }
};