class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int add=1;
        vector<int> plusone;
        for(int i=digits.size()-1;i>=0;i--)
        {
            plusone.insert(plusone.begin(),(digits[i]+add)%10);
            add = (digits[i]+add)/10;
        }
        if(add==1)
            plusone.insert(plusone.begin(),add);
        return plusone;
    }
};