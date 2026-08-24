class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty())
            return false;
        int size = nums.size();
        vector<bool> dp(size, false);
        dp[size - 1] = true;
        for(int i = size - 2; i >= 0; i--){
            for(int j = i + 1; j <= min(i + nums[i], size - 1); j++){
                if(dp[j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};