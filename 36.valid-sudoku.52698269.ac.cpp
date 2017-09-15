class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return checkColumn(board)&&checkRow(board)&&checkBlock(board);
    }
    bool checkColumn(vector<vector<char>>& board){
        for(int i=0;i<9;i++)
        {
            unordered_set<char> set;
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                    continue;
                else if (set.find(board[i][j])!=set.end())
                {
                    cout<<"checkColumn false!"<<"i:"<<i<<" j:"<<j<<endl;
                    return false;
                }
                else
                    set.insert(board[i][j]);
            }
        }
        return true;
    }
    bool checkRow(vector<vector<char>>& board){
        for(int j=0;j<9;j++)
        {
            unordered_set<char> set;
            for(int i=0;i<9;i++)
            {
                if(board[i][j]=='.')
                    continue;
                else if (set.find(board[i][j])!=set.end())
                {
                    cout<<"checkRow false!"<<"i:"<<i<<" j:"<<j<<endl;
                    return false;
                }
                else
                    set.insert(board[i][j]);
            }
        }
        return true;
    }
    bool checkBlock(vector<vector<char>>& board){
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                unordered_set<char> set;
                for(int k=0;k<3;k++)
                {
                    for(int l=0;l<3;l++)
                    {
                        if(board[i+k][j+l]=='.')
                            continue;
                        else if (set.find(board[i+k][j+l])!=set.end())
                        {
                            cout<<"checkBlock false!"<<"i:"<<i<<" j:"<<j<<" k:"<<k<<" l:"<<l<<endl;
                            return false;
                        }
                        else
                            set.insert(board[i+k][j+l]);
                    }
                }
            }
        }
        return true;
    }
};