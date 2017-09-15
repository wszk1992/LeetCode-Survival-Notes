class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        row.reserve(rowIndex+1);
        row.push_back(1);
        for(int i=0;i<rowIndex;i++)
        {
            row = addline(row);
        }
        return row;
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