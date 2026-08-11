class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        if(coins.empty())
            return 0;
        dp[0] = 1;
        for(auto& coin : coins){
            for(int i = coin; i <= amount; i++){
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
        /* DP */   
        // dp[i]: total combinations that total up to i
        // dp[i] += dp[i - coins[j]] if
        //避免重複：比coin小的都不再計算

        /* DFS */
        /*
        int combs = 0;
        dfs(coins, 0, amount, combs);
        return combs;
    }
    void dfs(vector<int>& coins, int idx, int amount_left, int& combs){
        if(amount_left == 0){
            combs++;
            return;
        }
        if(idx == coins.size())
            return;
        for(int i = idx; i < coins.size(); i++){
            if(amount_left >= coins[i])
                dfs(coins, i, amount_left - coins[i], combs);
            else
                return;
        }
    }*/
};
