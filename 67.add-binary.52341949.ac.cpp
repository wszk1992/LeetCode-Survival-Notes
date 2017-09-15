class Solution {
public:
    string addBinary(string a, string b) {
        string c;
        char unit;
        int add1,add2;
        int carry=0;
        int i,j;
        
        for(i=a.length()-1,j=b.length()-1;i>=0||j>=0;i--,j--)
        {
            add1 = i<0?0:a[i]-'0';
            add2 = j<0?0:b[j]-'0';
            unit = add1^add2^carry+'0';
            carry = add1+add2+carry>1?1:0;
            c.insert(c.begin(),unit);
        }
        if(carry)
            c.insert(c.begin(),carry+'0');
        return c;
    }
};