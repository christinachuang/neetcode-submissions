class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.size() < 2)
            return {};
        int left = 0, right = numbers.size() - 1;
        while(left < right){
            int curr_sum = numbers[left] + numbers[right];
            if(curr_sum == target)
                return {left + 1, right + 1};
            else if(curr_sum < target)
                left++;
            else
                right--;
        }
        return {0, 0};
    }
};
