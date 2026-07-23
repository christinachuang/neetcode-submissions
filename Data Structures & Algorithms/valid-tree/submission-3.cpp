class Solution {
public:
    int find(int x, vector<int>& parent){
        if(parent[x] != x)
            parent[x] = find(parent[x], parent);
        return parent[x];
    }
    bool unionSets(int root1, int root2, vector<int>& rank, vector<int>& parent){
        if(rank[root1] > rank[root2]){
            parent[root2] = root1;
            rank[root1]++;
        }
        else{
            parent[root1] = root2;
            rank[root2]++;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        // parent[]: record parent of each node
        // rank[] or size[]: record rank or size of each node
        // component: count sets
        // 1. initialization
        vector<int> parent(n, 0);
        vector<int> rank(n, 0);
        int components = n;
        for(int i = 0; i < n; i++)
            parent[i] = i;
        // 2. find & union
        for(int i = 0; i < edges.size(); i++){
            int root1 = find(edges[i][0], parent);
            int root2 = find(edges[i][1], parent);
            if(root1 == root2)
                return false;
            else if(unionSets(root1, root2, rank, parent))
                components--;
        }
        return components == 1;
    }
};
