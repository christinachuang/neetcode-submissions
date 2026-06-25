class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size() == 1)
            return {0};
        vector<int> prefix(nums.size(), 1);
        int suffix = 1;
        for(int i = 1; i < nums.size(); i++)
            prefix[i] = prefix[i - 1] * nums[i - 1];
        for(int i = nums.size() - 1; i >= 0; i--){
            prefix[i] *= suffix;
            suffix *= nums[i];
        }
        return prefix;
    }
};
