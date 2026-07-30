class KthLargest {
public:
    // min heap
    KthLargest(int k, vector<int>& nums): size(k) {
        for(auto& x : nums){
            pq.push(x);
            if(pq.size() > size)
                pq.pop();
        }
    }
    int add(int val){
        pq.push(val);
        if(pq.size() > size)
            pq.pop();
        return pq.top();
    }
private:
    int size;
    priority_queue<int, vector<int>, greater<int>> pq;
};
