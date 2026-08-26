class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lookup;
        for(int i = 0; i < s.size(); i++)
            lookup[s[i]] = i;
        vector<int> result;
        int start = 0, curr_end = 0;
        for(int i = 0; i < s.size(); i++){
            curr_end = max(curr_end, lookup[s[i]]);
            if(curr_end == i){
                result.push_back(curr_end - start + 1);
                start = i + 1;
            }
        }
        return result;
    }

};
