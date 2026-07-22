class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> lookup;
        vector<int> count(numCourses, 0);
        vector<int> output;
        for(auto& course : prerequisites){
            lookup[course[1]].insert(course[0]);
            count[course[0]]++;
        }
        queue<int> q;
        int finished = 0;
        for(int i = 0; i < count.size(); i++){
            if(count[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            auto& idx = q.front();
            output.push_back(idx);
            for(auto& x : lookup[idx]){
                count[x]--;
                if(count[x] == 0)
                    q.push(x);
            }
            q.pop();
            finished++;
        }
        if(finished == numCourses) return output;
        else return {};
    }
};
