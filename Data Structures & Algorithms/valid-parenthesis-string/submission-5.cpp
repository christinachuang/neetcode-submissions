class Solution {
public:
    bool checkValidString(string s) {
        int least_diff = 0, top_diff = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                least_diff++;
                top_diff++;
            }
            else if(s[i] == ')'){
                least_diff--;
                top_diff--;
            }
            else{
                top_diff++;
                least_diff--;
            }
            if(top_diff < 0)
                return false;
            least_diff = max(least_diff, 0);
        }
        return (least_diff <= 0 && top_diff >= 0);
    }
};
