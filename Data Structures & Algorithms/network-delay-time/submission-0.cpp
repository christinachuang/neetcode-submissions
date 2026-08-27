class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Dijkstra Algo: adjacency list, dist vector, priority queue
        if(n <= 1)
            return 0;
        if(times.empty())
            return -1;
        vector<vector<pair<int, int>>> adjacency(n + 1);
        for(auto& time : times)
            adjacency[time[0]].push_back({time[1], time[2]});
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while(!pq.empty()){
            auto [d, v] = pq.top();
            pq.pop();
            if(d > dist[v])
                continue;
            dist[v] = d;
            for(auto& [next_v, next_d] : adjacency[v]){
                int tmp_dis = dist[v] + next_d;
                if(tmp_dis < dist[next_v]){
                    dist[next_v] = tmp_dis;
                    pq.push({dist[next_v], next_v});
                }
            }

        }
        int max_dist = 0;
        for(int i = 1; i < dist.size(); i++){
            if(dist[i] == INT_MAX)
                return -1;
            max_dist = max(max_dist, dist[i]);
        }
        return max_dist;
    }
};