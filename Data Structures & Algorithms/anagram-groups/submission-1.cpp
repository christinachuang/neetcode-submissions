class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> lookup;
        for(auto& w : strs){
            vector<int> curr(26, 0);
            for(auto& c : w){
                curr[c - 'a']++;
            }
            string tmp;
            for(auto& idx : curr){
                tmp += ',' + to_string(idx);
            }
            lookup[tmp].push_back(w);
        }
        vector<vector<string>> output;
        for(auto& [k, v] : lookup){
            output.push_back(v);
        }
        return output;
    }
};
