class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // find the sum
        int target = 0;
        for(auto& x : nums)
            target += x;
        if(target % 2 != 0)
            return false;
        target = target / 2;
        // dp: dp[i] = dp[i] || dp[i - j]
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(auto& x : nums){
            for(int i = target; i - x >= 0; i--)
                dp[i] = (dp[i] || dp[i - x]);
        }
        return dp[target];
    }
};