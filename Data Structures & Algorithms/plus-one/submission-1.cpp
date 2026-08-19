#include <cmath>
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0, size = digits.size();
        for(int i = size - 1; i >= 0; i--){
            if(i == size - 1)
                digits[i]++;
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        if(carry)
            digits.emplace(digits.begin(), carry);
        return digits;
    }
};
