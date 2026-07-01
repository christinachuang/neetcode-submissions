class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, maxf = 0, longest = 0;
        unordered_map<char, int> charMap;
        for(int i = 0; i < s.size(); i++){
            charMap[s[i]]++;
            maxf = max(maxf, charMap[s[i]]);
            while(left <= i && (i - left + 1) - maxf > k){
                charMap[s[left]]--;
                left++;
            }
            longest = max(longest, i - left + 1);
        }
        return longest;
    }
};
