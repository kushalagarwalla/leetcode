class Solution {
public:
    bool isSafe(int row,int col, vector<vector<char>>& board, int val)
    {
        char arr[10]={'0','1','2','3','4','5','6','7','8','9'};
        for(int i=0;i<board.size();i++)
        {
            //check row
            if(board[row][i]==arr[val])
                return false;
            //check col
            if(board[i][col]==arr[val])
                return false;
            //check matrix 3*3
            if(board[3*(row/3)+i/3][3*(col/3) + i%3]==arr[val])
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        char arr[10]={'0','1','2','3','4','5','6','7','8','9'};
        int n=board[0].size();
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<n;col++)
            {
                //
                if(board[row][col]=='.')
                {
                    for(int val=1;val<=9;val++)
                    {
                        if(isSafe(row,col,board,val))
                            {
                                board[row][col]=arr[val];
                                //recursive call
                                bool isSolutionPossible=solve(board);
                                if(isSolutionPossible)
                                {
                                    return true;
                                }
                                else
                                {
                                    //backtrack
                                    board[row][col]='.';
                                }
                            }
                    }
                    return false;
                }
                
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};