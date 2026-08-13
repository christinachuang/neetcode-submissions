class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for(int i = 0; i <= word1.size(); i++){
            for(int j = 0; j <= word2.size(); j++){
                if(i == 0)
                    dp[i][j] = j;
                else if(j == 0)
                    dp[i][j] = i;
                else if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min({
                        dp[i - 1][j - 1],
                        dp[i][j - 1],
                        dp[i - 1][j]}
                    );
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
// insert -> (i, j + 1)
// delete -> (i + 1, j)
// replace -> (i + 1, j + 1)
// for each dp[i][j] => min steps to form word1[0~i] == word2[0~j]