class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // num size >= 2?
        // range of num[i] => avoid overflow
        // 0. brute force (O(N^2) / O(N))
        // 1. sorting + trav (O(NlogN) / O(1 or N))
        // 2. lookup : unordered_set (O(N) / O(N))
        unordered_map<int, int> nums_lookup;
        for(int i = 0; i < nums.size(); i++){
            if(nums_lookup.count(nums[i]))
                return {nums_lookup[nums[i]], i};
            nums_lookup[target - nums[i]] = i;
        }
        return {};
    }
};
