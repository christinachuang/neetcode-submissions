class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // dp[i][j] = dp[i][k] && dp[k][j], where i <= k <= j
        vector<bool> dp(s.size() + 1, 0);
        unordered_set<string> lookup;
        for(auto& x : wordDict)
            lookup.insert(x);
        dp[0] = true;
        for(int i = 1; i < dp.size(); i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && lookup.count(s.substr(j, i - j))){
                    // j ~ i - 1
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[dp.size() - 1];
    }
};
