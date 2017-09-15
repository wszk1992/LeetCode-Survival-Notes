class Solution {
public:
    int lengthOfLastWord(string s) {
        int counter=0;
        bool begin_count=false;
        if(s.empty())
            return 0;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(!begin_count&&s[i]!=' ')
            {
                begin_count=true;
            }
            if(begin_count&&s[i]!=' ')
            {
                counter++;
            }
            if(begin_count&&s[i]==' ')
                break;
        }
        return counter;
    }
};