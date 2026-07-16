class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> output;
        vector<int> curr;
        dfs(candidates, target, 0, curr, output);
        return output;
    }
    void dfs(vector<int>& candidates, int target, int idx, vector<int>& curr, 
            vector<vector<int>>& output){
        if(target == 0){
            output.push_back(curr);
            return;
        }
        for(int i = idx; i < candidates.size() && target - candidates[i] >= 0; i++){
            curr.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, curr, output);
            curr.pop_back();
            while(i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
                i++;
        }
        return;
    }
};
