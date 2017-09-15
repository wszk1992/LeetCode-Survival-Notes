class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        string s_new;
        for(int i=0;i<s.size();i++)
        {
            if(s_new.find(s[i])==s_new.npos)
            {
                if(s_new.size()==0)
                    s_new.push_back(s[i]);
                else{
                    int j;
                    for(j=0;j<s_new.size();j++)
                    {
                        if(s[i]<s_new[j])
                        {
                            s_new.insert(j,1,s[i]);
                            break;
                        }
                    }
                    if(j==s_new.size())
                        s_new.insert(j,1,s[i]);
                }
            }
        }
        return s_new;
    }
};