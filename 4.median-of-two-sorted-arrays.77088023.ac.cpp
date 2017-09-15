class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int i1 = 0, i2 = 0;
        int k = (n1 + n2) / 2;
        bool even = n1 + n2 == k * 2;
        while(k) {
            if(i1 >= n1) {
                i2 += k - 1;
                return even ? (double)(nums2[i2] + nums2[i2+1]) / 2 : nums2[i2 + 1];
            }else if(i2 >= n2) {
                i1 += k - 1;
                return even ? (double)(nums1[i1] + nums1[i1+1]) / 2 : nums1[i1 + 1];
            }else {
                if(k == 1) {
                    if(nums1[i1] < nums2[i2]) {
                        if(i1 + 1 == n1) {
                            return even ? (double)(nums1[i1] + nums2[i2]) / 2 : nums2[i2];
                        }else {
                            return even ? (double)(nums1[i1] + min(nums1[i1+1], nums2[i2])) / 2 : min(nums1[i1+1], nums2[i2]);
                        }
                    }else {
                        if(i2 + 1 == n2) {
                            return even ? (double)(nums2[i2] + nums1[i1]) / 2 : nums1[i1];
                        }else {
                            return even ? (double)(nums2[i2] + min(nums2[i2+1], nums1[i1])) / 2 : min(nums2[i2+1], nums1[i1]);
                        }
                    }
                }
                int i1_next = i1 + k / 2 >= n1 ? n1 : i1 + k / 2;
                int i2_next = i2 + k / 2 >= n2 ? n2 : i2 + k / 2;
                if(nums1[i1_next - 1] <= nums2[i2_next - 1]) {
                    k -= i1_next - i1;
                    i1 = i1_next;
                }else {
                    k -= i2_next - i2;
                    i2 = i2_next;
                }
            }
            //cout <<"i1: " <<i1 <<", i2: " <<i2 <<", k: " << k<<endl;
        }
        return n1 == 0 ? nums2[i2] : nums1[i1];
    }
};

// /1 /2 /3 4 5 6

// /1 /3 5 7

// k = 5, k / 2 = 2
// k = 3, k / 2 = 1
// k = 2, k / 2 = 1
// k = 1, k / 2 = 0
