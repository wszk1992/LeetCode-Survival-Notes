
class cmp {
public:
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k, 0);
        int i1 = 0, i2 = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        for(int i = 0; i <= k; i++) {
            if(n1 >= i && n2 >= k - i) {
                vector<int> v1 = maxNum(nums1, i);
                vector<int> v2 = maxNum(nums2, k - i);
                vector<int> v = merge(v1, v2);
                // display(v1);
                // display(v2);
                // display(v);
                if(isLargerVector(v, res)) {
                    res = v;
                }
            }
        }
        return res;
    }
    
    vector<int> maxNum(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        int end = -1;
        for(int i = 0; i < n;) {
            if(n - i + end + 1 == k) {
                res.insert(res.end(), nums.begin() + i, nums.end());
                break;
            }else {
                if(end != -1 && nums[i] > res[end]) {
                    res.pop_back();
                    end--;
                }else {
                    if(end < k - 1) {
                        res.push_back(nums[i]);
                        end++;
                    }
                    i++;
                }
            }
        }
        return res;
    }
    
    vector<int> merge(vector<int>& v1, vector<int>& v2) {
        vector<int> res;
        int n1 = v1.size(), n2 = v2.size();
        int i1 = 0, i2 = 0;
        while(i1 < n1 && i2 < n2) {
            if(v1[i1] > v2[i2]) {
                res.push_back(v1[i1++]);
            }else if(v1[i1] < v2[i2]){
                res.push_back(v2[i2++]);
            }else {
                if(isLargerVector(vector<int>(v1.begin() + i1, v1.end()), vector<int>(v2.begin() + i2, v2.end()))) {
                    res.push_back(v1[i1++]);
                }else {
                    res.push_back(v2[i2++]);
                }
            }
        }
        while(i1 < n1) {
            res.push_back(v1[i1++]);
        }
        while(i2 < n2) {
            res.push_back(v2[i2++]);
        }
        return res;
    }
    
    bool isLargerVector(vector<int> v1, vector<int> v2) {
        int n = min(v1.size(), v2.size());
        for(int i = 0; i < n; i++) {
            if(v1[i] == v2[i]) {
                continue;
            }else {
                return v1[i] > v2[i];
            }
        }
        return v1.size() > v2.size();
    }
    
    void display(vector<int>& v) {
        cout << "[";
        for(int a : v) {
            cout << a << " ";
        }
        cout << "]" << endl;
    }
};