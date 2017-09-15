class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        for(int i=0;i<s.length();i++)
        {
            if(map.find(s[i])==map.end())
                map.insert({s[i],1});
            else
                map[s[i]]++;
        }
        for(int i=0;i<t.length();i++)
        {
            if(map.find(t[i])==map.end())
                return false;
            else if(map[t[i]]==1)
                map.erase(t[i]);
            else
                map[t[i]]--;
        }
        if(map.empty())
            return true;
        else
            return false;
    }
};