class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int gMax = nums[0];
        int currMax = 1, currMin = 1;
        for(int i = 0; i < nums.size(); i++){
            int tmp_max = currMax, tmp_min = currMin;
            if(nums[i] > 0){
                currMax = max(nums[i], tmp_max * nums[i]);
                currMin = min(nums[i], tmp_min * nums[i]);
                gMax = max(currMax, gMax);
            }
            else if(nums[i] < 0){
                currMin = min(nums[i], tmp_max * nums[i]);
                currMax = max(nums[i], tmp_min * nums[i]);
                gMax = max(currMax, gMax);
            }
            if(nums[i] == 0){
                gMax = max(gMax, 0);
                currMin = 1;
                currMax = 1;
            }
        } 
        return gMax;
    }
};