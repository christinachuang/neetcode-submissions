class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> output;
        vector<int> curr;
        dfs(nums, 0, curr, target, output);
        return output;
    }
    void dfs(vector<int>& nums, int idx, vector<int>& curr, int target,
            vector<vector<int>>& output){
        for(int i = idx; i < nums.size(); i++){
            curr.push_back(nums[i]);
            if(nums[i] == target)
                output.push_back(curr);
            else if(nums[i] < target)
                dfs(nums, i, curr, target - nums[i], output);
            curr.pop_back();
        }
        return;
    }
};
