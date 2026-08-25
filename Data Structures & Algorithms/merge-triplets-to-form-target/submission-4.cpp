class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> result(target.size(), INT_MIN);
        for(int i = 0; i < triplets.size(); i++){
            bool valid = true;
            for(int j = 0; j < target.size(); j++){
                if(triplets[i][j] > target[j]){
                    valid = false;
                    break;
                }
            }
            if(valid == false)
                continue;
            for(int j = 0; j < target.size(); j++)
                result[j] = max(result[j], triplets[i][j]);
        }
        return result == target;
    }
};
