class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //sorted?
        // all items of nums are valid?
        // must have answer?
        unordered_map<int, int> lookup;
        for(auto& x : nums)
           lookup[x]++;
        priority_queue<pair<int, int>> pq;
        for(auto& [k, v] : lookup)
            pq.push({v, k});
        vector<int> output;
        for(int i = 0; i < k; i++){
            if(!pq.empty()){
                output.push_back(pq.top().second);
                pq.pop();
            }
        }
        return output;
    }
};
