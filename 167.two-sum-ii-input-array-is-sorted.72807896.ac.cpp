class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int front = 0;
        int end = numbers.size() - 1;
        while(front < end) {
            int sum = numbers[front] + numbers[end];
            if(sum > target) {
                end--;
            }else if(sum < target) {
                front++;
            }else {
                break;
            }
        }
        res.push_back(front + 1);
        res.push_back(end + 1);
        return res;
    }
};