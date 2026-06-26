class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = 0;
        int left = 0, right = heights.size() - 1;
        while(left < right){
            max_area = max(max_area, min(heights[left], heights[right]) * (right - left));
            if(heights[left] <= heights[right])
                left++;
            else
                right--;
        }
        return max_area;
    }
};
