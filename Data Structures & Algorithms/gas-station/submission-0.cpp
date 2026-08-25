class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curr_tank = 0, start = 0;
        if(accumulate(gas.begin(), gas.end(), 0) < 
            accumulate(cost.begin(), cost.end(), 0))
            return -1;
        for(int i = 0; i < gas.size(); i++){
            curr_tank += (gas[i] - cost[i]);
            if(curr_tank < 0){
                curr_tank = 0;
                start = i + 1;
            }
        }
        if(start == gas.size())
            return -1;
        return start;
    }
};
