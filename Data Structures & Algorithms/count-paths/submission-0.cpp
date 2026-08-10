class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0)
            return 0;
        vector<int> dp(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0)
                    dp[j] = 1;
                else
                    dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};
