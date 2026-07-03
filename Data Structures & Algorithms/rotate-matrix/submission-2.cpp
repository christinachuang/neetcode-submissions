class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       int top = 0, 
           down = matrix.size() - 1,
           left = 0, 
           right = matrix[0].size() - 1; 
        while(top < down && left < right){
            for(int i = left; i < right; i++){
                int offset = i - left;
                int tmp = matrix[top][i];
                matrix[top][i] = matrix[down - offset][left];
                matrix[down - offset][left] = matrix[down][right - offset];
                matrix[down][right - offset] = matrix[i][right];
                matrix[i][right] = tmp;
            }
            top++;
            down--;
            left++;
            right--;
        }
    }
};
