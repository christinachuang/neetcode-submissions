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
    bool isValidBST(TreeNode* root) {
        // record: 1. lower for left subtrees;
        //         2. upper for right subtrees;
        // for each node: update curr val with root -> check left -> check right -> recursive
        if(!root) return true;
        return DFS(root, INT_MIN, INT_MAX);
    }
    bool DFS(TreeNode* root, int lower, int upper){
        if(!root)
            return true;
        if(root->val <= lower || root->val >= upper)
            return false;
        return DFS(root->left, lower, root->val) &&
                DFS(root->right, root->val, upper);
    }
};
