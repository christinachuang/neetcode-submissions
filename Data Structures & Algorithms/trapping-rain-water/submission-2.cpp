class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2)
            return 0;
        int leftMax = height[0], rightMax = height[height.size() - 1];
        int left = 1, right = height.size() - 2;
        int total = 0;
        while(left <= right){
            if(leftMax <= rightMax){
                total += max(0, (leftMax - height[left]));
                leftMax = max(leftMax, height[left]);
                left++;
            }
            else{
                total += max(0, (rightMax - height[right]));
                rightMax = max(rightMax, height[right]);
                right--;
            }
        }
        return total;
    }
};
