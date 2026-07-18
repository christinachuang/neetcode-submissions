class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> output;
        if(digits.empty())
            return output;
        string curr;
        unordered_map<char, string> lookup = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };
        dfs(lookup, digits, curr, 0, output);
        return output;
    }
    void dfs(unordered_map<char, string>& lookup, string digits, string curr, int idx, vector<string>& output){
        if(curr.size() == digits.size()){
            output.push_back(curr);
            return;
        }
        for(auto& c : lookup[digits[idx]]){
            curr.push_back(c);
            dfs(lookup, digits, curr, idx + 1, output);
            curr.pop_back();
        }
    }
};
