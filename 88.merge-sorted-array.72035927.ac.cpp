class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i, j;
        for(i = 0, j = 0; i < m + j && j < n; i++) {
            if(nums1[i] > nums2[j]) {
                nums1.insert(nums1.begin() + i, nums2[j]);
                j++;
            }
        }
        while(j < n) {
            nums1[i++] = nums2[j++];
        }
        nums1.resize(m + n);
    }
};