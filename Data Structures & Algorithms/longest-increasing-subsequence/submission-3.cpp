class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int> dp(nums.size(), 1);
        int max_len = 1;
        //9,1,2,4,3,3,7
        //1,
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }
};
