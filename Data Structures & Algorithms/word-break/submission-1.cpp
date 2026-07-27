class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // dp[i][j] = dp[i][k] && dp[k][j], where i <= k <= j
        vector<bool> dp(s.size() + 1, 0);
        unordered_set<string> lookup;
        int max_size = 0;
        for(auto& x : wordDict){
            lookup.insert(x);
            max_size = max(max_size, (int)x.size());
        }
        dp[0] = true;
        for(int i = 1; i < dp.size(); i++){
            for(int j = max(0, i - 1 - max_size); j < i; j++){
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
