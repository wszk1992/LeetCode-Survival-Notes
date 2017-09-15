class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> text;
        int len = 0;
        int start = 0;
        for(int i = 0; i < words.size(); i++) {
            if(len + words[i].length() <= maxWidth) {
                //insert the words[i] into current line
                len += words[i].length() + 1;
            } else {
                //add spaces between words 
                string curLine;
                int size = 0;
                for(int j = start; j < i; j++) {
                    size += words[j].length();
                }
                int spaces = maxWidth - size;
                int slots = i - start - 1;
                if(slots == 0) {
                    curLine = words[start] + getSpaces(spaces);
                } else {
                    int spacesPerSlot = spaces / slots;
                    int extraSpaces = spaces % slots;
                    for(int j = start; j < i - 1; j++) {
                        curLine += words[j] + getSpaces(spacesPerSlot + (extraSpaces-- > 0 ? 1 : 0) );
                    }
                    curLine += words[i-1];
                }
                //insert current line into text
                text.push_back(curLine);
                //reset len, set start
                len = words[i].length() + 1;
                start = i;
            }
        }
        //handle the last line
        string lastLine;
        for(int i = start; i < words.size() - 1; i++) {
            lastLine += words[i] + ' ';
        }
        lastLine += words[words.size() - 1];
        lastLine += getSpaces(maxWidth - lastLine.length());
        text.push_back(lastLine);
        return text;
    }
    
    string getSpaces(int num) {
        string s;
        while(num--) {
            s += ' ';
        }
        return s;
    }
};