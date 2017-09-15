class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0;
        unordered_set<int> dict;
        unordered_set<int> arrived;
        for(int num : nums) {
            dict.insert(num);
        }
        for(int num : nums) {
            if(arrived.count(num)) {
                continue;
            }
            arrived.insert(num);
            int len = 1;
            int left = num - 1;
            while(dict.count(left)) {
                arrived.insert(left);
                len++;
                left--;
            }
            int right = num + 1;
            while(dict.count(right)) {
                arrived.insert(right);
                len++;
                right++;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
    
};