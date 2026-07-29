class Solution {
public:
    int getSum(int a, int b) {
        // each bit = a ^= b
        // carry = (a & b) << 1
        while(b){
            int carry = (a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};
