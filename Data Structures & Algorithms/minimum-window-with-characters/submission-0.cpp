class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size())
            return "";
        unordered_map<char, int> sSet;
        unordered_map<char, int> tSet;
        for(auto & c : t)
            tSet[c]++;
        int left = 0, out_l = 0, out_r = INT_MAX, matches = 0;
        for(int i = 0; i < s.size(); i++){
            sSet[s[i]]++;
            if(tSet.count(s[i]) && sSet[s[i]] == tSet[s[i]]){
                matches++;
                while(left <= i && matches == tSet.size()){
                    if(i - left < out_r - out_l){
                        out_r = i;
                        out_l = left;
                    }
                    if(tSet.count(s[left]) && sSet[s[left]] == tSet[s[left]])
                        matches--;
                    sSet[s[left]]--;
                    left++;
                }
            }
        }
        if(out_r == INT_MAX)
            return "";
        else
            return s.substr(out_l, out_r - out_l + 1);
    }
};
