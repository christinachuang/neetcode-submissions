class Solution {
public:
    void helper(int start, int end, string& s, int& left, int& right){
        int max_size = right - left + 1;
        while(start >= 0 && end < s.size() && s[start] == s[end]){
            if(end - start + 1 > max_size){
                left = start;
                right = end;
            }
            start--;
            end++;
        }
    }
    string longestPalindrome(string s) {
        // dp[i][j] : if s[i~j] is palindrome
        // dp[i][j] = 1 if (dp[i + 1][j - 1] == 1) && (s[i] == s[j])
        // 1.)DP 2.)Two Pointers
        int left = 0, right = -1;
        for(int i = 0; i < s.size(); i++){
            helper(i, i, s, left, right);
            if(i > 0 && s[i - 1] == s[i])
                helper(i - 1, i, s, left, right);
        }
        return s.substr(left, right - left + 1);
    }
};
