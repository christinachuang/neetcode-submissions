class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3)
            return 0;
        vector<int> prefix(height.size(), 0), suffix(height.size(), 0);
        int total_sum = 0;
        for(int i = 1; i < height.size(); i++)
            prefix[i] = max(prefix[i - 1], height[i - 1]);
        for(int i = height.size() - 2; i >= 0; i--)
            suffix[i] = max(suffix[i + 1], height[i + 1]);
        for(int i = 0; i < height.size(); i++){
            total_sum += max(0, min(prefix[i], suffix[i]) - height[i]);
        }
        return total_sum;
    }
};
