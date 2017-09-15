class StringIterator {
    int i;
    int i_next;
    int num;
    string s;
public:
    StringIterator(string compressedString) {
        i = 0;
        i_next = 0;
        num = 0;
        s = compressedString;
    }
    
    char next() {
        if(!hasNext()) {
            return ' ';
        }
        if(num == 0) {
            i = i_next;
            i_next += 1;
            while(i_next < s.length() && !isalpha(s[i_next])) {
                num = num * 10 + s[i_next] - '0';
                i_next++;
            }
        }
        num--;
        return s[i];
    }
    
    bool hasNext() {
        return !(num == 0 && i_next == s.length());
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */