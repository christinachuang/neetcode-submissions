class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //sorted?
        // all items of nums are valid?
        // must have answer?
        unordered_map<int, int> lookup;
        for(auto& x : nums)
           lookup[x]++;
        vector<vector<int>> bucket_sort(nums.size() + 1);
        for(auto& [key, val] : lookup){
            bucket_sort[val].push_back(key);
        }
        vector<int> output;
        for(int i = bucket_sort.size() - 1; i >= 0; i--){
            for(auto& curr : bucket_sort[i]){
               output.push_back(curr);
                    k--;
                if(k == 0)
                    return output;
            }
        }
        return output;
    }
};
