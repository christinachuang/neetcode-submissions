class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3)
            return 0;
        int leftMax = 0, rightMax = 0;
        int left = 0, right = height.size() - 1;
        int total_sum = 0;
        while(left <= right){
            if(leftMax <= rightMax){
                total_sum += max(0, leftMax - height[left]);
                leftMax = max(leftMax, height[left]);
                left++; 
            }
            else{
                total_sum += max(0, rightMax - height[right]);
                rightMax = max(rightMax, height[right]);
                right--;
            }
        }
        return total_sum;
    }
};
