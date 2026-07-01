class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        unordered_map<char, int> charMap_s1;
        for(auto& c : s1)
            charMap_s1[c]++;
        unordered_map<char, int> charMap_s2;
        int left = 0;
        for(int i = 0; i < s2.size(); i++){
            if(!charMap_s1.count(s2[i])){
                left = i + 1;
                charMap_s2.clear();
                continue;
            }
            charMap_s2[s2[i]]++;
            while(left <= i && charMap_s2[s2[i]] > charMap_s1[s2[i]]){
                charMap_s2[s2[left]]--;
                left++;
            }
            if(i - left + 1 == s1.size())
                return true;
        }
        return false;
    }
};
