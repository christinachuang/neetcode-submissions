class Solution {
public:
    int numDecodings(string s) {
        // dp[i] could be combinations of [i] and [i-1~i]
        // dp[i] = dp[i - 1] + dp[i - 2](if(s[i-1~i] is valid))
        if(s.size() == 0)
            return 0;
        vector<int> dp(s.size(), 0);
        dp[0] = (s[0] == '0') ? 0 : 1;
        for(int i = 1; i < dp.size(); i++){
            int curr = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if(s[i] != '0')
                dp[i] += dp[i - 1];
            if(s[i - 1] != '0' && curr >= 1 && curr <= 26)
                dp[i] += (i == 1) ? 1 : dp[i - 2];
        }
        return dp[s.size() - 1];
    }
};
