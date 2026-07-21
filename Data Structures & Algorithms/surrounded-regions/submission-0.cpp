class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0)
            return;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if((i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1) && board[i][j] == 'O')
                    dfs(board, i, j);
            }
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '-')
                    board[i][j] = 'O';
            }
        }
    }
    void dfs(vector<vector<char>>& board, int row, int col){
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != 'O')
            return;
        board[row][col] = '-';
        dfs(board, row + 1, col);
        dfs(board, row - 1, col);
        dfs(board, row, col + 1);
        dfs(board, row, col - 1);
    }
};
