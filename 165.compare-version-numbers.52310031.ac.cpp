class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> version1_level=parse_version(version1);
        vector<string> version2_level=parse_version(version2);
        if(version1_level.empty()||version2_level.empty())
            return 0;
        for(int i=0;i<version1_level.size()&&i<version2_level.size();i++){
            if(stoi(version1_level[i])>stoi(version2_level[i]))
                return 1;
            else if(stoi(version1_level[i])<stoi(version2_level[i]))
                return -1;
        }
        if(version1_level.size()>version2_level.size())
            return 1;
        else if (version1_level.size()<version2_level.size())
            return -1;
        else
            return 0;
    }
        
        
    vector<string> parse_version(string version)
    {
        vector<string> vec;
        int former_pos=0;
        int i=0;
        vec.push_back(version);
        for(;;)
        {
            size_t found = vec[i].find('.',former_pos);
            if(found==string::npos)
                break;
            else{
                vec.push_back(vec[i].substr(found+1));
                vec[i].erase(vec[i].begin()+found,vec[i].end());
            }
            i++;    
        }
        while(stoi(vec[i])==0&&i>0)
        {
            vec.pop_back();
            i--;
        }
        return vec;
    }
};