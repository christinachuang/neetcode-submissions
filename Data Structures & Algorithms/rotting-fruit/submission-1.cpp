class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        queue<pair<int, int>> q;
        int fresh = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        if(fresh == 0)
            return 0;
        int rounds = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto& [r, c] = q.front();
                if(r + 1 < grid.size() && grid[r + 1][c] == 1){
                    grid[r + 1][c] = 2;
                    q.push({r + 1, c});
                    fresh--;
                }
                if(r - 1 >= 0 && grid[r - 1][c] == 1){
                    grid[r - 1][c] = 2;
                    q.push({r - 1, c});
                    fresh--;
                }
                if(c + 1 < grid[0].size() && grid[r][c + 1] == 1){
                    grid[r][c + 1] = 2;
                    q.push({r, c + 1});
                    fresh--;
                }
                if(c - 1 >= 0 && grid[r][c - 1] == 1){
                    grid[r][c - 1] = 2;
                    q.push({r, c - 1});
                    fresh--;
                }
                q.pop();
            }
            rounds++;
        }
        return fresh > 0 ? -1 : rounds - 1;
    }
};
