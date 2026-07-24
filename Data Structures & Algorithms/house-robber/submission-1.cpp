class Solution {
public:
    int rob(vector<int>& nums) {
        // dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
        vector<int> dp(nums.size(), 0);
        for(int i = 0; i < dp.size(); i++){
            if(i == 0)
                dp[i] = nums[i];
            else if(i == 1)
                dp[i] = max(nums[i - 1], nums[i]);
            else
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};