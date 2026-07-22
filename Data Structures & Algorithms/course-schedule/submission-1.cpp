class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.empty())
            return true;
        unordered_map<int, unordered_set<int>> lookup;
        vector<int> count(numCourses, 0);
        for(auto& x : prerequisites){
            lookup[x[1]].insert(x[0]);
            count[x[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < count.size(); i++){
            if(count[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            auto& x = q.front();
            for(auto& item : lookup[x]){
                count[item]--;
                if(count[item] == 0)
                    q.push(item);
            }
            q.pop();
        }
        for(auto& tmp : count){
            if(tmp != 0)
                return false;
        }
        return true;
    }
};
