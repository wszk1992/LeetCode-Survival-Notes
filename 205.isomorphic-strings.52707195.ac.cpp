class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> map;
        unordered_map<char,char> map_rev;
        if(s.length()!=t.length())
            return false;
        for(int i=0;i<s.length();i++)
        {
            if(map.find(s[i])==map.end())
                map.insert({s[i],t[i]});
            else if (t[i]!=map[s[i]])
                return false;
            if(map_rev.find(t[i])==map_rev.end())
                map_rev.insert({t[i],s[i]});
            else if (s[i]!=map_rev[t[i]])
                return false;
            
        }
        return true;
    }
};