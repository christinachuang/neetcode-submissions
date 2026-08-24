class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 0;
        int max_reach = 0;
        int curr = 0;
        for(int i = 0; i < nums.size(); i++){
            if(max_reach >= nums.size() - 1)
                return steps;
            if(i <= max_reach)
                curr = max(curr, i + nums[i]);
            if(i == max_reach){
                max_reach = max(max_reach, curr);
                steps++;
            }
        }
        return -1;
    }
};
