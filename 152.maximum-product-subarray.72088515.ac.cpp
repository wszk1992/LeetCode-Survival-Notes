class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //if nums[i] < 0  cur- = cur+ * nums[i]   cur+ = cur- * nums[i]
        //if nums[i] > 0  cur- = cur- * nums[i]   cur+ = cur+ * nums[i]
        int maxNeg = 1;
        int maxPos = -1;
        int curNeg = 1;
        int curPos = -1;
        for(int i = 0; i < nums.size(); i++) {
            int neg = curNeg;
            int pos = curPos;
            if(nums[i] < 0) {
                curNeg = pos <= 0 ? nums[i] : pos * nums[i];
                curPos = neg == 1 ? -1 : neg * nums[i];
            }else if(nums[i] > 0){
                curNeg = neg == 1 ? 1 : neg * nums[i];
                curPos = pos <= 0 ? nums[i] : pos * nums[i];
            }else {
                curNeg = 0;
                curPos = 0;
            }
            maxNeg = min(maxNeg, curNeg);
            maxPos = max(maxPos, curPos);
        }
        return maxPos == -1 ? maxNeg : maxPos;
    }
};

//-2 3 -2 4 -5
//neg -2 -6 -6 -24 -240
//pos 0  3  12 48  120
