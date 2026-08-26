class Solution {
public:
    bool checkValidString(string s) {
        stack<char> main;
        stack<char> backup;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')
                main.push(i);
            else if(s[i] == ')' && !main.empty())
                main.pop();
            else if(s[i] == ')' && main.empty()){
                if(backup.empty())
                    return false;
                else
                    backup.pop();
            }
            else
                backup.push(i);
        }
        while(!main.empty() && !backup.empty()){
            if(main.top() > backup.top())
                return false;
            main.pop();
            backup.pop();
        }
        return main.empty();
    }
};
