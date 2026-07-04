class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int max_len = 1;
        for(int i = 1; i < nums.size(); i++){
            int max_len_before = 0;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i])
                    max_len_before = max(dp[j], max_len_before);
            }
            dp[i] = max_len_before + 1;
            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }
};
