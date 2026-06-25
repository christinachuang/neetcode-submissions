class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> rows;
        unordered_map<int, unordered_set<int>> cols;
        unordered_map<int, unordered_set<int>> cubes;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0';
                //check for rows
                if(rows[num].count(i) ||
                   cols[num].count(j) ||
                   cubes[num].count((i / 3) * 10 + (j / 3))
                )
                    return false;
                else{
                    rows[num].insert(i);
                    cols[num].insert(j);
                    cubes[num].insert((i / 3) * 10 + (j / 3));
                }
            }
        }
        return true;
    }
};
