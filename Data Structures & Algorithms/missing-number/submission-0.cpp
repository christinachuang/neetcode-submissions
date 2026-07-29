class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //xor[0~n] + xor[nums]
        int result = 0;
        for(int i = 0; i <= nums.size(); i++)
            result ^= i;
        for(auto& x : nums)
            result ^= x;
        return result;
    }
};

