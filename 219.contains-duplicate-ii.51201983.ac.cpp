class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i,j;
        unordered_map <int,int> map;
        unordered_map <int,int>::const_iterator got;
        for(i=0;i<nums.size();i++)
        {
            got = map.find(nums[i]);
            if(got == map.end())
            {
                map.insert({nums[i],i});
            }
            else
            {
                if(i-got->second<=k)
                    return true;
                else
                    {
                        map.erase(nums[i]);
                        map.insert({nums[i],i});
                    }
            }
        }
        return false;
    }
};