class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        curr_min = min(curr_min, val);
        Stack.push({val, curr_min});
    }
    
    void pop() {
        if(!Stack.empty())
            Stack.pop();
        curr_min = Stack.empty() ? INT_MAX : Stack.top().second;
    }
    
    int top() {
        if(!Stack.empty())
            return Stack.top().first;
        else
            return INT_MAX;
    }
    
    int getMin() {
        if(!Stack.empty())
            return Stack.top().second;
        else
            return INT_MAX;
    }
private:
    stack<pair<int, int>> Stack;
    int curr_min = INT_MAX;
};
