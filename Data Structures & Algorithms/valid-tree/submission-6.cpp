class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // adjacency list
        // dfs: with a visited_vertex => check if exists a cycle and connected
        if(edges.size() != n - 1)
            return false;
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_set<int> visited;
        if(!dfs(0, -1, visited, adj) || visited.size() != n)
            return false;
        return true;
    }
    bool dfs(int idx, int parent, unordered_set<int>& visited, unordered_map<int, vector<int>>& adj){
        if(visited.count(idx))
            return false;
        visited.insert(idx);
        for(auto& x : adj[idx]){
            if(x != parent && !dfs(x, idx, visited, adj))
                return false;
        }
        return true;
    }
};
