class NumArray {
public:
    NumArray(vector<int> &nums) {
        vec.push_back(0);
        for(auto num : nums)
            vec.push_back(num + vec.back());
    }
    int sumRange(int i, int j) {
        return vec[j+1] - vec[i];
    }
    
    private: vector<int> vec;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);