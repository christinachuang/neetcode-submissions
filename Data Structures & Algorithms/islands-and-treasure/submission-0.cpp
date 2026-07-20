class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // Conduct bfs starts from 0s -> all 1 steps -> all 2 steps ...
        // so it won't be replicate
        if(grid.size() == 0 || grid[0].size() == 0)
            return;
        queue<pair<int, int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0)
                    q.push({i, j});
            }
        }
        int INF = (1 << 31) - 1;
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto& [row, col] = q.front();
                grid[row][col] = min(grid[row][col], steps);
                if(row + 1 < grid.size() && grid[row + 1][col] == INF)
                    q.push({row + 1, col});
                if(row - 1 >= 0 && grid[row - 1][col] == INF)
                    q.push({row - 1, col});
                if(col + 1 < grid[0].size() && grid[row][col + 1] == INF)
                    q.push({row, col + 1});
                if(col - 1 >= 0 && grid[row][col - 1] == INF)
                    q.push({row, col - 1});
                q.pop();
            }
            steps++;
        }
    }
};
