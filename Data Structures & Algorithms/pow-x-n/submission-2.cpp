class Solution {
public:
    double myPow(double x, int n) {
        // if x < 0 || x == 0
        double result = 1.0;
        long long N = n;
        if(x == 0)
            return double(N == 0);
        if(N < 0){
            x = 1 / x;
            N = (-1) * N;
        }
        result = halfPow(x, N);
        return result;
    }
    double halfPow(double x, int n){
        if(n == 0)
            return 1;
        double curr = halfPow(x, n/2);
        if(n % 2 != 0)
            return curr * curr * x;
        else
            return curr * curr;
    }
};
