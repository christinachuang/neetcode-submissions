class Solution {
public:
    vector<string> generateParenthesis(int n) {
        //dfs, record the left (s and )s
        vector<string> output;
        string curr;
        dfs(0, 0, n, curr, output);
        return output;
    }
    void dfs(int left, int right, int n, string& curr, vector<string>& output){
        if(curr.size() == n * 2){
            output.push_back(curr);
            return;
        }
        if(left < n){
            curr.push_back('(');
            dfs(left + 1, right, n, curr, output);
            curr.pop_back();
        }
        if(right < left){
            curr.push_back(')');
            dfs(left, right + 1, n, curr, output);
            curr.pop_back();
        }
    }
};
