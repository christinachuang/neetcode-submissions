class Solution {
public:
    bool isAnagram(string s, string t) {
        // different len => x
        if(s.size() != t.size())
            return false;
        vector<int> characters(26, 0);
        for(auto& c : s)
            characters[c - 'a']++;
        for(auto& c : t){
            if(--characters[c - 'a'] < 0)
                return false;
        }
        for(auto& v : characters){
            if(v != 0)
                return false;
        }
        return true;
    }
};
