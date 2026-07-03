class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        int curr = n;
        while(n > 0){
            int tmp = 0;
            while(curr > 0){
                tmp += (curr % 10) * (curr % 10);
                curr /= 10;
            }
            if(tmp == 1)
                return true;
            else if(seen.count(tmp))
                return false;
            seen.insert(tmp);
            curr = tmp;
        }
        return false;
    }
};
