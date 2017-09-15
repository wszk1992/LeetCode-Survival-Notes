class Solution {
public:
    string convert(string s, int numRows) {
        string zs;
        vector<int> vec;
        int unit = (numRows-1)*2;
        if(unit == 0)   return s;
        for(int row=0;row<numRows&&row<s.length();row++)
        {
            for(int col=0; col<(s.length()-1-0.5*unit)/unit+2;col++)
            {
                if(row==0){
                    if(unit*col<s.length())
                        vec.push_back(unit*col);
                }
                else if (row==numRows-1)
                {
                    if(unit*(col+0.5)<s.length())
                        vec.push_back(unit*(col+0.5));
                }
                else if (col==0)
                {   if(unit*col+row<s.length())
                        vec.push_back(unit*col+row);
                }
                else
                {
                    if(unit*col-row<s.length())
                        vec.push_back(unit*col-row);
                    if(unit*col+row<s.length())
                        vec.push_back(unit*col+row);
                }
            }
        }
        
        for(int i=0;i<vec.size();i++)
            {
//                cout<<vec[i]<<endl;
                zs.push_back(s[vec[i]]);
            }
        return zs;
    }
};