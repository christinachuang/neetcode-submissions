class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        dfs(nums, curr, 0, output);
        return output;
    }
    void dfs(vector<int>& nums, vector<int>& curr, int idx, vector<vector<int>>& output){
        output.push_back(curr);
        if(idx == nums.size())
            return;
        for(int i = idx; i < nums.size(); i++){
            curr.push_back(nums[i]);
            dfs(nums, curr, i + 1, output);
            curr.pop_back();
            while(i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }
    }
};
