class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // priority_queue<idx in points, dist>;
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < points.size(); i++){
            int dist = (pow(points[i][0], 2) + pow(points[i][1], 2));
            pq.push({dist, i});
            if(pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> output;
        while(!pq.empty()){
            auto& [dist, idx] = pq.top();
            output.push_back(points[idx]);
            pq.pop();
        }
        return output;
    }
};
