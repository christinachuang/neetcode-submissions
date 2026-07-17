class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        vector<int> curr;
        vector<vector<int>> output;
        dfs(nums, visited, curr, output);
        return output;
    }
    void dfs(vector<int>& nums, vector<bool>& visited, vector<int>& curr, 
                vector<vector<int>>& output){
        if(curr.size() == nums.size()){
            output.push_back(curr);
            return;
        }
        for(int i = 0; i < visited.size(); i++){
            if(visited[i] == false){
                curr.push_back(nums[i]);
                visited[i] = true;
                dfs(nums, visited, curr, output);
                curr.pop_back();
                visited[i] = false;
            }
        }
        return;
    }
};
