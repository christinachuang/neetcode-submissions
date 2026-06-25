class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set;
        for(auto& x : nums)
            nums_set.insert(x);
        int max_len = 0;
        for(auto& x : nums_set){
            int tgt = x;
            int curr_len = 0;
            if(nums_set.count(tgt - 1))
                continue;
            while(nums_set.count(tgt++))
                curr_len++;
            max_len = max(max_len, curr_len);
        }
        return max_len;
    }
};
