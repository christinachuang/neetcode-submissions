class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        // a map to store nums[i] : i
        // a queue to traverse possible combinations
        // avoid duplicated : do not choose idx < tail of combination
        vector<vector<int>> output;
        if(nums.empty())
            return output;
        // set map
        unordered_map<int, int> lookup;
        for(int i = 0; i < nums.size(); i++)
            lookup[nums[i]] = i;
        // initialize queue
        queue<pair<int, vector<int>>> q;
        for(auto& x : nums){
            if(target - x == 0)
                output.push_back({x});
            else if(target - x > 0)
                q.push({target - x, {x}});
        }
        // traverse combinatinos
        while(!q.empty()){
            auto& [left, arr] = q.front();
            for(int i = lookup[arr.back()]; i < nums.size(); i++){
                arr.push_back(nums[i]);
                if(left - nums[i] > 0)
                    q.push({left - nums[i], arr});
                else if(left - nums[i] == 0)
                    output.push_back(arr);
                arr.pop_back();
            }
            q.pop();
        }
        return output;
    }
};
