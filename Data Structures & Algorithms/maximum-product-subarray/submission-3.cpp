class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int gMax = nums[0];
        int currMax = 1, currMin = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0)
                swap(currMax, currMin);
            if(nums[i] == 0){
                gMax = max(gMax, 0);
                currMin = 1;
                currMax = 1;
            }
            else{
                currMin = min(nums[i], currMin * nums[i]);
                currMax = max(nums[i], currMax * nums[i]);
                gMax = max(currMax, gMax);
            }
        } 
        return gMax;
    }
};