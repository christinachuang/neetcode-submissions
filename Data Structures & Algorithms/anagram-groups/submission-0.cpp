class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> lookup;
        for(auto& w : strs){
            string curr(27, '0');
            for(auto& c : w){
                curr[c - 'a']++;
            }
            lookup[curr].push_back(w);
        }
        vector<vector<string>> output;
        for(auto& [k, v] : lookup){
            output.push_back(v);
        }
        return output;
    }
};
