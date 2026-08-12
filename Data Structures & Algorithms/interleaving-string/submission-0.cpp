class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size())
            return false;
        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        dp[0][0] = true;
        for(int i = 0; i <= s1.size(); i++){
            for(int j = 0; j <= s2.size(); j++){
                if(i == 0 && j == 0)
                    continue;
                if(j > 0)
                    dp[i][j] = dp[i][j] |
                        (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1]));
                if(i > 0)
                    dp[i][j] = dp[i][j] | 
                        (dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1]));
            }
        }
        return dp[s1.size()][s2.size()];
    }
};

/*
    0 1 2 3 4
    x a a a a
x   t t t f f
b   f f 
b   f
b.  f
b.  f*/

