class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        if(points.empty())
            return 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // (dist, idx)
        vector<bool> visited(points.size(), false);     
        pq.push({0, 0});
        int total_cost = 0;
        int used_edge = 0;
        while(!pq.empty() && used_edge < points.size()){
            auto [dist, idx] = pq.top();
            pq.pop();
            if(!visited[idx]){
                total_cost += dist;
                visited[idx] = true;
                used_edge++;
                for(int i = 0; i < visited.size(); i++){
                    if(!visited[i]){
                        pq.push({abs(points[i][0] - points[idx][0]) +
                            abs(points[i][1] - points[idx][1]), i});
                    }
                }
            }
        }
        return total_cost;
    }
};
