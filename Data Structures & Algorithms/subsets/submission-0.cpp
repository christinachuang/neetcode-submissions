class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // use a queue to calculate subsets
        // record idx of the last item
        vector<vector<int>> output;
        queue<pair<vector<int>, int>> q;
        output.push_back({});
        if(nums.empty())
            return output;
        for(int i = 0; i < nums.size(); i++)
            q.push({{nums[i]}, i});
        while(!q.empty()){
            auto& [arr, idx] = q.front();
            for(int i = idx + 1; i < nums.size(); i++){
                arr.push_back(nums[i]);
                q.push({arr, i});
                arr.pop_back();
            }
            output.push_back(arr);
            q.pop();
        }
        return output;
    }
};
