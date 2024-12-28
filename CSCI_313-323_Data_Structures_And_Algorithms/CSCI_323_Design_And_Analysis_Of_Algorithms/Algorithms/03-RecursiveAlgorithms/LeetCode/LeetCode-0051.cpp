class Solution {
    vector<vector<string>> result;       
    unordered_map<int, bool> ver;
    unordered_map<int, bool> upperLeft;
    unordered_map<int, bool> upperRight;    
    
    void solve(int row, int n, vector<string> &board){
        if (row >= n){
            result.push_back(board);
            return;
        } // end-if
            
        for (int col=0; col<n; col++){
            if (ver[col] == true) continue;
            if (upperLeft[row-col] == true) continue;
            if (upperRight[row+col] == true) continue;
            
            board[row][col] = 'Q';
            ver[col] = true;            
            upperLeft[row-col] = true;
            upperRight[row+col] = true;
            
            solve(row+1, n, board);
            
            board[row][col] = '.';
            ver[col] = false;            
            upperLeft[row-col] = false;
            upperRight[row+col] = false;            
        } // end-for
        
    } // end-solve    
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        string s(n, '.');
        for (int i=0; i<n; i++)
            board.push_back(s);
        
        solve(0, n, board);
        
        return result;
    } // end-solveNQueens
};