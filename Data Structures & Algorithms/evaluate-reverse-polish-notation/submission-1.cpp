class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> Stack;
        if(tokens.empty())
            return 0;
        int i = 0;
        unordered_map<string, function<int(int, int)>> operators = {
            {"+", [](int a, int b){return a + b;}},
            {"-", [](int a, int b){return a - b;}},
            {"*", [](int a, int b){return a * b;}},
            {"/", [](int a, int b){return a / b;}}
        };
        while(i < tokens.size()){
            if(!operators.count(tokens[i]))
                Stack.push(stoi(tokens[i]));
            else{
                int a, b;
                if(Stack.size() > 1){
                    b = Stack.top();
                    Stack.pop();
                    a = Stack.top();
                    Stack.pop();
                    // calculation
                    Stack.push(operators[tokens[i]](a, b));
                }
            }
            i++;
        }
        return Stack.top();
    }
};
