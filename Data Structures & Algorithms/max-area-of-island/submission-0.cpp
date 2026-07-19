class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        if(grid.size() == 0 || grid[0].size() == 0)
            return max_area;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j])
                    max_area = max(max_area, dfs(grid, i, j));
            }
        }
        return max_area;
    }
    int dfs(vector<vector<int>>& grid, int row, int col){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0)
            return 0;
        grid[row][col] = 0;
        return 1 + dfs(grid, row + 1, col) + 
                   dfs(grid, row - 1, col) +
                   dfs(grid, row, col - 1) + 
                   dfs(grid, row, col + 1);
    }
};
