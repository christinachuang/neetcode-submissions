class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> curr;
        dfs(nums, -1, curr, output); 
        return output;
    }
    void dfs(vector<int>& nums, int idx, vector<int>& curr, vector<vector<int>>& output){
        output.push_back(curr);
        for(int i = idx + 1; i < nums.size(); i++){
            curr.push_back(nums[i]);
            dfs(nums, i, curr, output);
            curr.pop_back();
        }
        return;
    }
};
