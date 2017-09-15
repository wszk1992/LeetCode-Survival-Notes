class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        int current=n;
        while(current!=1)
        {
            if(set.find(current)==set.end())
                set.insert(current);
            else
                return false;
            current = replace(current);
        }
        return true;
    }
    int replace(int integer)
    {
        int unit;
        int sum=0;
        int x=integer;
        while(x!=0)
        {
            unit = x%10;
            x = x/10;
            sum+= unit*unit;
        }
        return sum;
    }
};