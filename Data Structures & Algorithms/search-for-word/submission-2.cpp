class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || board[0].size() == 0)
            return false;
        string curr;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(dfs(board, i, j, 0, word))
                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, int row, int col, int idx, string& word){
        if(idx == word.size())
            return true;
        if(row >= board.size() || row < 0 || col >= board[0].size() || col < 0 || board[row][col] != word[idx])
            return false;
        char tmp = board[row][col];
        board[row][col] = '-';
        bool result = false;
        result = dfs(board, row + 1, col, idx + 1, word) ||
                 dfs(board, row - 1, col, idx + 1, word) ||
                 dfs(board, row, col + 1, idx + 1, word) ||
                 dfs(board, row, col - 1, idx + 1, word);
        board[row][col] = tmp;
        return result;
    }
};
