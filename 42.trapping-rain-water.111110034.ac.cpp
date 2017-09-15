class Solution {
public:
    //trap[i] = max(min(leftMaxHeight[i], rightMaxHeight[i]) - height[i], 0);
    
    int trap(vector<int>& height) {
        if(height.empty()) {
            return 0;
        }
        int traps = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while(left <= right) {
            if(leftMax <= rightMax) {
                traps += max(min(leftMax, rightMax) - height[left], 0);
                // cout << left << ","<< max(min(leftMax, rightMax) - height[left], 0) << endl;
                leftMax = max(leftMax, height[left++]);
            } else {
                traps += max(min(leftMax, rightMax) - height[right], 0);
                // cout << right << ","<< max(min(leftMax, rightMax) - height[right], 0) << endl;
                rightMax = max(rightMax, height[right--]);
            }
        }
        return traps;
    }
};