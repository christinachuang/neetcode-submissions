class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty() || k == 0)
            return 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto& x : nums){
            pq.push(x);
            if(pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};
