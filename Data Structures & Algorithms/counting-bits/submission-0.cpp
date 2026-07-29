class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output(n + 1, 0);
        for(int i = 0; i < n + 1; i++){
            int curr = i;
            while(curr){
                output[i] += (curr & 1);
                curr >>= 1;
            }
        }
        return output;
    }
};
