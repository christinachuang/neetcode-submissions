class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        for(int i = 0; i < n + 1; i++){
            if(i < 2)
                dp[i] = i;
            else
                dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
        /*
        vector<int> output(n + 1, 0);
        for(int i = 0; i < n + 1; i++){
            int curr = i;
            while(curr){
                output[i] += (curr & 1);
                curr >>= 1;
            }
        }
        return output;
        */
    }
};
