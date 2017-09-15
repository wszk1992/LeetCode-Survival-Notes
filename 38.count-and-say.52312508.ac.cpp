class Solution {
public:
    //recursive way
    string countAndSay(int n) {
        string str;
        string result;
        char count;
        char say;
        int begin=0;
        int found;
        if(n==1)
            return "1";
        else{
            str=countAndSay(n-1);
            for(;;){
                say = str[begin];
                int found=str.find_first_not_of(say,begin);
                if(found==string::npos)
                {
                    count = str.length()-begin+'0';
                    result.push_back(count);
                    result.push_back(say);
                    break;
                }
                else
                {
                    count = found-begin+'0';
                    result.push_back(count);
                    result.push_back(say);
                }
                begin = found;
            }
            return result;
        }
    }
};