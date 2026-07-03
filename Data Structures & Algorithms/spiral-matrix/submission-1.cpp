class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> output;
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return output;
        int left = 0, right = matrix[0].size() - 1,
            top = 0, down = matrix.size() - 1;
        while(left <= right && top <= down){
            // top row
            for(int i = left; i <= right; i++)
                output.push_back(matrix[top][i]);
            top++;
            // right column
            for(int i = top; i <= down; i++)
                output.push_back(matrix[i][right]);
            right--;
            if(top <= down){
                // down row
                for(int i = right; i >= left; i--)
                    output.push_back(matrix[down][i]);
                down--;
            }
            if(left <= right){
                //left column
                for(int i = down; i >= top; i--)
                    output.push_back(matrix[i][left]);
                left++;
            }
        }
        return output;
    }
};
