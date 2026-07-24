class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int max_money = 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for(int i = 1; i < dp.size() - 1; i++){
            if(i == 1)
                dp[i] = max(nums[i - 1], nums[i]);
            else
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        max_money = dp[max((int)dp.size() - 2, 0)];
        dp[0] = 0;
        for(int i = 1; i < dp.size(); i++){
            if(i == 1)
                dp[i] = nums[i];
            else if(i == 2)
                dp[i] = max(nums[i - 1], nums[i]);
            else
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        max_money = max(max_money, dp[dp.size() - 1]);
        return max_money;
    }
};