class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        // stack
        stack<pair<int, int>> Stack;
        for(int i = 0; i < temperatures.size(); i++){
            while(!Stack.empty() && Stack.top().first < temperatures[i]){
                auto [k, v] = Stack.top();
                result[v] = i - v;
                Stack.pop();
            }
            Stack.push({temperatures[i], i});
        }
        return result;
    }
};
