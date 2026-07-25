class Solution {
public:
    void helper(int left, int right, string& s, vector<string>& out){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            string curr = s.substr(left, right - left + 1);
            out.push_back(curr);
            left--;
            right++;
        }
    }
    int countSubstrings(string s) {
        vector<string> out;
        for(int i = 0; i < s.size(); i++){
            helper(i, i, s, out);
            if(i > 0 && s[i] == s[i - 1])
                helper(i - 1, i, s, out);
        }
        return out.size();
    }
};
