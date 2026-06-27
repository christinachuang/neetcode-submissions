class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        for(int i = temperatures.size() - 2; i >= 0; i--){
            if(temperatures[i + 1] > temperatures[i])
                result[i] = 1;
            else{
                int idx = i + 1;
                while(idx < temperatures.size() && result[idx] != 0){
                    int next = idx + result[idx];
                    if(temperatures[i] < temperatures[next]){
                        result[i] = next - i;
                        break;
                    }
                    idx = next;
                }
            }
        }
        return result;
    }
};
