class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int> lis;
        lis.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            binarySearch(nums[i], lis);
        }
        return lis.size();
    }
    void binarySearch(int curr, vector<int>& lis){
        int left = 0, right = lis.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(curr <= lis[mid])
                right = mid - 1;
            else
                left = mid + 1;   
        }
        if(left < lis.size())
            lis[left] = curr;
        else
            lis.push_back(curr);
    }
};
