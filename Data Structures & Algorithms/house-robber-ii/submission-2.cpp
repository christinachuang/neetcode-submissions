class Solution {
public:
    int FindMaxMoney(int start, int end, vector<int>& nums, vector<int>& dp){
        for(int i = 0; i < start; i++)
            dp[i] = 0;
        for(int i = start; i <= end; i++){
            if(i == start)
                dp[i] = nums[i];
            else if(i == start + 1)
                dp[i] = max(nums[i - 1], nums[i]);
            else
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[end];
    }
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        else if(nums.size() == 1)
            return nums[0];
        vector<int> dp(nums.size(), 0);
        return max(FindMaxMoney(0, nums.size() - 2, nums, dp), 
                    FindMaxMoney(1, nums.size() - 1, nums, dp));
    }
};