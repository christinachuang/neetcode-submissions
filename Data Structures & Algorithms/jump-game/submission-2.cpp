class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty())
            return false;
        int max_reach = 0;
        for(int i = 0; i < nums.size(); i++){
            if(max_reach >= i)
                max_reach = max(max_reach, i + nums[i]);
            else
                return false;
        }
        return true;
    }
};
