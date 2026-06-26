class Solution {
public:
    bool isValid(string s) {
        stack<char> Parentheses;
        int i = 0;
        unordered_map<char, char> lookup = {{')', '('}, {'}', '{'}, {']', '['}};
        while(i < s.size()){
            if(!lookup.count(s[i]))
                Parentheses.push(s[i]);
            else{
                if(Parentheses.empty() ||
                    Parentheses.top() != lookup[s[i]]
                    )
                    return false;
                Parentheses.pop();
            }
            i++;
        }
        return Parentheses.empty();
    }
};
