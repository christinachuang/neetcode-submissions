class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while(left <= right){
            int mid = left + (right - left) / 2;
            // calculate the h with mid
            int curr_h = 0;
            for(auto& p : piles)
                curr_h += (p + mid - 1) / mid;
            if(curr_h > h)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};
