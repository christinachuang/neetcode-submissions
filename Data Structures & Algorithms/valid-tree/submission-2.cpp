class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // connected and no cycles
        unordered_map<int, unordered_set<int>> lookup;
        vector<int> count(n, 0);
        if(edges.size() != n - 1)
            return false;
        if(n == 1)
            return true;
        for(auto& tmp : edges){
            lookup[tmp[0]].insert(tmp[1]);
            lookup[tmp[1]].insert(tmp[0]);
            count[tmp[0]]++;
            count[tmp[1]]++;
        }
        queue<int> q;
        int finished = 0;
        for(int i = 0; i < n; i++){
            if(count[i] == 1)
                q.push(i);
        }
        while(!q.empty()){
            auto& idx = q.front();
            for(auto& next : lookup[idx]){
                count[next]--;
                count[idx]--;
                if(count[next] == 1)
                    q.push(next);
            }
            q.pop();
            finished++;
        }
        return finished == n;
    }
};
/*
edges=[[0,1],[0,2],[0,3],[1,4]]
0 - 1
| \   \ 
2.  3.  4
0 : 1,2,3
1 : 0,4
2 : 0
3 : 0
4 : 1
0 0
1 0
2 0
3 0
4 0
2/3/4/0/1
1
     1.
  /  | 
2    3.
1 0
2 0
3 0
*/