class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int counter1 = 0, counter2 = 0;
        int cand1 = 0, cand2 = 1;
        for(auto num : nums) {
            if(num == cand1) {
                counter1++;
            }else if(num == cand2) {
                counter2++;
            }else if(counter1 == 0) {
                cand1 = num;
                counter1 = 1;
            }else if(counter2 == 0) {
                cand2 = num;
                counter2 = 1;
            }else {
                counter1--;
                counter2--;
            }
        }
        counter1 = counter2 = 0;
        for(auto num : nums) {
            if(num == cand1) {
                counter1++;
            }else if(num == cand2) {
                counter2++;
            }
        }
        vector<int> res;
        if(counter1 > nums.size() / 3) {
            res.push_back(cand1);
        }
        if(counter2 > nums.size() / 3) {
            res.push_back(cand2);
        }
        return res;
    }
};