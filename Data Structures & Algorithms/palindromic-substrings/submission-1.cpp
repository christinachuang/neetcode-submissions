class Solution {
public:
    void helper(int left, int right, string& s, int& count){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            count++;
            left--;
            right++;
        }
    }
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            helper(i, i, s, count);
            if(i > 0 && s[i] == s[i - 1])
                helper(i - 1, i, s, count);
        }
        return count;
    }
};
