class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int p;
        int s;
        string word;
        unordered_map<char,string> hashmap1;
        unordered_map<string,char> hashmap2;
        for(p=0,s=0;p<pattern.length()&&s<str.length();p++)
        {
            word = getWord(str,s);
            cout<<"word: "<<word<<";"<<endl;
            if(hashmap1.find(pattern[p])==hashmap1.end()&&hashmap2.find(word)==hashmap2.end())
            {
                hashmap1.insert({pattern[p],word});
                hashmap2.insert({word,pattern[p]});
            }
            else if(hashmap1[pattern[p]]!=word||hashmap2[word]!=pattern[p])
                return false;
            s += word.length();
            while(s<str.length()&&str[s]==' ')
                s++;   
        }
        cout<<"p = "<<p<<" s = "<<s<<endl;
        if(p==pattern.length()&&s==str.length())
            return true;
        else
            return false;
    }
    string getWord(string str, int index)
    {
        if(index<0||index>=str.length()||str[index]==' ')
            return "";
        int i=index;
        while(str[i]!=' '&&i!=str.length()) i++;
        return str.substr(index,i-index);
    }
};