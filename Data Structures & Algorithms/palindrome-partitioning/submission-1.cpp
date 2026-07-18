class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> output;
        vector<string> curr;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for(int i = s.size() - 1; i >= 0; i--){
            for(int j = s.size() - 1; j >= i; j--){
                if(i == j)
                    dp[i][j] = true;
                else if(j - i == 1)
                    dp[i][j] = (s[i] == s[j]);
                else
                    dp[i][j] = (dp[i + 1][j - 1]) && (s[i] == s[j]);
            }
        }
        dfs(dp, s, 0, curr, output);
        return output;
    }
    void dfs(vector<vector<bool>>& dp, string& s, int idx, vector<string>& curr, vector<vector<string>>& output){
        if(idx == s.size()){
            output.push_back(curr);
            return;
        }
        for(int i = idx; i < s.size(); i++){
            if(dp[idx][i]){
                curr.push_back(s.substr(idx, i - idx + 1));
                dfs(dp, s, i + 1, curr, output);
                curr.pop_back();
            }
        }
    }
};
