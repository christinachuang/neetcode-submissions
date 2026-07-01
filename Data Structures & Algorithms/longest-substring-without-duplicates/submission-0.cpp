class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        unordered_set<char> charSet;
        int longest = 0;
        for(int i = 0; i < s.size(); i++){
            if(charSet.count(s[i])){
                // remove old chars
                while(left <= i && s[left] != s[i]){
                    charSet.erase(s[left]);
                    left++;
                }
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[i]);
            longest = max(longest, i - left + 1);
        }
        return longest;
    }
};
