class Solution {
public:
    int findMin(vector<int> &nums) {
        // 右邊是順的 -> min在左邊
        // 右邊不順 -> min在右邊
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = left + (right - left)/2;
            if(nums[mid] <= nums[right])
                right = mid;
            else
                left = mid + 1;
        }
        return nums[left];
    }
};
