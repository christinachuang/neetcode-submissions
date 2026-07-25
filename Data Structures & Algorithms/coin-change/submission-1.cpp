class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //dp[i]: min count of coins to collect i dollars
        // dp[i] = min(dp[i - coins[j]])
        if(coins.empty())
            return -1;
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i < dp.size(); i++){
            for(auto& x : coins){
                if(i - x >= 0 && dp[i - x] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - x] + 1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
