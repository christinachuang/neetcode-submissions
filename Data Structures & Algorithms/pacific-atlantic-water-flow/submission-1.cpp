class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // pacific: r == 0 || c == 0
        // atlantic: r == heights.size() - 1 || c == heights[0].size() - 1
        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), 0));
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), 0));
        vector<vector<int>> output;
        if(heights.size() == 0 || heights[0].size() == 0)
            return output;
        for(int j = 0; j < heights[0].size(); j++){
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, heights.size() - 1, j);
        }
        for(int i = 0; i < heights.size(); i++){
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, heights[0].size() - 1);
        }
        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[0].size(); j++){
                if(pacific[i][j] && atlantic[i][j])
                    output.push_back({i, j});
            }
        }
        return output;
    }
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int r, int c){
        if(r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size() || ocean[r][c])
            return;
        ocean[r][c] = true;
        if(r + 1 < heights.size() &&  heights[r + 1][c] >= heights[r][c])
            dfs(heights, ocean, r + 1, c);
        if(r - 1 >= 0 &&  heights[r - 1][c] >= heights[r][c])
            dfs(heights, ocean, r - 1, c);
        if(c + 1 < heights[0].size() &&  heights[r][c + 1] >= heights[r][c])
            dfs(heights, ocean, r, c + 1);
        if(c - 1 >= 0 &&  heights[r][c - 1] >= heights[r][c])
            dfs(heights, ocean, r, c - 1);
    }
};
