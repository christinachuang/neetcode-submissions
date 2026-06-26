class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        for(int i = 0; i < nums.size() - 2; i++){
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = nums.size() - 1;
            while(left < right){
                int curr_sum = nums[left] + nums[right];
                if(curr_sum == 0 - nums[i]){
                    output.push_back({nums[i], nums[left], nums[right]});
                    int tmp_left = nums[left], tmp_right = nums[right];
                    while(++left < right && nums[left] == nums[left - 1]);
                    while(--right > left && nums[right] == nums[right + 1]);
                }
                else if(curr_sum < 0 - nums[i])
                    left++;
                else
                    right--;
            }
        }
        return output;
    }
};
