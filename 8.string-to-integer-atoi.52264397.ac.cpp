class Solution {
public:
    int myAtoi(string str) {
        bool pos=true;
        int integer=0;
        int num=0;
        int digit;
        int max = INT_MAX;
        bool needcheck;
        string::iterator it;
        // discards as many whitespace characters as necessary until the first non-whitespace character is found
        for(it=str.begin();it!=str.end();it++)
            if(*it!=' ') break;
        // all whitespace return 0 
        if(it==str.end()){ 
            cout<<"all is space"<<endl;
            return 0;
        }
        //optional + or -
        else if(*it=='+'){   
            pos = true;
            it++;
        }
        else if(*it=='-'){
            pos = false;
            it++;
        }
        //non number character return 0
        else if (*it<'0'||*it>'9'){
            cout<<"not numerical character"<<endl;
            return 0;
        }
        //count number of numerical digits
        for(string::iterator iter = it;*iter>='0'&&*iter<='9'&&iter!=str.end();iter++)
            num++;
        //return INT_MAX or INT_MIN if out of range
        if(num>10) {
            return pos?INT_MAX:INT_MIN;
        }
        else if (num<10)
            needcheck = false;
        else
            needcheck = true;
        for(int i=num;*it>='0'&&*it<='9'&&it!=str.end();it++,i--){
            if(needcheck){
                digit=max/ten_power(i-1);
                if(*it-'0'>digit)
                    return pos?INT_MAX:INT_MIN;
                else if (*it-'0'<digit)
                    needcheck = false;
                else
                    needcheck = true;
            }
            integer += ((*it)-'0') * ten_power(i-1);
            max -= ten_power(i-1)*(max/ten_power(i-1));
            
        }
        return pos?integer:-integer;
    }
    int ten_power(int n)
    {
        int sum=1;
        for(int i=0;i<n;i++)
        {
            sum*=10;
        }
        return sum;
    }
};