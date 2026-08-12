class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.empty())
            return 0;
        int total = 0;
        for(auto& num : nums)
            total += num;
        if(abs(target) > total)
            return 0;
        vector<int> curr_dp(total * 2 + 1, 0), next_dp(total * 2 + 1, 0);
        curr_dp[total] = 1;
        for(auto& num : nums){
            for(int i = 0; i < curr_dp.size(); i++){
                if(curr_dp[i] > 0 && i + num < curr_dp.size())
                    next_dp[i + num] += curr_dp[i];
                if(curr_dp[i] > 0 && i - num >= 0)
                    next_dp[i - num] += curr_dp[i];
            }
            curr_dp = next_dp;
            fill(next_dp.begin(), next_dp.end(), 0);
        }
        return curr_dp[total + target];
    }
};