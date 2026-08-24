class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
            return 0;
        // before + curr <= curr => before is no need
        int max_sum = INT_MIN, curr_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            curr_sum = max(nums[i], curr_sum + nums[i]);
            /*if(curr_sum + nums[i] <= nums[i])
                curr_sum = nums[i];
            else
                curr_sum += nums[i];*/
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
};