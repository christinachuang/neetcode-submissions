/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // each node: 
        //      abs(left subtree depth + right subtree depth)
        //      return self depth
        int result = 0;
        CalculateTreeDistance(root, result);
        return result;
    }
    int CalculateTreeDistance(TreeNode* root, int& result){
        if(!root)
            return 0;
        int left = CalculateTreeDistance(root->left, result);
        int right = CalculateTreeDistance(root->right, result);
        result = max(result, left + right);
        return max(left, right) + 1;
    }
};
