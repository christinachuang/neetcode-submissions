class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges){
        int n = edges.size();
        vector<int> parent(n + 1, 0);
        vector<int> rank(n + 1, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
        for(int i = 0; i < n; i++){
            int root1 = find(edges[i][0], parent);
            int root2 = find(edges[i][1], parent);
            if(root1 == root2)
                return edges[i];
            unionSets(root1, root2, rank, parent);
        }
        return {};
    }
private:
    int find(int x, vector<int>& parent){
        if(parent[x] != x)
            parent[x] = find(parent[x], parent);
        return parent[x];
    }
    void unionSets(int x, int y, vector<int>& rank, vector<int>& parent){
        if(rank[x] < rank[y])
            parent[x] = y;
        else if(rank[x] > rank[y])
            parent[y] = x;
        else{
            parent[y] = x;
            rank[x]++;
        }
    }
};