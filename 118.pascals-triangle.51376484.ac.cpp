class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        vector<int> line;
        for(int i=0;i<numRows;i++)
        {
            if(i==0)
                line.push_back(1);
            else
                line = addline(line);
            pascal.push_back(line);
        }
        return pascal;
    }
    
    vector<int> addline(vector<int> line)
    {
        vector<int> newline;
        newline.reserve(line.size()+1);
        newline.push_back(1);
        for(int i=0;i<line.size()-1;i++)
        {
            newline.push_back(line[i]+line[i+1]);
        }
        newline.push_back(1);
        return newline;
    }
};