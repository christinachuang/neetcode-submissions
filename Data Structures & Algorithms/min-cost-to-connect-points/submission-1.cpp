class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        if(points.empty())
            return 0;        
        vector<int> min_dist(points.size(), INT_MAX);
        vector<bool> visited(points.size(), false);
        min_dist[0] = 0;
        int total_cost = 0;
        int used_edges = 0;
        while(used_edges < points.size()){
            auto iter = min_element(min_dist.begin(), min_dist.end());
            int idx = iter - min_dist.begin();
            int val = *iter;
            visited[idx] = true;
            min_dist[idx] = INT_MAX;
            total_cost += val;
            used_edges++;
            for(int i = 0; i < min_dist.size(); i++){
                if(!visited[i]){
                    min_dist[i] = min(min_dist[i], abs(points[idx][0] - points[i][0]) + abs(points[idx][1] - points[i][1]));
                }
            }
        }
        return total_cost;
        
        /*
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
        */
    }
};
