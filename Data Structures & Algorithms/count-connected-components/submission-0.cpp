class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // dfs
        // adjacency list + components + visited
        // check: cycle
        unordered_map<int, vector<int>> adj;
        int components = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                components++;
            }
        }
        return components;
    }
    void dfs(int idx, unordered_map<int, vector<int>>& adj, vector<bool>& visited){
        if(visited[idx])    
            return;
        visited[idx] = true;
        for(auto& x : adj[idx])
            dfs(x, adj, visited);
        return;
    }
};
