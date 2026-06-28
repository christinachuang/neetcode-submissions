class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int r = matrix.size(), c = matrix[0].size();
        int left = 0, right = r * c - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int r_mid = mid / c, c_mid = mid % c;
            if(matrix[r_mid][c_mid] == target)
                return true;
            else if(matrix[r_mid][c_mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};
