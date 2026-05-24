class Solution {
public:
    bool isSafeQueen(int n,int row, int col, vector<string> &board){
        int duprow = row;
        int dupcol = col;
        col = col-1;
        row = row -1;
        while(col>=0 && row >=0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row = duprow;
        col = dupcol-1;
        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        row = duprow+1;
        col = dupcol-1;
        while(col>=0 && row<=n-1){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
    return true;

    }

    void solve(int n,int col, vector<vector<string>> &ans, vector<string> &board){
        if(col == n) {
            ans.push_back(board);
            return;
        }
            for(int row = 0; row<n ; row++){
                if(isSafeQueen(n,row,col,board)){
                    board[row][col] = 'Q';
                    //col++;
                    solve(n,col+1,ans,board);
                    board[row][col] = '.';
            }
        } 
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(n,0,ans,board);
        return ans;
    }
    
};