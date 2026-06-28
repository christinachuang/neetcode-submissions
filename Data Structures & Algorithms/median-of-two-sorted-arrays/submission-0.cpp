class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int half = (m + n + 1) / 2;
        if(m > n){
            swap(nums1, nums2);
            swap(m, n);
        }
        int left = 0, right = m;
        while(left <= right){
            int b1 = left + (right - left) / 2;
            int b2 = half - b1;
            int l1 = (b1 - 1 >= 0) ? nums1[b1 - 1] : INT_MIN,
                r1 = b1 < m ? nums1[b1] : INT_MAX,
                l2 = (b2 - 1 >= 0) ? nums2[b2 - 1] : INT_MIN, 
                r2 = b2 < n ? nums2[b2] : INT_MAX;
            if(l1 <= r2 && l2 <= r1){
                if((m + n) % 2 == 0)
                    return ((max(l1, l2) + min(r1, r2)) / 2.0);
                else
                    return max(l1, l2);
            }
            else if(l1 > r2)
                right = b1 - 1;
            else
                left = b1 + 1;
        }
        return -1;
    }
};
