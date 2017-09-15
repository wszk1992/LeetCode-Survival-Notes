class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int start = 0;
        int val = INT_MAX;
        // do it by binary search
        for(int i = 0; i < arr.size(); i++) {
            if(abs(arr[i] - x) < val) {
                start = i;
                val = abs(arr[i] - x);
            }
        }
        
        int left = start - 1, right = start + 1;
        while(--k) {
            int leftVal = left >= 0 ? abs(arr[left] - x) : INT_MAX;
            int rightVal = right < arr.size() ? abs(arr[right] - x) : INT_MAX;
            if(leftVal <= rightVal) {
                left--;
            } else {
                right++;
            }
        }
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};